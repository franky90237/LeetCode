//2022-05-10
//dp recursive
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        bool dp[n];
        for(int i=0; i<n; ++i) dp[i]=true;
        return solve(nums,dp,0);
    }
    
    bool solve(vector<int>& nums, bool dp[], int now)
    {
        int n=nums.size();
        if(now>=n-1) return true;
        if(!dp[now]) return false;
        
        for(int i=1; i<=nums[now]; ++i)
        {
            bool isLast=solve(nums,dp,now+i);
            if(isLast) return true;
        }
        
        dp[now]=false;
        return false;
    }
};

//2022-05-10
//dp iterative
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1) return true;
        
        bool dp[n];
        for(int i=0; i<n; ++i) dp[i]=false;
        
        for(int i=n-2; i>=0; --i)
        {
            for(int step=nums[i]; step>=1; --step)
            {
                if(i+step>=n-1 || dp[i+step]) 
                {
                    dp[i]=true;
                    break;
                }
                
                dp[i]=false;
            }
        }
        
        return dp[0];
    }
};

//2022-05-10
//greedy
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        
        int max_index=0;
        for(int i=0; i<n-1; ++i)
        {
            max_index=max(max_index,i+nums[i]);
            if(i==max_index) return false;
        }
        
        return true;
    }
};

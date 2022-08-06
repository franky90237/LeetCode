//2022-06-08
//TLE
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        return solve(0,nums,target);
    }
    
    int solve(int now, vector<int>& nums, int target)
    {
        int n=nums.size();
        if(now>=n || target<0) return 0;
        if(target==0) return 1;
        
        int sum=0;
        for(int i=now; i<n; ++i)
        {
            sum+=solve(0,nums,target-nums[i]);
        }
        
        return sum;
    }
};

//2022-06-08
//dp recursive
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int dp[target+1];
        for(int i=0; i<=target; ++i) dp[i]=-1;
        
        return solve(0,dp,nums,target);
    }
    
    int solve(int now, int dp[], vector<int>& nums, int target)
    {
        int n=nums.size();
        if(now>=n || target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        if(target==0) return 1;
        
        int sum=0;
        for(int i=now; i<n; ++i)
        {
            sum+=solve(0,dp,nums,target-nums[i]);
        }
        
        dp[target]=sum;
        return sum;
    }
};

//2022-06-08
//dp iterative
//time  : O(n*m), m is the target size
//space : O(m)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int dp[target+1];
        for(int i=1; i<=target; ++i) dp[i]=0;
        dp[0]=1;
        
        for(int i=1; i<=target; ++i)
        {
            //cout<<i<<endl;
            for(auto& num:nums)
            {
                //if(i==320) cout<<i<<":"<<num<<endl;
                if((i-num)>=0) 
                {
                    if(dp[i]<=INT_MAX-dp[i-num]) dp[i]=dp[i]+dp[i-num];
                }
            }
            //cout<<i<<":"<<dp[i]<<endl;
        }
        
        return dp[target];
    }
};

//2022-08-06
//time  : O(2^n)
//space : O(n)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        /*
        1,2,3        
        */
        
        int cnt=0;
        int sum=0;
        sort(nums.begin(),nums.end());
        dfs(nums,target,sum,cnt);
        
        return cnt;
    }
    
    void dfs(vector<int>& nums, int target, int sum, int& cnt)
    {
        if(sum==target)
        {
            ++cnt;
            return;
        }
        
        if(sum>target) return;
        
        for(int i=0; i<nums.size(); ++i)
        {
            sum+=nums[i];
            
            dfs(nums,target,sum,cnt);
            if(sum>=target) return;
            
            sum-=nums[i];
        }
    }
};

//2022-08-06
//dp recursive
//time  : O(target)
//space : O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {        
        int dp[target+1];
        for(int i=0; i<=target; ++i) dp[i]=-1;
        
        sort(nums.begin(),nums.end(),greater<int>());
        dfs(nums,target,dp);
        
        return dp[target];
    }
    
    int dfs(vector<int>& nums, int target, int dp[])
    {
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        
        int cnt=0;
        for(int i=0; i<nums.size(); ++i)
        {
            cnt+=dfs(nums,target-nums[i],dp);
        }
        
        dp[target]=cnt;
        return dp[target];
    }
};

//2022-08-06
//dp iterative
//time  : O(n*target)
//space : O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {        
        unsigned int dp[target+1];
        for(int i=0; i<=target; ++i) dp[i]=0;
        dp[0]=1;
        
        for(int cur_target=1; cur_target<=target; ++cur_target)
        {            
            for(auto& num:nums)
            {
                int pre_target=cur_target-num;
                if(pre_target>=0) dp[cur_target]+=dp[pre_target];
            }
        }
        
        return dp[target];
    }     
};

//2022-06-08
//TLE
class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size()==1) return nums[0];
        
        return solve(0,true,nums);
    }
    
    int solve(int now, bool first, vector<int>& nums)
    {
        int n=nums.size();
        if(now>=n) return 0;
        
        int maxMoney=0;
        for(int i=now; i<n; ++i)
        {
            if(now==0 && i!=now) first=false;
            if(i==n-1 && first) continue;
            maxMoney=max(maxMoney,nums[i]+solve(i+2,first,nums));
            //cout<<i<<":"<<money<<endl;
        }
        
        return maxMoney;
    }
};

//2022-06-08
//dp recursive
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1) return nums[0];
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        /*for(int i=0; i<n; ++i)
        {
            dp[i][true]=-1;
            dp[i][false]=-1;
        }*/
        //solve(0,true,dp,nums);
        //for(int i=0; i<n; ++i) printf("%d : %d,%d\n",i,dp[i][1],dp[i][0]);
        return solve(0,true,dp,nums);
    }
    
    int solve(int now, bool first, vector<vector<int>>& dp, vector<int>& nums)
    {
        int n=nums.size();
        if(now>=n) return 0;
        if(dp[now][first]!=-1) return dp[now][first];
        
        bool tmp=first;
        int maxMoney=0;
        for(int i=now; i<n; ++i)
        {
            if(now==0 && i!=now) first=false;
            if(i==n-1 && first) continue;
            
            int res=solve(i+2,first,dp,nums);
            if(maxMoney<=nums[i]+res)
            {
                maxMoney=nums[i]+res;
                tmp=first;
            }
            
            //maxMoney=max(maxMoney,nums[i]+solve(i+2,first,dp,nums));
            //cout<<i<<":"<<money<<endl;
        }
        
        dp[now][tmp]=maxMoney;
        return maxMoney;
    }
};

//2022-06-08
//dp iterative
//time  : O(n)
//space : O(n)
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        
        return max(rob(nums,0,n-2),rob(nums,1,n-1));
    }
    
    int rob(vector<int>& nums, int l, int r)
    {
        int dp[r+1];
        dp[l]=nums[l];
        dp[l+1]=max(nums[l+1],nums[l]);
            
        for(int i=l+2; i<=r; ++i)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        
        return dp[r];
    }
};

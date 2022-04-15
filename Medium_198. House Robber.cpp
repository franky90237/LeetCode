//2022-04-15
//TLE
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        return solve(nums,0);
    }
    
    int solve(vector<int>& nums, int now)
    {     
        if(now>=nums.size()) return 0;
               
        return max(nums[now]+solve(nums,now+2), solve(nums,now+1));
    }
};

//2022-04-15
//TLE
//dp recursive
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=0;
        
        return solve(dp,nums,0);
    }
    
    int solve(int dp[], vector<int>& nums, int now)
    {        
        if(now>=nums.size()) return 0;
        if(dp[now]!=0) return dp[now];
        
        dp[now]=max(nums[now]+solve(dp,nums,now+2), solve(dp,nums,now+1));
        
        return dp[now];
    }
};

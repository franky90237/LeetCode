//2022-10-29
//time  : O(n*m), m is average num[i]
//spcae : O(1)
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n=nums.size();       
        vector<int> dp(n, -1);
        
        return solve(nums, 0, dp);
    }
    
    int solve(vector<int>& nums, int cur, vector<int>& dp)
    {
        int n=nums.size();
        if(cur >= n-1) return 0;
        if(cur+nums[cur] >= n-1) return 1;
        if(dp[cur] != -1) return dp[cur];
        
        int minCnt=99999;
        for(int i=1; i<=nums[cur]; ++i)
        {
            int cnt = 1 + solve(nums, cur+i, dp);
            minCnt=min(minCnt, cnt);
        }
        
        dp[cur]=minCnt;
        return minCnt;
    }
};

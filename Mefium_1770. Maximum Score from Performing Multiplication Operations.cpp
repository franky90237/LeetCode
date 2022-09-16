//2022-09-16
//MLE
//time  : O(m*m*n)
//space : O(m*m*n)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        
        /*
        5,6,100,1
        
        [1,100]
        
        5*1+6*100
        
        1*1+100*100
        
        
        
        (l,r,k)
        
        dp[l][r][k] = max( dp[l-1][r][k-1] + nums[l-1]*mul[k-1], dp[l][r+1][k-1] + nums[r+1]*mul[k-1])
        */
        int m=nums.size();
        int n=multipliers.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>(n, -1) ) );
        
        return solve(nums, multipliers, 0, m-1, 0, dp);
    }
    
    int solve(vector<int>& nums, vector<int>& multipliers, int l, int r, int k, vector<vector<vector<int>>>& dp)
    {
        if(k >= multipliers.size()) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        
        int pick_left  = solve(nums, multipliers, l+1, r, k+1, dp) + nums[l]*multipliers[k];
        int pick_right = solve(nums, multipliers, l, r-1, k+1, dp) + nums[r]*multipliers[k];
        
        dp[l][r][k]=max(pick_left,pick_right);
        return dp[l][r][k];
    }
};

//2022-10-09
//time  : O(m*n*k)
//space : O(m*n*k)
class Solution 
{
private:
    int mod = 1e9+7;
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1) ) );
        
        return solve(grid, k, 0, 0, 0, dp);
    }
    
    int solve(vector<vector<int>>& grid, int k, int r, int c, int sum, vector<vector<vector<int>>>& dp)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(r >= m || c >= n) return 0;
        
        sum = (sum + grid[r][c]) % k;
        if(dp[r][c][sum] != -1) return dp[r][c][sum];
        if(r==m-1 && c==n-1)
        {
            return sum==0;
        }
        
        int right=solve(grid, k, r, c+1, sum, dp);
        int down =solve(grid, k, r+1, c, sum, dp);
        
        dp[r][c][sum]=(right+down)%mod;
        return dp[r][c][sum];
    }
};

//2024-03-02
//time  : O(n*n*n)
//sapce : O(n*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        dp.resize(n, vector<int>(n, -1));
        
        return f(values, 0, n - 1);
    }
    
    int f(vector<int>& values, int i, int j)
    {
        if(i == j - 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
                
        int res = INT_MAX;
        for(int k = i + 1; k < j; ++k)
        {
            res = min(res, f(values, i, k) + f(values, k, j) + values[i] * values[k] * values[j]);
        }
        
        return dp[i][j] = res;
    }
};

//2024-03-02
//time  : O(n*n*n)
//sapce : O(n*n)
class Solution {        
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n - 3; i >= 0; --i)
        {
            for(int j = i + 2; j < n; ++j)
            {
                int res = INT_MAX;
                for(int k = i + 1; k < j; ++k)
                {
                    res = min(res, dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
                
                dp[i][j] = res;
            }
        }
        
        return dp[0][n-1];
    }     
};

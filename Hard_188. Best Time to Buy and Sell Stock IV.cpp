//2024-01-11
//time  : O(n*k)
//space : O(n*k)
class Solution 
{
private:
    vector<vector<vector<int>>> dp;
    
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        dp.resize(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, false, k);
    }
    
    int solve(vector<int>& prices, int i, bool isHold, int k)
    {
        if(i >= prices.size() || k == 0) return 0;
        if(dp[i][isHold][k] != -1) return dp[i][isHold][k];
        
        if(isHold)
        {
            return dp[i][isHold][k] = max(solve(prices, i+1, true, k), solve(prices, i+1, false, k-1) + prices[i]);
        }
        else
        {
            return dp[i][isHold][k] = max(solve(prices, i+1, false, k), solve(prices, i+1, true, k) - prices[i]);
        }
    }
};

//2023-06-22
//time  : O(n*n)
//space : O(n*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        int n=cost.size();
        dp.resize(n, vector<int>(n+1, -1));
        return solve(cost, time, 0, n);
    }
    
    int solve(vector<int>& cost, vector<int>& time, int cur, int restWalls)
    {
        int n=cost.size();
        if(restWalls <= 0) return 0;
        if(cur >= n) return INT_MAX;
        if(dp[cur][restWalls] != -1) return dp[cur][restWalls];
        
        int paidPainterNotPaint = solve(cost, time , cur+1, restWalls);
        int paidPainterPaint = solve(cost, time, cur+1, restWalls-1-time[cur]);
        if(paidPainterPaint != INT_MAX) paidPainterPaint += cost[cur];
        
        dp[cur][restWalls] = min(paidPainterNotPaint, paidPainterPaint);
        return dp[cur][restWalls];
    }
};

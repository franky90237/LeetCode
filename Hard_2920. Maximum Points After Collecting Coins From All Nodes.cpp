//2023-11-07
//time  : O(n*log(100000))
//space : O(n*log(100000))
class Solution 
{
private:
    vector<unordered_set<int>> graph;
    vector<vector<int>> dp;
    vector<int> powerOf2;
    int maxPower=17;
    
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k)
    {
        int n=coins.size();
        graph.resize(n);
        for(auto edge: edges)
        {
            int a=edge[0];
            int b=edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        
        powerOf2.resize(maxPower+1);
        powerOf2[0]=1;
        for(int i=1; i<=maxPower; ++i)
        {
            powerOf2[i] = powerOf2[i-1]*2;
        }
        
        dp.resize(n, vector<int>(maxPower+1, -1));
        return solve(coins, k, -1, 0, 0);
    }
    
    int solve(vector<int>& coins, int k, int parent, int cur, int halfCnt)
    {
        int n=coins.size();
        if(dp[cur][halfCnt] != -1) return dp[cur][halfCnt];
        
        int base=powerOf2[halfCnt];
        int rest=coins[cur]/base;
        int first=rest-k;
        int second=rest/2;
        for(auto& next: graph[cur])
        {
            if(next == parent) continue;
            first += solve(coins, k, cur, next, halfCnt);                        
            second += solve(coins, k, cur, next, min(halfCnt+1, maxPower));
        }
        
        dp[cur][halfCnt] = max(first, second);
        return dp[cur][halfCnt];
    }
};

//2024-04-02
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<int>> g;
    long long res=0;
    
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) 
    {
        g.resize(n);
        for(auto& edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        dfs(price, -1, 0);
        return res;
    }
    
    vector<long long> dfs(vector<int>& price, int parent, int cur)
    {
        long long contain = price[cur];
        long long notContain = 0;
        
        for(int next : g[cur])
        {
            if(next == parent) continue;
            
            auto tmp = dfs(price, cur, next);
            long long subtreeContain = tmp[0];
            long long subtreeNotContain = tmp[1];
            
            res = max(res, contain + subtreeNotContain);
            res = max(res, notContain + subtreeContain);
            
            contain = max(contain, subtreeContain + price[cur]);
            notContain = max(notContain, subtreeNotContain + price[cur]);
        }
        
        return {contain, notContain};
    }
};

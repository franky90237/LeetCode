//2024-04-12
//time  : O(n)
//sapce : O(n)
class Solution 
{
private:
    vector<vector<int>> g;
    
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        g.resize(n + 1);
        for (auto& e : edges)
        {
            int a = e[0];
            int b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        long long res = f(-1, 1, t, target);
        return (res == 0) ? res : 1.0/res;
    }
    
    long long f(int pre, int cur, int t, int target)
    {
        if(t < 0) return 0LL;
        if (t == 0) return (cur == target);
        
        bool isEnd = true;
        
        long long res = 0;
        long long cnt = 0;
        for (int next : g[cur])
        {
            if (next == pre) continue;
            isEnd = false;
            ++cnt;
            res = max(res, f(cur, next, t-1, target));
        }
        
        if(isEnd && cur == target) return 1LL;
        else return res * cnt;
    }
};

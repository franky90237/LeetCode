//2024-02-04
//time  : O(n)
//spcae : O(n)
class Solution 
{
private:
    vector<vector<int>> g;
    vector<int> degree;
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if(n == 1) return {0};
        
        buildGraph(n, edges);
                
        queue<int> q;        
        for(int i=0; i<n; ++i)
        {
            if(degree[i] == 1) 
            {
                //cout<<i<<endl;
                q.push(i);               
            }
        }
        
        vector<bool> vis(n, false);
        vector<int> res;
        while(!q.empty())
        {
            res.clear();
            int size=q.size();
            for(int cnt=0; cnt<size; ++cnt)
            {
                int cur=q.front();
                q.pop();
                vis[cur]=true;
                res.push_back(cur);
                
                for(int next : g[cur])
                {
                    if(vis[next]) continue;                    
                    
                    --degree[next];
                    if(degree[next] == 1) q.push(next);
                }
            }
        }
        
        return res;
    }
    
    void buildGraph(int n, vector<vector<int>>& edges) 
    {
        g.resize(n);
        degree.resize(n, 0);
        for(auto& edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }        
    }
};

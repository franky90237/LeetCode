//2024-01-26
//time  : O(n+e)
//space : O(n+e)
class Solution 
{
private:
    vector<unordered_set<int>> g;
    unordered_set<int> cycleNode;    
    vector<bool> done;
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        g.resize(n+1);
        buildGraph(edges);
        
        done.resize(n+1, false);
        for(int i=1; i<=n; ++i)
        {
            vector<bool> vis(n+1, false);
            vector<int> path;
            bool hasCycle = dfs(vis, path, i, -1);
            if(hasCycle)
            {
                int begin=0;
                while(path[begin] != path.back()) ++begin;
                
                for(; begin < path.size() - 1; ++begin)
                {
                    //cout<<path[begin]<<endl;
                    cycleNode.insert(path[begin]);
                }
                
                break;
            }
        }
                
        int res=0;
        for(int i=n-1; i>=0; --i)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            if(cycleNode.count(a) && cycleNode.count(b))
            {
                res=i;
                break;
            }
        }        
        
        return edges[res];
    }
    
    bool dfs(vector<bool>& vis, vector<int>& path, int cur, int parent)
    {
        //cout<<cur<<endl;
        path.push_back(cur);
        
        if(vis[cur]) return true;
        if(done[cur]) return false;
        
        vis[cur]=true;
        done[cur]=true;
        
        for(int next : g[cur])
        {            
            if(next == parent) continue;
            if(dfs(vis, path, next, cur)) return true;
        }
        
        path.pop_back();
        vis[cur]=false;
        return false;
    }
    
    void buildGraph(vector<vector<int>>& edges)        
    {
        for(auto& e : edges)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
    }
};

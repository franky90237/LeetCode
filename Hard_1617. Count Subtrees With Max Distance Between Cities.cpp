//2024-03-31
//time  : O((2^n) * n)
//space : O(2^n + n*n)
class Solution 
{
private:
    vector<vector<int>> g;
    unordered_set<int> subset;
    vector<int> res;
    
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) 
    {        
        buildGraph(n, edges);
        
        res.resize(n-1, 0);
        goThrough(1, n);
                
        return res;
    }
    
    void buildGraph(int n, vector<vector<int>>& edges) 
    {
        g.resize(n+1);
        for(auto& edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    
    void goThrough(int i, int n)
    {        
        if(i > n)
        {
            if(subset.size() < 2) return;
            
            int begin=*subset.begin();
                        
            vector<bool> vis(n+1, false);
            int visitedCities=dfs(begin, vis);
            
            //for(auto& it : subset) cout<<it<<" "; cout<<endl;
            //cout<<visitedCities<<endl<<endl;
            
            if(visitedCities == subset.size())
            {
                int diameter=0;
                fill(vis.begin(), vis.end(), false);
                getDiameter(begin, vis, diameter);
                ++res[diameter-2];
                
                //for(auto& it : subset) cout<<it<<" "; cout<<endl;
                //cout<<diameter<<endl<<endl;
            }
            
            return;
        }          
        
        goThrough(i+1, n);
        
        subset.insert(i);
        goThrough(i+1, n);
        subset.erase(i);
    }
    
    int dfs(int cur, vector<bool>& vis)
    {
        vis[cur]=true;        
        
        int cnt=1;
        for(int next : g[cur])
        {
            if(vis[next] || subset.count(next) == 0) continue;
            cnt += dfs(next, vis);
        }
        
        return cnt;
    }
    
    int getDiameter(int cur, vector<bool>& vis, int& diameter)
    {
        vis[cur]=true;
        
        int max1=0;
        int max2=0;
        for(int next : g[cur])
        {
            if(vis[next] || subset.count(next) == 0) continue;
            
            int d=getDiameter(next, vis, diameter);
            if(d >= max1)
            {
                max2=max1;
                max1=d;
            }
            else if(d > max2)
            {
                max2=d;
            }
        }
        
        diameter=max(diameter, max1+max2+1);
        return max(max1, max2) + 1;
    }
};

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

//2024-01-26
//time  : O(n*n)
//space : O(n)
class Solution 
{
private:
    vector<unordered_set<int>> g;
    vector<bool> vis;
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        g.resize(n+1);    
        vis.resize(n+1, false);
        
        for(auto& edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            if(canReach(a, b))
            {
                return edge;
            }
            
            g[a].insert(b);
            g[b].insert(a);
        }
        
        return {};
    }
    
    bool canReach(int begin, int end)
    {
        if(vis[begin]) return false;
        if(begin == end) return true;
        
        vis[begin]=true;
        
        for(int next : g[begin])
        {
            if(canReach(next, end)) 
            {
                vis[begin]=false;
                return true;        
            }
        }
        
        vis[begin]=false;
        return false;
    }
};

//2024-01-26
//time  : O(n*n)
//space : O(n)
class Solution 
{
private:
    vector<unordered_set<int>> g;    
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        g.resize(n+1);        
        
        for(auto& edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            if(canReach(-1, a, b))
            {
                return edge;
            }
            
            g[a].insert(b);
            g[b].insert(a);
        }
        
        return {};
    }
    
    bool canReach(int pre, int begin, int end)
    {        
        if(begin == end) return true;                
        
        for(int next : g[begin])
        {            
            if(next != pre && canReach(begin, next, end)) return true;
        }
        
        return false;
    }
};

//2024-01-26
//time  : O(n)
//space : O(n)
class UF
{  
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UF() = default;
    
    UF(int n)
    {
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i]=i;
        
        size.resize(n, 1);
    }
    
    bool combine(int a, int b)
    {
        int rootA=find(a);
        int rootB=find(b);
        if(rootA == rootB) return true;
        
        if(size[rootA] < size[rootB])
        {
            parent[rootA]=rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            parent[rootB]=rootA;
            size[rootA] += size[rootB];            
        }
        
        return false;
    }
    
    int find(int a)
    {
        if(parent[a] == a) return a;
        return parent[a]=find(parent[a]);
    }
};

class Solution 
{
private:
    vector<unordered_set<int>> g;    
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        UF uf(n+1);
        
        for(auto& edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            if(uf.combine(a, b)) return edge;
        }
        
        return {};
    }    
};

//2024-02-18
//time  : O(e)
//space : O(v + e + v)
class UF
{  
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UF(int n)
    {
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        
        size.resize(n, 1);
    }
    
    bool combine(int a, int b)
    {
        int parentA = find(a);
        int parentB = find(b);
        if(parentA == parentB) return false;
        
        if(size[parentA] < size[parentB])
        {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
        else
        {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];            
        }
        
        return true;
    }
    
    int find(int a)
    {
        if(parent[a] == a) return a;
        
        parent[a] = find(parent[a]);
        return parent[a];
    }
    
};

class Solution 
{
private:
    vector<vector<int>> g;
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        buildGraph(edges);
        
        UF uf(edges.size()+1);
        
        for(auto edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            
            if(!uf.combine(a, b)) return {a, b};
        }
        
        return {};
    }
    
    void buildGraph(vector<vector<int>>& edges)
    {
        int n=edges.size();
        g.resize(n+1);
        for(auto edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
};

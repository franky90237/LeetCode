//203-05-14
class Solution 
{
private:
    vector<set<int>> graph;
    vector<bool> used;
    vector<bool> visited;
    vector<vector<int>> groups;    
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        createGraph(n, edges);
        //cout<<"graph done"<<endl;
        
        used.resize(n, false);
        visited.resize(n, false);        
        for(int i=0; i<n; ++i)
        {
            if(used[i]) continue;
            groups.push_back({});
            dfs(i);
        }
        //cout<<"dfs done"<<endl;
        
        /*
        for(auto& group: groups)
        {
            for(int node: group) cout<<node<<" ";
            cout<<endl;
        }
        */
        
        int ans=0;
        for(auto& group: groups)
        {
            int cnt=group.size();
            bool find=true;
            for(int node: group)
            {
                if((int)graph[node].size() != cnt-1) 
                {
                    find=false;
                    break;
                }
            }
            
            if(find) ++ans;
        }
        
        return ans;
    }
    
    void createGraph(int n, vector<vector<int>>& edges)
    {
        graph.resize(n);
        
        for(auto& edge: edges)
        {
            int s=edge[0];
            int e=edge[1];
            graph[s].insert(e);
            graph[e].insert(s);
        }
    }
    
    void dfs(int cur)
    {
        if(visited[cur] || used[cur]) return;
        visited[cur]=true;
        used[cur]=true;
        
        groups.back().push_back(cur);
        
        for(auto nei: graph[cur])
        {
            dfs(nei);
        }
        
        visited[cur]=false;
    }
};

//2023-05-27
//time  : O(n+e)
//space : O(n+e)
class unionFind
{
private:
    
public:
    vector<int> parent;
    vector<int> size;
    unionFind(int n)
    {
        parent.resize(n);
        for(int i=0; i<n; ++i)
        {
            parent[i]=i;
        }
        
        size.resize(n, 1);
    }
    
    void combine(int u, int v)
    {
        int rootU=find(u);
        int rootV=find(v);
        
        if(size[rootU] < size[rootV])
        {
            parent[rootU]=rootV;
        }
        else
        {
            parent[rootV]=rootU;
        }
    }
    
    int find(int u)
    {
        if(u == parent[u]) return u;
        
        return parent[u]=find(parent[u]);
        
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<unordered_set<int>> graph(n);
        unionFind uf(n);
        for(auto& edge: edges)
        {
            int begin=edge[0];
            int end=edge[1];
            graph[begin].insert(end);
            graph[end].insert(begin);
            uf.combine(begin, end);
        }
        
        unordered_map<int, vector<int>> groups;
        for(int i=0; i<n; ++i)
        {        
            int group=uf.find(i);
            groups[group].push_back(i);            
        }
        
        /*
        for(auto& group: groups)
        {
            for(auto node: group.second) cout<<node<<" ";
            cout<<endl;
        }
        */
        
        int ans=0;
        for(auto& group: groups)
        {
            bool find=true;
            int size=group.second.size();
            for(auto node: group.second)
            {
                if(graph[node].size() != size -1)
                {
                    find=false;
                    break;
                }
            }
            
            if(find)
            {
                ++ans;
            }
        }
        
        return ans;
    }
};

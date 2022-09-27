//2022-09-26
//TLE
//time  : O(n + n*n)
//space : O(n)
class Solution 
{
private:
    class node
    {
    public:
        int index;
        int val;
        vector<int> neighbor;             
    };
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {        
        int n=vals.size();
        if(n==1) return 1;
        
        int max_val=0;
        vector<int> val_cnt(1e5+1, 0);
        for(auto val : vals) 
        {
            max_val=max(max_val, val);
            ++val_cnt[val];
        }
        
        vector<node> adj(n);        
        for(auto& edge : edges)
        {
            adj[edge[0]].index=edge[0];
            adj[edge[0]].val=vals[edge[0]];
            adj[edge[0]].neighbor.push_back(edge[1]);
            
            adj[edge[1]].index=edge[1];
            adj[edge[1]].val=vals[edge[1]];
            adj[edge[1]].neighbor.push_back(edge[0]);
        }
        
        int ans=0;
        vector<unordered_set<int>> finished(max_val+1);
        vector<bool> visited(n, false);
        for(int i=0; i<n; ++i)
        {            
            int val=vals[i];            
            if(val_cnt[val] <= 1 || finished[val].count(i) > 0)
            {
                ++ans;
                continue;
            }                 
            
            //cout<<"*"<<val<<":"<<endl;
            int cnt=0;
            dfs(adj, adj[i], val, cnt, visited, finished, val_cnt);
            if(cnt==1) ans+=cnt;
            else ans= ans + (cnt*(cnt-1))/2 + 1;
            
            //cout<<i<<" : "<<val<<" "<<cnt<<endl;            
            //cout<<endl;
        }
        
        return ans;
    }
    
    void dfs(vector<node>& adj, node& vertex, int val, int& cnt, vector<bool>& visited, vector<unordered_set<int>>& finished, vector<int>& val_cnt)
    {
        if(visited[vertex.index] || vertex.val > val) return;
        visited[vertex.index]=true;
        
        if(vertex.val == val ) 
        {
            finished[val].insert(vertex.index);
            --val_cnt[val];
            ++cnt;
        }
        
        if(val_cnt[val]==0) 
        {
            //cout<<val<<" "<<cnt<<endl;
            visited[vertex.index]=false;
            return;
        }
        //cout<<vertex.val<<" ";
        
        for(auto& neighbor : vertex.neighbor)
        {
            dfs(adj, adj[neighbor], val, cnt, visited, finished, val_cnt);
            if(val_cnt[val]==0)
            {
                visited[vertex.index]=false;
                return;                
            }
        }
        
        visited[vertex.index]=false;
    }
};

//2022-09-27
//time  : O(n+e)
//space : O(n+e)
class union_find
{
private:
    vector<int> parent;
    vector<int> size;
    
public:
    union_find(int n)
    {
        for(int i=0; i<n; ++i)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    void combine(int a, int b)
    {
        int rootA=find(a);
        int rootB=find(b);
        if(rootA==rootB) return;
        
        if(size[rootA] > size[rootB])
        {
            parent[rootB]=rootA;
            size[rootA]+=size[rootB];
            //return rootA;
        }        
        else
        {
            parent[rootA]=rootB;
            size[rootB]+=size[rootA];
            //return rootB;
        }                
    }
    
    int find(int a)
    {
        if(parent[a] == a) return a;
        
        parent[a]=find(parent[a]);
        return parent[a];
    }
};

class Solution 
{
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {        
        int n=vals.size();
        if(n==1) return 1;
        
        int smallest=INT_MAX;
        int biggest=INT_MIN;
        vector<vector<int>> table(1e5+1, vector<int>());
        for(int i=0; i<n; ++i)
        {
            smallest=min(smallest, vals[i]);
            biggest=max(biggest, vals[i]);
            table[vals[i]].push_back(i);
        }
        
        vector<vector<int>> adj(n);
        for(auto& edge : edges)
        {
            int nodeA=edge[0];
            int nodeB=edge[1];
            
            if(vals[nodeA] >= vals[nodeB]) adj[nodeA].push_back(nodeB);
            if(vals[nodeB] >= vals[nodeA]) adj[nodeB].push_back(nodeA);
        }
        
        union_find uf(n);
        int ans=0;
        for(int i=smallest; i<=biggest; ++i)
        {
            if(table[i].empty()) continue;
                        
            for(auto& index : table[i])
            {
                for(auto& neighbor : adj[index])
                {
                    uf.combine(index, neighbor);                    
                }                
            }
            
            unordered_map<int, int> parent;
            for(auto& index : table[i])
            {
                ++parent[uf.find(index)];
            }
            
            for(auto& it : parent)
            {            
                ans = ans + (it.second * (it.second-1))/2;
            }
            ans = ans + table[i].size();
            //cout<<i<<" "<<ans<<endl;
        }
        
        return ans;
    }
};

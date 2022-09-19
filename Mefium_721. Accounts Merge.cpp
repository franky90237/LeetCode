//2022-09-19
//time  : O(v+e)
//space : O(v+e)
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        unordered_map<string, vector<string>> adj;
        for(auto& account : accounts)
        {
            string& first_email=account[1];
            for(int i=2; i<account.size(); ++i)
            {
                adj[first_email].push_back(account[i]);
                adj[account[i]].push_back(first_email);
            }
        }
        
        vector<vector<string>> ans;
        unordered_set<string> visited;
        for(auto& account : accounts)
        {
            if(visited.find(account[1])!=visited.end()) continue;
            
            string& name=account[0];            
            ans.push_back({name});
            dfs(account[1], adj, visited, ans.back());
            sort(ans.back().begin()+1, ans.back().end());
        }
                
        return ans;
    }
    
    void dfs(string& node, unordered_map<string, vector<string>>& adj, unordered_set<string>& visited, vector<string>& ans)
    {
        if(visited.find(node)!=visited.end()) return;
        
        visited.insert(node);
        ans.push_back(node);
        for(auto& neighbor : adj[node])
        {
            dfs(neighbor, adj, visited, ans);
        }
    }
};

//2022-09-19
//time  : O(v+e + klogk)
//space : O(v+e)
class union_find
{
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> size;
        
public:
    union_find()
    {
        
    }
    
    void combine(string& a, string& b)
    {
        if(parent.find(a)==parent.end())
        {
            parent[a]=a;
            size[a]=1;
        }
        
        if(parent.find(b)==parent.end())
        {            
            parent[b]=a;
            size[b]=1;
            ++size[a];
            return;
        }
                
        string root_a=find(a);        
        string root_b=find(b);
        //cout<<a<<", "<<root_a<<" | "<<b<<", "<<root_b<<endl;
        if(root_a==root_b) return;
        
        if(size[a]>size[b])
        {
            parent[root_b]=root_a;
            size[root_a]+=size[root_b];
        }
        else
        {
            parent[root_a]=root_b;
            size[root_b]+=size[root_a];
        }                
    }
    
    string find(string& a)
    {       
        if(parent[a]==a) return a;
                
        parent[a]=find(parent[a]);
        return parent[a];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n=accounts.size();
        
        union_find uf;
        unordered_map<int, string> mapping;
        for(int i=0; i<n; ++i)
        {
            //cout<<i<<" : ";
            vector<string>& account=accounts[i];
            mapping[i]=account[0];
            for(int k=1; k<account.size(); ++k)
            {
                //cout<<k<<" ";
                string& email=account[k];
                string group=to_string(i);
                uf.combine(group, email);
            }
            //cout<<endl;
        }
        
        //cout<<"done !"<<endl;
        
        vector<vector<string>> ans;
        unordered_set<string> visited_email;
        vector<int> visited_group(n,-1);
        for(int i=0; i<n; ++i)
        {
            vector<string>& account=accounts[i];
            
            for(int k=1; k<account.size(); ++k)
            {
                string& email=account[k];
                
                if(visited_email.find(email)!=visited_email.end()) continue;
                visited_email.insert(email);
                
                int group=stoi(uf.find(email));
                if(visited_group[group]==-1)
                {
                    ans.push_back({mapping[group]});
                    visited_group[group]=ans.size()-1;
                }
                
                int idx=visited_group[group];
                ans[idx].push_back(email);
            }
        }
        
        for(int i=0; i<ans.size(); ++i)
        {
            sort(ans[i].begin()+1, ans[i].end());
        }
        
        return ans;
    }
};

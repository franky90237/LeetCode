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

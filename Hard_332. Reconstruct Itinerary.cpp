//2024-01-26
//time  : O(v^e)
//space : O(v*e)
class Solution 
{
private:
    unordered_map<string, vector<string>> g;
    int pathLen;
    vector<vector<string>> paths;
    vector<string> res;
    unordered_map<string, vector<bool>> vis;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        pathLen = 1 + tickets.size();
        //cout<<pathLen<<endl;
        
        buildGraph(tickets);
        
        string begin="JFK";
        dfs(begin);
        
        return res;
    }
    
    bool dfs(string& cur)
    {
        //cout<<cur<<endl;
        //cout<<res.size()<<" ";
        res.emplace_back(cur);
        
        for(int i=0; i<g[cur].size(); ++i)
        {
            if(vis[cur][i]) continue;            
            vis[cur][i]=true;                        
            
            bool isFind = dfs(g[cur][i]);
            if(isFind) return true;
            
            vis[cur][i]=false;
                        
            int j=i+1;            
            for(; j<g[cur].size(); ++j)
            {
                if(g[cur][j] != g[cur][i]) break;
            }        
            i=j-1;
        }
        
        if(res.size() == pathLen) return true;
        
        res.pop_back();
        return false;
    }
    
    void buildGraph(vector<vector<string>>& tickets)
    {        
        for(auto ticket : tickets)
        {                 
            g[ticket[0]].emplace_back(ticket[1]);
        }                        
        
        for(auto& it : g)
        {
            sort(it.second.begin(), it.second.end());
            
            int len=(it.second).size();
            vis[it.first].resize(len, false);
        }
        
        /*
        for(auto it : g)
        {
            cout<<it.first<<" : ";
            for(auto& s : it.second) cout<<s<<" ";
            cout<<endl;
        }
        */
    }
};

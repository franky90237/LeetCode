//2023-04-21
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<int>> graph;
    vector<int> paths;
    vector<vector<int>> dp;
    
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips)
    {
        graph.resize(n);
        createGraph(edges);
        //cout<<"graph created \n";
        
        paths.resize(n, 0);
        for(int i=0; i<trips.size(); ++i)
        {            
            int s=trips[i][0];
            int e=trips[i][1];
            
            //vector<bool> used(n, false);
            //bool find = false;            
            dfs(-1, s, e);            
        }
        /*
        cout<<"total init \n";
        for(int i=0; i<n; ++i) 
        {
            if(paths[i] == 0) continue;
            cout<<i<<" : "<<paths[i]<<endl;
        }
        cout<<endl;
        */
        
        dp.resize(n, vector<int>(2, -1));
        return solve(price, -1, 0, false);                                   
    }
    
    void createGraph(vector<vector<int>>& edges)
    {
        for(auto edge: edges)
        {
            int s=edge[0];
            int e=edge[1];            
            graph[s].push_back(e);
            graph[e].push_back(s);            
        }
    }
    
    bool dfs(int parent, int s, int e)
    {        
        ++paths[s];
        
        if(s == e)
        {            
            return true;
        }
        
        bool isFind=false;
        for(auto nei: graph[s])
        {
            if(nei == parent) 
            {
                continue;
            }
            
            isFind = dfs(s, nei, e);
            if(isFind)
            {
                return true;
            }
        }
                        
        --paths[s];
        return false;                        
    }
    
    int solve(vector<int>& price, int parent, int cur, bool preHalve)
    {
        int notHalve = price[cur]*paths[cur];
        for(auto nei: graph[cur])
        {
            if(nei == parent) continue;
            notHalve += solve(price, cur, nei, false);
        }
        
        if(dp[cur][preHalve] != -1)
        {
            return dp[cur][preHalve];
        }
        
        int halve=INT_MAX;
        if(!preHalve)
        {
            halve = price[cur]*paths[cur]/2;
            for(auto nei: graph[cur])
            {
                if(nei == parent) continue;
                halve += solve(price, cur, nei, true);
            }
        }
        
        dp[cur][preHalve]=min(notHalve, halve);
        return dp[cur][preHalve];
    }
};

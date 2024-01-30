//2024-01-29
//time  : O(n*n*n)
//space : O(n*n)
class Solution { 
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {     
        
        vector<vector<int>> minCost(n+1, vector<int>(n+1, INT_MAX/2));
        for(int i=0; i<=n; ++i) minCost[i][i]=0;
        for(auto& time : times)
        {
            int s=time[0];
            int t=time[1];
            int c=time[2];            
            minCost[s][t]=c;
        }        
        
        for(int k=1; k<=n; ++k)
        {
            for(int i=1; i<=n; ++i)
            {
                for(int j=1; j<=n; ++j)
                {
                    if(minCost[i][j] > minCost[i][k] + minCost[k][j])
                    {
                        minCost[i][j] = minCost[i][k] + minCost[k][j];
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=1; i<=n; ++i)
        {
            //cout<<k<<" "<<i<<" | "<<minCost[k][i]<<endl;
            if(i == k) continue;
            if(minCost[k][i] == INT_MAX/2) return -1;        
            ans = max(ans, minCost[k][i]);
        }
        
        return ans;
    }          
};

//2024-01-30
//time  : O(e + vlog(e))
//space : O(v+e)
class Solution 
{
private:
    vector<vector<pair<int, int>>> g;
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        buildGraph(times, n);
        
        vector<bool> vis(n+1, false);
        
        vector<int> dist(n+1, INT_MAX/2);
        dist[k]=0;
                
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        while(!q.empty())
        {
            int cur=q.top().second;
            //int val=q.top().first;
            q.pop();
            vis[cur]=true;
            --n;
            
            for(auto it : g[cur])
            {
                int next=it.first;
                int weight=it.second;
                if(vis[next]) continue;
                
                int newDist = dist[cur] + weight;
                if(newDist < dist[next]) 
                {
                    dist[next]=newDist;
                    q.push({newDist, next});
                }
             }
        }
        
        //for(int i : dist) cout<<i<<" "; cout<<endl;
        if(n > 0) return -1;
        return *max_element(dist.begin()+1, dist.end());
    }
    
    void buildGraph(vector<vector<int>>& times, int n)
    {
        g.resize(n+1);
        for(auto& time : times)
        {
            int source=time[0];
            int target=time[1];
            int weight=time[2];
            g[source].push_back({target, weight});
        }
    }
};

//2024-01-30
//time  : O(n*e)
//space : O(n)
class Solution {    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {        
        vector<int> dist(n+1, INT_MAX/2);
        dist[k]=0;
        
        for(int i=1; i<=n-1; ++i)
        {
            for(auto time : times)
            {
                int source=time[0];
                int target=time[1];
                int weight=time[2];
                
                if(dist[target] > dist[source] + weight)
                {
                    dist[target] = dist[source] + weight;
                }
            }                        
        }
        
        //for(int i : dist) cout<<i<<" "; cout<<endl;
        int ans=-1;
        for(int i=1; i<=n; ++i) ans=max(ans, dist[i]);        
        return ans == INT_MAX/2 ? -1 : ans;
    }      
};

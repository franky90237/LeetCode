//2022-11-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n=roads.size();
        if(n == 0) return 0;
        
        vector<unordered_set<int>> graph(100001);        
        createGraph(roads, graph);
        
        long long ans=0;       
        
        vector<int> nodeCnt(100001, 1);        
        vector<unordered_set<int>> cur(100002);
        for(int i=1; i<graph.size(); ++i)
        {            
            if(graph[i].size() == 1)
            {
                cur[0].insert(i);
                //cout<<i<<" "<<graph[i].size()<<endl;
            }
        }
                
        for(int i=0; i<cur.size(); ++i)
        {
            //cout<<i<<" "<<cur[i].size()<<endl;
            if(cur[i].size() == 0) break;
            
            for(auto it=cur[i].begin(); it!=cur[i].end(); ++it)
            {
                int city=*it;
                double cnt=nodeCnt[city];
                ans += ceil(cnt/seats);
                //cout<<city<<" "<<cnt<<" "<<ans<<endl;                                               
                
                int neighbor=*(graph[city].begin());
                if(neighbor == 0) continue;                
                
                graph[neighbor].erase(city);
                nodeCnt[neighbor] += cnt;
                if(graph[neighbor].size() >= 2) continue;
                
                cur[i+1].insert(neighbor);
            }            
        }
        
        return ans;
    }
    
    void createGraph(vector<vector<int>>& roads, vector<unordered_set<int>>& graph)
    {        
        for(auto road: roads)
        {
            int a=road[0];
            int b=road[1];
            graph[a].insert(b);
            graph[b].insert(a);            
        }
        
    }
};

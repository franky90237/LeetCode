//2023-05-01
//time  : O(n*n), where n is the number of nodes
//sapce : O(n*n)
class Solution 
{
private:
    int size=1e5;  
    unordered_map<long long, unordered_set<long long>> graph;
    unordered_map<long long, unordered_map<long long, int>> cost;    
    
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads)
    {        
        vector<vector<int>> Roads;
        for(auto& Road : specialRoads)
        {
            int c = abs(Road[2]-Road[0]) + abs(Road[3]-Road[1]);
            if(Road[4] < c)
            {
                Roads.push_back({Road[0], Road[1], Road[2], Road[3], Road[4]});
            }
        }
        
        createGraph(start, target, Roads);
        /*
        for(auto nei: graph[2*size+3])
        {
            cout<<nei<<endl;
        }
        */        
        return shortestPath((long long)start[0]*size+start[1], (long long)target[0]*size+target[1]);
    }
    
    void createGraph(vector<int>& start, vector<int>& target, vector<vector<int>>& Roads)
    {
        long long begin = (long long)start[0]*size+start[1];
        long long end = (long long)target[0]*size+target[1];
        
        graph[begin].insert(end);
        cost[begin][end] = abs(target[0]-start[0]) + abs(target[1]-start[1]);
        
        int n = Roads.size();
        int distance;
        for(int i=0; i<n; ++i)
        {         
            long long curStart = (long long)Roads[i][0]*size+Roads[i][1];
            long long curEnd = (long long)Roads[i][2]*size+Roads[i][3];
                        
            graph[begin].insert(curStart);
            distance = abs(Roads[i][0] - start[0]) + abs(Roads[i][1] - start[1]);
            if(cost[begin].find(curStart) == cost[begin].end()) cost[begin][curStart]=distance;
            else cost[begin][curStart] = min(cost[begin][curStart], distance);
            
            graph[curEnd].insert(end);
            distance = abs(target[0] - Roads[i][2]) + abs(target[1] - Roads[i][3]);
            if(cost[curEnd].find(end) == cost[curEnd].end()) cost[curEnd][end] = distance;
            else cost[curEnd][end] = min(cost[curEnd][end], distance);
            
            graph[curStart].insert(curEnd);
            if(cost[curStart].find(curEnd) == cost[curStart].end()) cost[curStart][curEnd] = Roads[i][4];
            cost[curStart][curEnd] = min(cost[curStart][curEnd], Roads[i][4]);
            
            for(int k=0; k<n; ++k)
            {
                if(k == i) continue;
                
                long long nxtStart=(long long)Roads[k][0]*size+Roads[k][1];
                if(curEnd == nxtStart) continue;                                
            
                graph[curEnd].insert(nxtStart);
                distance = abs(Roads[k][0]-Roads[i][2]) + abs(Roads[k][1]-Roads[i][3]);
                if(cost[curEnd].find(nxtStart) == cost[curEnd].end()) cost[curEnd][nxtStart]=distance;
                else cost[curEnd][nxtStart] = min(cost[curEnd][nxtStart], distance);
            }                                    
        }
    }
    
    int shortestPath(long long begin, long long end)
    {        
        //cost[begin][begin]=0;
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minHeap;
        minHeap.push({0, begin});
        
        long long cur=begin;
        while(cur != end)
        {            
            int distance=minHeap.top()[0];
            cur = minHeap.top()[1];
            minHeap.pop();
            //cout<<cur/size<<","<<cur%size<<endl;
            
            auto it=graph[cur].begin();
            while(it != graph[cur].end())
            {
                long long nei=*it;
                
                if(cost[begin].find(nei) == cost[begin].end()) 
                {
                    cost[begin][nei]=abs(nei/size - begin/size) + abs(nei%size - begin%size);
                }
                
                if(distance + cost[cur][nei] < cost[begin][nei])
                {
                    cost[begin][nei]=cost[begin][cur] + cost[cur][nei];                    
                }
                
                //cout<<nei/size<<","<<nei%size<<" | "<<cost[begin][nei]<<endl;                
                minHeap.push({cost[begin][nei], nei});
                it = graph[cur].erase(it);
            }
        }
        
        //cout<<minHeap.size()<<" | "<<cur<<" : "<<end<<endl;
        return cost[begin][end];        
    }    
};

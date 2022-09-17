//2022-06-09
//dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> relation(numCourses,vector<int>());        
        
        for(auto& p:prerequisites)
        {
            int pre=p[1];
            int cur=p[0];
            
            if(pre==cur) return false;
            relation[pre].push_back(cur);
        }      
        
        bool travel[numCourses];
        for(int i=0; i<numCourses; ++i) travel[i]=false;    
        
        for(int i=0; i<numCourses; ++i)
        {
            if(relation[i].empty() || travel[i]) continue;
            
            bool visited[numCourses];
            for(int j=0; j<numCourses; ++j) visited[j]=false;
            if(hasCycle(i,relation,visited,travel)) 
            {
                //cout<<endl<<i<<endl;
                return false;
            }
            
            travel[i]=true;
        }
        
        return true;
    }
    
    bool hasCycle(int now, vector<vector<int>>& relation, bool visited[], bool travel[])
    {
        //cout<<now<<endl;
        if(relation[now].empty()) return false;
        if(travel[now]) return false;
        if(visited[now]) return true;
        
        visited[now]=true;
        
        for(auto i:relation[now])
        {
            bool isCycle=hasCycle(i,relation,visited,travel);
            if(isCycle) return true;
        }
        
        visited[now]=false;
        
        travel[now]=true;
        return false;
    }
};

//2022-06-09
//clear dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> relation(numCourses,vector<int>());        
        
        for(auto& p:prerequisites)
        {
            int pre=p[1];
            int cur=p[0];
            
            if(pre==cur) return false;
            relation[pre].push_back(cur);
        }    
        
        bool travel[numCourses],visited[numCourses];
        for(int i=0; i<numCourses; ++i) 
        {
            travel[i]=false;
            visited[i]=false;
        }
        
        for(int i=0; i<numCourses; ++i)
        {
            if(relation[i].empty() || travel[i]) continue;
                        
            if(hasCycle(i,relation,visited,travel)) 
            {
                //cout<<endl<<i<<endl;
                return false;
            }                      
        }
        
        return true;
    }
    
    bool hasCycle(int now, vector<vector<int>>& relation, bool visited[], bool travel[])
    {
        //cout<<now<<endl;
        if(relation[now].empty()) return false;
        if(travel[now]) return false;
        if(visited[now]) return true;
        
        visited[now]=true;
        
        for(auto i:relation[now])
        {
            if(hasCycle(i,relation,visited,travel)) return true;            
        }
        
        visited[now]=false;
        
        travel[now]=true;
        return false;
    }
};

//2022-09-17
//time  : O(n+e)
//space : O(n+e)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        int indegree[numCourses];
        for(int i=0; i<numCourses; ++i) indegree[i]=0;
        build_graph(numCourses, prerequisites, graph, indegree);
        
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
        {
            //cout<<i<<" : "<<indegree[i]<<endl;
            if(indegree[i]==0)
            {
                q.push(i);                
            }
        }
        
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ++cnt;
            
            for(auto& neighbor : graph[node])
            {
                --indegree[neighbor];
                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }
        
        return cnt==numCourses;
    }
        
    void build_graph(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& graph, int indegree[])
    {
        for(auto& course : prerequisites)
        {
            int pre=course[1];
            int nxt=course[0];
            
            graph[pre].push_back(nxt);
            ++indegree[nxt];
        }        
    }
};

//2022-09-17
//time  : O(n+e)
//space : O(n+e)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        build_graph(numCourses, prerequisites, graph);
        
        vector<bool> last_done(numCourses,false);
        vector<bool> visited(numCourses,false);
        for(int i=0; i<numCourses; ++i)
        {
            if(!last_done[i] && check_cycle(graph, last_done, visited, i))
            {
                return false;
            }
        }
        
        return true;
    }
        
    void build_graph(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& graph)
    {
        for(auto& course : prerequisites)
        {
            int pre=course[1];
            int nxt=course[0];
            
            graph[pre].push_back(nxt);            
        }        
    }
    
    bool check_cycle(vector<vector<int>>& graph, vector<bool>& last_done, vector<bool>& visited, int node)
    {
        //cout<<node<<endl;
        if(visited[node]) return true;
        
        if(last_done[node]) return false;
        
        visited[node]=true;
        last_done[node]=true;
        
        for(auto& neighbor : graph[node])
        {            
            bool has_cycle = check_cycle(graph, last_done, visited, neighbor);
            if(has_cycle) return true;
        }
        
        visited[node]=false;
        return false;
    }
};

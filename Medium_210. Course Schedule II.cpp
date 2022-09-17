//2022-09-17
//clear dfs
//time  : O(n+e)
//space : O(n)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        build_graph(numCourses, prerequisites, graph);
                
        vector<int> visited(numCourses,0);
        vector<int> ans;
        for(int i=0; i<numCourses; ++i)
        {
            if(visited[i]==0 && !dfs(graph, visited, ans, i))
            {
                return {};
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;        
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
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans, int node)
    {
        if(visited[node]==1) return false;
        if(visited[node]==2) return true;
        
        visited[node]=1;
        
        for(auto& neighbor : graph[node])
        {
            if(!dfs(graph, visited, ans, neighbor)) return false;
        }
        
        ans.push_back(node);
        visited[node]=2;
        
        return true;
    }
};

//2022-09-17
//bfs
//time  : O(n+e)
//space : O(e)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses,0);
        build_graph(numCourses, prerequisites, graph, indegree);
                
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
        {
            if(indegree[i]==0) q.push(i);
        }
                
        vector<int> ans;        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto& neighbor : graph[node])
            {
                --indegree[neighbor];
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
        
        return ans.size()==numCourses ? ans : vector<int>();
    }
    
    void build_graph(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& graph, vector<int>& indegree)
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

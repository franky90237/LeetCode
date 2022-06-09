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
        
        /*for(int i=0; i<numCourses; ++i)
        {
            printf("%d [",i);
            for(auto& j:relation[i]) printf(" %d ",j);
            printf("] \n");
        }
        cout<<endl;*/
        
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
        
        return false;
    }
};

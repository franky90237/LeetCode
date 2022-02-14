class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n=rooms.size();
        unordered_set<int> visited;
        
        dfs(visited,rooms,0);
        
        return visited.size()==n;
    }
    
    void dfs(unordered_set<int>& visited, vector<vector<int>>& rooms, int now)
    {
        if(visited.count(now)==1) return;
        
        visited.insert(now);
        
        for(int i=0;i<rooms[now].size();++i)
        {
            if(visited.count(rooms[now][i])==0)
            {
                dfs(visited,rooms,rooms[now][i]);
            }
        }
    }
};

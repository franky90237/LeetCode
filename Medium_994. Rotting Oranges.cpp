//2022-09-12
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<vector<int>> q;
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c]==2)
                {
                    q.push({r,c});
                    grid[r][c]=3;
                }
            }
        }
        
        
        int time=-1;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
                int r=q.front()[0];
                int c=q.front()[1];
                q.pop();
                
                if(r-1>=0 && grid[r-1][c]==1)
                {
                    q.push({r-1,c});
                    grid[r-1][c]=3;
                }
                
                if(r+1<m && grid[r+1][c]==1)
                {
                    q.push({r+1,c});
                    grid[r+1][c]=3;
                }
                
                if(c-1>=0 && grid[r][c-1]==1)
                {
                    q.push({r,c-1});
                    grid[r][c-1]=3;
                }
                
                if(c+1<n && grid[r][c+1]==1)
                {
                    q.push({r,c+1});
                    grid[r][c+1]=3;
                }
                
                --size;
            }
            
            ++time;
        }
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c]==1) return -1;
            }
        }
        
        return time==-1 ? 0 : time;
    }
};

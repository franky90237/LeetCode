//2022-07-16
//dfs
//time  : O(n*m)
//space : O(1)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c]==1)
                {
                    ans=max(ans,dfs(r,c,grid));
                    //cout<<r<<" "<<c<<" : "<<ans<<endl;
                }
            }
        }
        
        return ans;
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]!=1) return 0;
        
        grid[r][c]=2;
        int up=dfs(r-1,c,grid);
        int bottom=dfs(r+1,c,grid);
        int right=dfs(r,c+1,grid);
        int left=dfs(r,c-1,grid);
        
        return 1+up+bottom+right+left;
        //return 1+max(up,max(bottom,max(right,left)));
    }
};

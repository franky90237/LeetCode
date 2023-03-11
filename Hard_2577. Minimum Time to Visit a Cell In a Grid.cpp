//2023-03-11
//time  : O(m*n*log(m*n))
//space : O(m*n)
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) 
    {
        if(grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0]=0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});    
        
        int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty())
        {
            int t=q.top()[0];
            int r=q.top()[1];
            int c=q.top()[2];
            q.pop();
            
            //cout<<r<<" "<<c<<" "<<t<<endl;
            
            for(int i=0; i<4; ++i)
            {
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                int time=t;
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                {
                    continue;
                }
                
                ++time;
                if(time < grid[nr][nc])
                {
                    int diff=grid[nr][nc]-time;
                    if(diff % 2 == 0) time=grid[nr][nc];
                    else time=grid[nr][nc]+1;
                }
                
                if(time < ans[nr][nc])
                {
                    ans[nr][nc]=time;
                    q.push({time, nr, nc});
                }
            }
        }
        
        return ans[m-1][n-1];
    }
};

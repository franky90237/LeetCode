//2023-08-08
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n=grid.size();
        queue<vector<int>> q;
        for(int r=0; r<n; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c] == 1) 
                {
                    q.push({r, c});
                    grid[r][c]=0;
                }
                else 
                {
                    grid[r][c]=INT_MAX;
                }
            }
        }

        int maxSF = calculateNodeSF(grid, q);
        //cout<<"maxSF : "<<maxSF<<endl;

        int left=0;
        int right=maxSF;
        int ans=0;
        while(left <= right)
        {            
            int mid=left+(right-left)/2;
            //cout<<left<<" "<<mid<<" "<<right<<endl;
            if(check(grid, mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        return ans;
    }

    int calculateNodeSF(vector<vector<int>>& grid, queue<vector<int>>& q)
    {
        int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n=grid.size();
        int maxSF=0;
        int dis=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size > 0)
            {
                int r=q.front()[0];
                int c=q.front()[1];
                q.pop();

                for(int i=0; i<4; ++i)
                {
                    int nr=r+dir[i][0];
                    int nc=c+dir[i][1];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] <= dis) continue;
                    grid[nr][nc]=dis;
                    q.push({nr, nc});
                }

                --size;
            }

            ++dis;
        }

        return dis-1;
    }

    bool check(vector<vector<int>>& grid, int ans)
    {
        if(grid[0][0] < ans) return false;

        int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n=grid.size();
        
        queue<vector<int>> q;
        q.push({0, 0});

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0]=true;

        while(!q.empty())
        {
            int size=q.size();
            while(size > 0)
            {
                int r=q.front()[0];
                int c=q.front()[1];
                q.pop();
                if(r == n-1 && c == n-1) return true;

                for(int i=0; i<4; ++i)
                {
                    int nr=r+dir[i][0];
                    int nc=c+dir[i][1];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] || grid[nr][nc] < ans) continue;
                    vis[nr][nc]=true;
                    q.push({nr, nc});
                }

                --size;
            }
        }

        return false;
    }
};

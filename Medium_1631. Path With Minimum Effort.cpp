//2023-08-10
//time  : O(m*n*log(100000))
//spcae : O(m*n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int left=0;
        int right=1000000;
        int ans=0;
        while(left <= right)
        {
            int mid=left+(right-left)/2;
            cout<<left<<" "<<mid<<" "<<right<<endl;
            if(check(heights, mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }            
        }

        return ans;    
    }

    bool check(vector<vector<int>>& heights, int diff)
    {
        int m=heights.size();
        int n=heights[0].size();
        int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0]=true;
        
        queue<vector<int>> q;
        q.push({0, 0});
        
        while(!q.empty())
        {
            int r=q.front()[0];
            int c=q.front()[1];
            q.pop();
            if(r == m-1 && c == n-1) return true;

            for(int i=0; i<4; ++i)
            {
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc] || abs(heights[nr][nc] - heights[r][c]) > diff) continue;
                vis[nr][nc]=true;
                q.push({nr, nc});
            }
        }

        return false;
    }
};

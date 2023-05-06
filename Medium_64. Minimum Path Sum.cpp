//2023-05-06
//time  : O(m*n*log(m*m))
//space : O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {                    
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0]=grid[0][0];
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        
        int dir[2][2]={{0,1}, {1,0}};
        while(!minHeap.empty())
        {
            int dis = minHeap.top()[0];
            int r = minHeap.top()[1];
            int c = minHeap.top()[2];
            //cout<<r<<" "<<c<<" | "<<dis<<endl;
            minHeap.pop();
            if(r == m-1 && c == n-1) break;
            
            for(int i=0; i<2; ++i)
            {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];
                if(nr >= m || nc >= n) continue;
                
                if(dis + grid[nr][nc] < ans[nr][nc])
                {
                    ans[nr][nc] = dis+grid[nr][nc];
                    minHeap.push({ans[nr][nc], nr, nc});
                }
            }
        }
        
        return ans[m-1][n-1];
    }
};

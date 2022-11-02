//2022-11-02
//time  : O(m*n)
//space : O(n)
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> ans(n, 0);
        for(int i=0; i<n; ++i)
        {
            int r=0;
            int c=i;
            while(r < m)
            {
                if(grid[r][c] == 1)
                {
                    if(c+1 == n || grid[r][c+1] == -1)
                    {
                        ans[i]=-1;
                        break;
                    }
                    
                    ++r;
                    ++c;
                }
                else
                {
                    if(c-1 == -1 || grid[r][c-1] == 1)
                    {
                        ans[i]=-1;
                        break;
                    }
                    
                    ++r;
                    --c;
                }
            }
            
            if(ans[i] != -1) ans[i]=c;
        }
        
        return ans;
    }
};

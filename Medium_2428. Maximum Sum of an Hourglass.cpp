//2022-10-020
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int r=1;
        int c=1;
        
        int ans=0;
        for(int r=1; r<=m-2; ++r)
        {
            for(int c=1; c<=n-2; ++c)
            {
                int sum=get_sum(grid, r, c);
                //cout<<r<<", "<<c<<" : "<<sum<<endl;
                ans=max(ans, sum);
            }
        }
        
        return ans;
    }
    
    int get_sum(vector<vector<int>>& grid, int r, int c)
    {
        int sum=0;
        for(int i=r-1; i<=r+1; ++i)
        {
            for(int k=c-1; k<=c+1; ++k)
            {                
                sum+=grid[i][k];
            }
        }
        
        return sum-grid[r][c-1]-grid[r][c+1];
    }
};

//2022-10-04
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int r=0; r<=m-3; ++r)
        {
            for(int c=0; c<=n-3; ++c)
            {
                int sum = grid[r][c]   + grid[r][c+1]   + grid[r][c+2]
                                       + grid[r+1][c+1] +
                          grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];
                ans=max(ans, sum);
            }
        }
        
        return ans;
    }
};

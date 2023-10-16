//2023-10-16
//time  : O(n*m)
//space : O(n*m)
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int modulo=12345;
        
        vector<int> pre(m*n);
        vector<int> suf(m*n);
        
        long long product=1;
        for(int r=0; r<n; ++r)
        {
            for(int c=0; c<m; ++c)
            {
                int cur=r*m+c;
                product = (product*grid[r][c])%modulo;
                pre[cur] = product;
            }
        }
        
        product=1;
        for(int r=n-1; r>=0; --r)
        {
            for(int c=m-1; c>=0; --c)
            {
                int cur=r*m+c;
                product = (product*grid[r][c])%modulo;
                suf[cur] = product;
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        for(int r=0; r<n; ++r)
        {
            for(int c=0; c<m; ++c)
            {
                int cur=r*m+c;
                if(cur-1 < 0) ans[r][c]=suf[cur+1];
                else if(cur+1 >= m*n) ans[r][c]=pre[cur-1];
                else ans[r][c]=((long long)pre[cur-1]*(long long)suf[cur+1])%modulo;
            }
        }
        
        return ans;
    }
};

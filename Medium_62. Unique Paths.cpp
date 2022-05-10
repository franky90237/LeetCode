//2022-05-10
//dp iterative
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        for(int r=0; r<m; ++r) dp[r][n-1]=1;
        for(int c=0; c<n; ++c) dp[m-1][c]=1;
        
        for(int r=m-2; r>=0; --r)
        {
            for(int c=n-2; c>=0; --c)
            {
                //printf("%d %d \n",r,c);
                dp[r][c]=dp[r][c+1]+dp[r+1][c];
            }
        }
        
        return dp[0][0];
    }
};

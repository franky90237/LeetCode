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

//2022-05-10
//reference : https://leetcode.com/problems/unique-paths/discuss/22958/Math-solution-O(1)-space
//combination
//time  : O(n)
//space : O(1)
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        if(m==1 || n==1) return 1;
        
        --m;
        --n;
        
        if(m<n) swap(m,n);
        
        long res=1;
        int c1=m+1;
        int c2=1;        
        while(c1<=m+n) 
        {            
            res*=c1;
            res/=c2;
            
            ++c1;
            ++c2;
        }                
        
        return res;
    }
};

//2024-02-11
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int uniquePaths(int m, int n) 
    {
        --m;
        --n;
        dp.resize(m+1, vector<int>(n+1, -1));
        f(m, n);
        
        return f(m, n);
    }
    
    int f(int m, int n)
    {
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        
        return dp[m][n] = (f(m-1, n) + f(m, n-1));
        
    }
};

//2022-06-14
//TLE
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        return solve(0,0,triangle);
    }
    
    int solve(int row, int column, vector<vector<int>>& triangle)
    {
        int m=triangle.size();
        if(row==m) return 0;
        
        int n=triangle[row].size();                
        if(column==n) return 0;
        
        int sum1=triangle[row][column]+solve(row+1,column,triangle);
        int sum2=triangle[row][column]+solve(row+1,column+1,triangle);
        
        return min(sum1,sum2);
    }
};

//2022-06-14
//dp recursive
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m=triangle.size();
        int n=triangle[m-1].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
    
    int solve(int row, int column, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        int m=triangle.size();
        if(row==m) return 0;
        
        int n=triangle[row].size();
        if(column==n) return 0;
        
        //cout<<row<<" "<<column<<endl;
        if(dp[row][column]!=-1) return dp[row][column];
        
        int sum1=triangle[row][column]+solve(row+1,column,triangle,dp);
        int sum2=triangle[row][column]+solve(row+1,column+1,triangle,dp);
        
        dp[row][column]=min(sum1,sum2);
        return dp[row][column];
    }
};

//2022-06-14
//dp iterative
//time  : O(m*m)
//space : O(m*n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m=triangle.size();
        int n=triangle[m-1].size();
        
        int dp[m][n];
        for(int i=0; i<n; ++i) dp[m-1][i]=triangle[m-1][i];
        
        for(int i=m-2; i>=0; --i)
        {
            for(int j=0; j<=i; ++j)
            {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }    
};

//2022-04-12
//TLE
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        return solve(text1,0,text2,0);
    }
    
    int solve(string& text1, int i1, string& text2, int i2) 
    {
        int j1=text1.size();
        int j2=text2.size();
        
        if(i1>=j1 || i2>=j2) return 0;
        
        if(text1[i1]==text2[i2]) return 1+solve(text1,i1+1,text2,i2+1);
        
        return max(solve(text1,i1+1,text2,i2),solve(text1,i1,text2,i2+1));
    }
};

//2022-04-12
//dp recursive
//time  : O(n*m)
//space : O(n*m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int j1=text1.size();
        int j2=text2.size();
        int n= (j1>j2) ? j1 : j2;
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(dp,text1,0,text2,0);
    }
    
    int solve(vector<vector<int>>& dp, string& text1, int i1, string& text2, int i2) 
    {
        int j1=text1.size();
        int j2=text2.size();
        
        if(i1>=j1 || i2>=j2) return 0;
        
        if(dp[i1][i2]!=-1) return dp[i1][i2];
                
        if(text1[i1]==text2[i2]) 
        {
            if(i1+1<j1 && i2+1<j2) 
            {
                dp[i1+1][i2+1]=solve(dp,text1,i1+1,text2,i2+1);
                return 1+dp[i1+1][i2+1];
            }
            else return 1;
        }

        dp[i1][i2]=max(solve(dp,text1,i1+1,text2,i2),solve(dp,text1,i1,text2,i2+1));
        return dp[i1][i2];
    }
};

//2022-04-12
//dp iterative
//time  : O(n*m)
//space : O(n*m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                //cout<<i<<"-"<<j<<" "<<dp[i][j]<<endl;
            }
        }
        
        return dp[n][m];
    }
};

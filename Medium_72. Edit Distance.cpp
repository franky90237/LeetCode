//2023-11-16
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int minDistance(string word1, string word2) 
    {
        int m=word1.size();
        int n=word2.size();
        dp.resize(m, vector<int>(n, -1));
        
        return dfs(word1, word2, 0, 0);
    }
    
    int dfs(string word1, string word2, int x, int y)
    {
        int len1=word1.size();
        int len2=word2.size();
        if(x == len1 && y == len2) return 0;
        if(x == len1) return len2-y;
        if(y == len2) return len1-x;
        if(dp[x][y] != -1) return dp[x][y];
        
        if(word1[x] == word2[y])
        {
            dp[x][y] = dfs(word1, word2, x+1, y+1);
            return dp[x][y];
        }
        
        int ins=1+dfs(word1, word2, x, y+1);
        int del=1+dfs(word1, word2, x+1, y);
        int rep=1+dfs(word1, word2, x+1, y+1);
        dp[x][y] = min(ins, min(del, rep));
        return dp[x][y];
    }
};

//2023-11-16
//time  : O(m*n)
//space : O(m*n)
class Solution {    
public:
    int minDistance(string word1, string word2) 
    {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        dp[m][n]=0;
        for(int y=0; y<n; ++y) dp[m][y]=n-y;
        for(int x=0; x<m; ++x) dp[x][n]=m-x;
            
        for(int x=m-1; x>=0; --x)
        {
            for(int y=n-1; y>=0; --y)
            {
                if(word1[x] == word2[y])
                {
                    dp[x][y] = dp[x+1][y+1];                    
                }
                else
                {
                    int ins=1+dp[x][y+1];
                    int del=1+dp[x+1][y];
                    int rep=1+dp[x+1][y+1];
                    dp[x][y] = min(ins, min(del, rep));
                }
            }
        }
        
        return dp[0][0];
    }    
};

//2023-11-16
//time  : O(m*n)
//space : O(2*max(m, n))
class Solution {    
public:
    int minDistance(string word1, string word2) 
    {
        int m=word1.size();
        int n=word2.size();
        int size=max(m, n);
        vector<vector<int>> dp(2, vector<int>(size+1));
        
        dp[m%2][n]=0;
        for(int y=0; y<n; ++y) dp[m%2][y]=n-y;
        //for(int x=0; x<m; ++x) dp[x%2][n]=m-x;
            
        for(int x=m-1; x>=0; --x)
        {            
            dp[x%2][n]=m-x;
            for(int y=n-1; y>=0; --y)
            {
                if(word1[x] == word2[y])
                {
                    dp[x%2][y] = dp[(x+1)%2][y+1];                    
                }
                else
                {
                    int ins=1+dp[x%2][y+1];
                    int del=1+dp[(x+1)%2][y];
                    int rep=1+dp[(x+1)%2][y+1];
                    dp[x%2][y] = min(ins, min(del, rep));
                }
            }
        }
        
        return dp[0][0];
    }    
};

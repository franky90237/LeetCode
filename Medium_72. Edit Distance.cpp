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

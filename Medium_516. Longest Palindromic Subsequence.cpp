//2024-03-02
//time  : O(n*n)
//space : O(n*n)
class Solution 
{
private:
    vector<vector<int>> dp;
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        
        return f(s, 0, n-1);
    }
    
    int f(string& s, int i, int j)
    {
        //cout<<i<<" "<<j<<endl;
        
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) return dp[i][j] = f(s, i+1, j-1) + 2;
        return dp[i][j] = max(f(s, i+1, j), f(s, i, j-1));
    }
};

//2024-03-02
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) dp[i][i]=1;
        
        for(int i = n - 2; i >= 0; --i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }     
};

//2024-03-02
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();        
        vector<int> dp(n, 0);
        
        for(int i = n - 1; i >= 0; --i)
        {
            dp[i] = 1;
            
            int dp_iplus1_jminus1 = 0;
            for(int j = i + 1; j < n; ++j)
            {
                int backup = dp[j];
                
                if(s[i] == s[j]) dp[j] = dp_iplus1_jminus1 + 2;
                else dp[j] = max(dp[j], dp[j-1]);
                
                dp_iplus1_jminus1 = backup;
            }
        }
        
        return dp[n-1];
    }     
};

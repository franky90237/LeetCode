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

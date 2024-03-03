//2024-03-03
//time  : O(n*n)
//space : O(n*n)
class Solution 
{
private:
    vector<vector<vector<int>>> dp;
    
public:
    int longestPalindrome(string word1, string word2) 
    {
        string s = word1 + word2;
        int n = s.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(s, word1.size(), 0, n - 1, false);
    }
    
    int f(string& s, int mid, int i, int j, bool hasMatched)
    {
        if((i >= mid || j  < mid) && !hasMatched) return 0;
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j][hasMatched] != -1) return dp[i][j][hasMatched];
        
        if(s[i] == s[j]) return dp[i][j][hasMatched] = f(s, mid, i + 1, j - 1, true) + 2;
        return dp[i][j][hasMatched] = max(f(s, mid, i + 1, j, hasMatched), f(s, mid, i, j - 1, hasMatched));
    }
};

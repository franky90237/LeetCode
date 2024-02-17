//2024-02-17
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int numDistinct(string s, string t) 
    {
        int m = s.size();
        int n = t.size();
        dp.resize(m, vector<int>(n, -1));
        
        return f(s, t, 0, 0);
    }
    
    int f(string& s, string& t, int i, int j)
    {
        //cout<<i<<" "<<j<<endl;
        int m = s.size();
        int n = t.size();
        if(j == n) return 1;        
        if((m-i) < (n-j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = 0;
        if(s[i] == t[j]) res += f(s, t, i+1, j+1);
    
        res += f(s, t, i+1, j);
                
        return dp[i][j] = res;     
    }
};

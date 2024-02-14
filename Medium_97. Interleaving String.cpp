//2024-02-14
//time  : O(n*m*(n+m))
//space : O(n*m)
class Solution 
{
private:
    vector<vector<vector<int>>> dp;
    
public:
    bool isInterleave(string s1, string s2, string s3) 
    {                
        int n=s1.size();
        int m=s2.size();
        if(n + m != s3.size()) return false;
        
        dp.resize(n+1, vector<vector<int>>(m+1, vector<int>(2, -1)));
        return f(s1, s2, s3, 0, 0, true) || f(s1, s2, s3, 0, 0, false);
    }
    
    bool f(string& s1, string& s2, string& s3, int i, int j, bool isFirst)
    {
        //cout<<i<<" "<<j<<" | "<<isFirst<<endl;
        int n=s1.size();
        int m=s2.size();
        if(i == n && j == m) return true;
        if(dp[i][j][isFirst] != -1) return dp[i][j][isFirst];
        
        if(isFirst)
        {
            for(int cur_i = i; cur_i < n; ++cur_i)
            {
                if(s1[cur_i] != s3[cur_i + j]) break;
                bool canSplit = f(s1, s2, s3, cur_i+1, j, false);
                if(canSplit) return dp[i][j][isFirst] = true;
            }
        }
        else
        {
            for(int cur_j = j; cur_j < m; ++cur_j)
            {
                if(s2[cur_j] != s3[i + cur_j]) break;
                bool canSplit = f(s1, s2, s3, i, cur_j+1, true);
                if(canSplit) return dp[i][j][isFirst] = true;
            }
        }        
                
        return dp[i][j][isFirst] = false;
    }      
};

//2024-02-14
//time  : O(n*m*(n+m))
//space : O(n*m)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {                
        int n=s1.size();
        int m=s2.size();
        if(n + m != s3.size()) return false;
        if(n == 0) return s2 == s3;
        if(m == 0) return s1 == s3;
        
        vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(m+1, vector<bool>(2, false)));
        dp[n][m][true] = dp[n][m][false] = true;
        
        for(int i=n-1, x=s3.size()-1; i>=0; --i, --x)
        {
            if(s1[i] != s3[x]) break;
            dp[i][m][true] = true;
        }
                
        for(int j=m-1, x=s3.size()-1; j>=0; --j, --x)
        {
            if(s2[j] != s3[x]) break;
            dp[n][j][false] = true;
        }                
        
        for(int i=n-1; i>=0; --i)
        {
            for(int j=m-1; j>=0; --j)
            {
                for(int cur_i = i; cur_i < n; ++cur_i)
                {
                    if(s1[cur_i] != s3[cur_i + j]) break;
                    dp[i][j][true] = dp[i][j][true] || dp[cur_i + 1][j][false];                  
                }
                
                for(int cur_j = j; cur_j < m; ++cur_j)
                {
                    if(s2[cur_j] != s3[i + cur_j]) break;
                    dp[i][j][false] = dp[i][j][false] || dp[i][cur_j + 1][true];
                }
            }
        }
        
        /*
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j) cout<<dp[i][j][true]<<" ";
            cout<<endl;
        }
        
        cout<<endl;
        
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j) cout<<dp[i][j][false]<<" ";
            cout<<endl;
        }        
        */
        
        return dp[0][0][true] || dp[0][0][false];            
    }        
};

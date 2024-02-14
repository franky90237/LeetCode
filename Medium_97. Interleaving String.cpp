//2024-02-14
//time  : O(n*m*n)
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

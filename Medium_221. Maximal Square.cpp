//2023-08-25
//time  : O(m*n*m)
//space : O(m*n*m)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> right(m, vector<int>(n, 0));       
               
        for(int r=0; r<m; ++r)
        {
            right[r][n-1]=matrix[r][n-1]-'0';
            for(int c=n-2; c>=0; --c)
            {
                if(matrix[r][c] == '1') right[r][c]=1+right[r][c+1];
                //cout<<right[r][c]<<" ";
            }
            //cout<<endl;
        }        
        
        int ans=0;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                int minLen=right[r][c];
                for(int i=r; i<r+minLen && i<m; ++i)
                {
                    int len=i-r+1;
                    if(matrix[i][c] == '0' || right[i][c] < len) break;
                    minLen=min(minLen, right[i][c]);
                    ans=max(ans, len*len);
                }
                //cout<<ans<<" ";            
            }
            //cout<<endl;
        }
        
        return ans;
    }    
};

//2023-08-26
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        dp.resize(m, vector<int>(n, -1));
        int ans=0;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                int len=dfs(matrix, r, c);
                ans=max(ans, len*len);
            }
        }
        
        return ans;
    }    
    
    int dfs(vector<vector<char>>& matrix, int r, int c)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(matrix[r][c] == '0') return 0;
        if(r-1 < 0 || c-1 < 0) return 1;
        if(matrix[r][c-1] == '0' || matrix[r-1][c-1] == '0' || matrix[r-1][c] == '0') return 1;
        if(dp[r][c] != -1) return dp[r][c];
        
        int left=1+dfs(matrix, r, c-1);
        int mid=1+dfs(matrix, r-1, c-1);
        int up=1+dfs(matrix, r-1, c);
        
        dp[r][c]=min(left, min(mid, up));
        return dp[r][c];
    }
};

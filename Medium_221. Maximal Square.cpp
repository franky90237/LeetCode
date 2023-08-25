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

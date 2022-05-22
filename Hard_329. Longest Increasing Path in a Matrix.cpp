//2022-05-23
//time. : O(m*n)
//space : O(m*n)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=1;
        for(int r=0; r<m ; ++r)
        {            
            for(int c=0; c<n ; ++c)
            {
                res=max(res,solve(dp,matrix,r,c,-1));
            }
            //cout<<endl<<endl;
        }
        
        return res;
    }
    
    int solve(vector<vector<int>>& dp, vector<vector<int>>& matrix, int r, int c, int pre)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n || matrix[r][c]<0) return 0;
        //cout<<matrix[r][c]<<" "<<r<<" "<<c<<" - "<<pre<<endl;
        if(matrix[r][c]<=pre) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        
        
        int dir[5]={0,1,0,-1,0};
        int max_len=0;
        for(int i=1; i<5; ++i)
        {
            int r_next=r+dir[i-1];
            int c_next=c+dir[i];
            
            matrix[r][c]=-matrix[r][c];
            
            int len=1+solve(dp,matrix,r_next,c_next,-matrix[r][c]);
            max_len=max(max_len,len);
            //cout<<len<<" ";
            matrix[r][c]=-matrix[r][c];
        }
        
        dp[r][c]=max_len;
        return max_len;     
    }
};

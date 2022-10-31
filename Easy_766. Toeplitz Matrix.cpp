//2022-11-01
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int r=m-1; r>=0; --r)
        {
            //cout<<r<<endl;
            int val=matrix[r][0];
            int i=r;
            int k=0;
            while(i < m && k < n)
            {
                if(matrix[i][k] != val) return false;
                ++i;
                ++k;
            }
        }
        
        for(int c=1; c<n-1; ++c)
        {
            //cout<<c<<endl;
            int val=matrix[0][c];
            int i=0;
            int k=c;
            while(i < m && k < n)
            {
                if(matrix[i][k] != val) return false;
                ++i;
                ++k;
            }
        }
                
        return true;
    }
};

//2022-11-01
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int r=0; r<m-1; ++r)
        {
            for(int c=0; c<n-1; ++c)
            {
                if(matrix[r][c] != matrix[r+1][c+1]) return false;
            }
        }
                
        return true;
    }
};

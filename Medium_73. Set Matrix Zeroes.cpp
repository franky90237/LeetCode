//2022-04-26
//time  : O(m*n)
//space : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_set<int> row;
        unordered_set<int> column;
        
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        
        for(auto& r:row)
        {
            for(int c=0; c<n; ++c) matrix[r][c]=0;
        }
        
        for(auto& c:column)
        {
            for(int r=0; r<m; ++r) matrix[r][c]=0;
        }
    }
};

//2022-04-26
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        bool is_column0=false;
        bool is_row0=false;
        
        if(matrix[0][0]==0)
        {
            is_column0=true;
            is_row0=true;
        }
        else
        {
            for(int c=1; c<n; ++c)
            {
                if(matrix[0][c]==0) 
                {
                    is_row0=true;
                    break;
                }
            }
        
            for(int r=1; r<m; ++r)
            {
                if(matrix[r][0]==0) 
                {
                    is_column0=true;
                    break;
                }
            }
        }
        
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        //for first row
        if(is_row0)
        {
            for(int c=0; c<n; ++c) matrix[0][c]=0;
        }
        
        //for first column
        if(is_column0)
        {
            for(int r=0; r<m; ++r) matrix[r][0]=0;
        }
    }
};

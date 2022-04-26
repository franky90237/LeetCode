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

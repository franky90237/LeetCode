//2022-06-14
//TLE
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        return solve(0,0,triangle);
    }
    
    int solve(int row, int column, vector<vector<int>>& triangle)
    {
        int m=triangle.size();
        if(row==m) return 0;
        
        int n=triangle[row].size();                
        if(column==n) return 0;
        
        int sum1=triangle[row][column]+solve(row+1,column,triangle);
        int sum2=triangle[row][column]+solve(row+1,column+1,triangle);
        
        return min(sum1,sum2);
    }
};

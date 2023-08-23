//2023-08-24
//TLE
//time  : O(mn*mn*mn)
//space : O(1)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;        
        for(int length=1; length<=n; ++length)
        {
            for(int width=1; width<=m; ++width)
            {
                int area=cal(matrix, length, width);
                ans=max(ans, area);
            }
        }
        
        return ans;
    }
    
    int cal(vector<vector<char>>& matrix, int length, int width)
    {
        int m=matrix.size();
        int n=matrix[0].size();    
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(checkAllOnes(matrix, r, c, length, width)) 
                {
                    //cout<<r<<" "<<c<<" | "<<length<<" "<<width<<endl;
                    return length*width;
                }
            }
        }
        
        return 0;
    }
    
    bool checkAllOnes(vector<vector<char>>& matrix, int x, int y, int length, int width)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if(y+length > n || x+width > m) return false;
                
        for(int r=x; r<x+width; ++r)
        {
            for(int c=y; c<y+length; ++c)
            {
                //cout<<r<<" "<<c<<" | "<<matrix[r][c]<<endl;
                if(matrix[r][c] == '0') return false;
            }
        }
                
        return true;
    }
};

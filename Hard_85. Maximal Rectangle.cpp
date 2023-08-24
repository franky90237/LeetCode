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

//2023-08-24
//time  : O(m*n*m)
//space : O(m*n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> rightOnes(m, vector<int>(n, 0));
        for(int r=0; r<m; ++r)
        {
            rightOnes[r][n-1]=matrix[r][n-1]-'0';
            for(int c=n-2; c>=0; --c)
            {
                if(matrix[r][c] == '1')
                {
                    rightOnes[r][c]=1+rightOnes[r][c+1];
                }
                //cout<<rightOnes[r][c]<<" ";
            }
            //cout<<endl;
        }
        
        int ans=0;
        for(int r=0; r<m; ++r)
        {                                  
            for(int c=0; c<n; ++c)
            {
                //if(matrix[r][c] == '0') continue;
                
                int length=rightOnes[r][c];
                int i=r;
                for(; i<m; ++i)
                {
                    if(matrix[i][c] == '0') break;
                    length=min(length, rightOnes[i][c]);
                    ans=max(ans, length*(i-r+1));
                }
                
                //cout<<length*(i-r)<<" ";
                //ans=max(ans, length*(i-r));
            }
            //cout<<endl;
        }
                
        return ans;
    }
};

//2022-09-15
//time  : O(m*n)
//space : O(max(m,n))
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if(image[sr][sc]==color) return image;
        
        dfs(image,sr,sc,image[sr][sc],color);        
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int source, int color)
    {
        int m=image.size();
        int n=image[0].size();
        
        //cout<<r<<" "<<c<<endl;
        if(r<0 || r>=m || c<0 || c>=n || image[r][c]!=source) return;
        
        image[r][c]=color;
        
        dfs(image,r-1,c,source,color);
        dfs(image,r+1,c,source,color);
        dfs(image,r,c-1,source,color);
        dfs(image,r,c+1,source,color);
    }
};

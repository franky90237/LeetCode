//dfs recursive
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)  
    {        
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        
        dfs(image,visited,sr,sc,image[sr][sc],newColor);
        
        return image;
    }
    
    void dfs(vector<vector<int>>& image, vector<vector<int>> visited, int sr, int sc, int sColor, int newColor)
    {
        int r_size=image.size();
        int c_size=image[0].size();
                
        //cout<<sr<<" "<<sc<<endl;
        
        if(r_size<=sr || sr<0 || c_size<=sc || sc<0 || visited[sr][sc]==1 ||image[sr][sc]!=sColor)
        {
            return;
        }
        
        visited[sr][sc]=1;
        image[sr][sc]=newColor;
        
        dfs(image,visited,sr+1,sc,sColor,newColor);
        dfs(image,visited,sr-1,sc,sColor,newColor);
        dfs(image,visited,sr,sc+1,sColor,newColor);
        dfs(image,visited,sr,sc-1,sColor,newColor);                       
    }
};

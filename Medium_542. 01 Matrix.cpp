//TLE
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        
        for(int i=0; i<mat.size(); ++i)
        {
            for(int j=0; j<mat[0].size(); ++j)
            {
                //if(mat[i][j]==0) visited[i][j]=1;
                if(mat[i][j]!=0) bfs(mat,i,j);
            }
        }
        
        return mat;
    }
    
    void bfs(vector<vector<int>>& mat, int r, int c)
    {
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),-1));
        
        bool flag=0;
        int dir[]={0,1,0,-1,0};
        queue<pair<int,int>> q;
        int step=0;
        
        q.push(pair<int,int>(r,c));
        while(!q.empty())
        {
            ++step;
            int size=q.size();
            for(int cnt=0; cnt<size ; ++cnt)
            {
            //++step;
            if((r-1>=0 && step>=mat[r-1][c]+1) || (c-1>=0 && step>=mat[r][c-1]+1))
            {
                flag=1;
                mat[r][c]=step;
                return;
                break;
            }
            
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            visited[row][col]=1;
            
            for(int i=0; i<4; ++i)
            {
                int new_row=row+dir[i];
                int new_col=col+dir[i+1];
                
                //if(new_row<=r || new_col<=c) continue;
                
                if(new_row>=0 && new_row<mat.size() && new_col>=0 && new_col<mat[0].size() && visited[new_row][new_col]!=1)
                {
                    if(mat[new_row][new_col]==0)
                    {
                        
                        mat[r][c]=step;
                        return;
                    }
                    q.push(pair<int,int>(new_row,new_col));
                    visited[new_row][new_col]=1;
                }
            }               
            }

            
        }
        //if(flag) cout<<step<<" ";     
        if(r-1>=0) step=min(step,mat[r-1][c]+1);
        if(c-1>=0) step=min(step,mat[r][c-1]+1);
        //if(flag) cout<<step<<endl;
        mat[r][c]=step;
    }
};

//bfs from zero
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[0].size();++j)
            {
                if(mat[i][j]==0) 
                {
                    res[i][j]=0;
                    q.emplace(i,j);
                }
            }
        }
        
        int dir[]={0,1,0,-1,0};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0; i<4; ++i)
            {
                int n_r=r+dir[i];
                int n_c=c+dir[i+1];
                
                if(n_r>=0 && n_r<m && n_c>=0 && n_c<n)
                {
                    if(res[n_r][n_c]==-1 || res[n_r][n_c]>res[r][c]+1)
                    {
                        res[n_r][n_c]=res[r][c]+1;
                        q.emplace(n_r,n_c);
                    }
                }
            }
        }
        
        return res;
    }
};

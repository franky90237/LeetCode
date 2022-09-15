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

//dynamic programming
//left to right, up to down
//right to left, down to up
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size(), n=mat[0].size();
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(mat[i][j]!=0) 
                {
                    mat[i][j]=m+n;
                }
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(mat[i][j]!=0) 
                {
                    if(i-1>=0) 
                    {
                        mat[i][j]=min(mat[i][j],mat[i-1][j]+1);
                    }
                    if(j-1>=0) 
                    {
                        mat[i][j]=min(mat[i][j],mat[i][j-1]+1);
                    }
                }
            }
        }
        
        for(int i=m-1; i>=0; --i)
        {
            for(int j=n-1; j>=0; --j)
            {
                if(mat[i][j]!=0) 
                {
                    if(i+1<m) 
                    {
                        mat[i][j]=min(mat[i][j],mat[i+1][j]+1);
                    }
                    if(j+1<n)
                    {
                        mat[i][j]=min(mat[i][j],mat[i][j+1]+1);
                    }
                }
            }
        }
        
        return mat;
    }
};

//2022-09-15
//TLE
//time  : O((m*n)^2)
//space : O(m*n)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n));        
        
        for(int r=0; r<m; ++r)    
        {
            for(int c=0; c<n; ++c)
            {
                if(mat[r][c] != 0)
                {
                    ans[r][c]=bfs(mat,r,c);
                }              
            }            
        }
            
        return ans;
    }
    
    int bfs(vector<vector<int>> mat, int r, int c)
    {
        int m=mat.size();
        int n=mat[0].size();
        
        queue<vector<int>> q;
        q.push({r,c});
        mat[r][c]=2;        
        
        int dir[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
        int distance=0;
        while(!q.empty())
        {
            ++distance;
            
            int size=q.size();
            while(size>0)
            {
                int row=q.front()[0];
                int col=q.front()[1];
                q.pop();
                
                for(int i=0; i<4; ++i)
                {
                    int new_row=row+dir[i][0];
                    int new_col=col+dir[i][1];
                    
                    if(new_row<0 || new_row>=m || new_col<0 || new_col>=n) continue;
                    if(mat[new_row][new_col]==0) return distance;

                    if(mat[new_row][new_col]!=2)
                    {                                                    
                        q.push({new_row,new_col});
                        mat[new_row][new_col]=2;
                    }
                }
                
                --size;
            }
        }
        
        return distance;
    }
};

//2022-09-15
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n,-1));        
        
        queue<vector<int>> q;
        
        for(int r=0; r<m; ++r)    
        {
            for(int c=0; c<n; ++c)
            {
                if(mat[r][c] == 0)
                {
                    ans[r][c]=0;
                    q.push({r,c});
                }
            }
        }
        
        int dir[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty())
        {                  
            int r=q.front()[0];
            int c=q.front()[1];
            q.pop();

            for(int i=0; i<4; ++i)
            {
                int new_r=r + dir[i][0];
                int new_c=c + dir[i][1];

                if(new_r<0 || new_r>=m || new_c<0 || new_c>=n) continue;
                
                if(ans[new_r][new_c]==-1)
                {
                    ans[new_r][new_c]=ans[r][c]+1;
                    q.push({new_r,new_c});
                }
            }                       
        }        
            
        return ans;
    }
};

//2022-09-15
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, m+n));
        
        for(int r=0; r<m; ++r)    
        {
            for(int c=0; c<n; ++c)
            {
                if(mat[r][c] != 0)
                {                    
                    if(r-1>=0) ans[r][c]=min(ans[r][c], ans[r-1][c] + 1);
                    if(c-1>=0) ans[r][c]=min(ans[r][c], ans[r][c-1] + 1);                   
                }
                else
                {
                    ans[r][c]=0;
                }
            }
        }
        
        for(int r=m-1; r>=0; --r)    
        {
            for(int c=n-1; c>=0; --c)
            {
                if(mat[r][c] != 0)
                {
                    if(r+1<m) ans[r][c]=min(ans[r][c], ans[r+1][c] + 1);
                    if(c+1<n) ans[r][c]=min(ans[r][c], ans[r][c+1] + 1);
                }
                else
                {
                    ans[r][c]=0;
                }                
            }
        }        
                    
        return ans;
    }
};

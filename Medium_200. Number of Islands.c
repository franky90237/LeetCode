class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        unordered_set<int> s;
        int row=0;
        int col=0;
        int number_of_islands=0;
        
        for(int row=0;row<m;++row)
        {
            for(int col=0;col<n;++col)
            {                
                if(grid[row][col]=='1' && s.find(row*n+col)==s.end())
                {
                    //cout<<row<<" "<<col<<endl;
                    s.insert(row*n+col);
                    
                    queue<int> q;
                    q.push(row*n+col);
                    while(!q.empty())
                    {
                        int row_now=q.front()/n;
                        int col_now=q.front()%n;                        
                        q.pop();
                        
                        //up side
                        if(row_now+-1>=0 && s.find((row_now-1)*n+col_now)==s.end() && \
                           grid[row_now-1][col_now]=='1')
                        {
                            q.push((row_now-1)*n+col_now);
                            s.insert((row_now-1)*n+col_now);
                        }                        
                        
                        //down side
                        if(row_now+1<m && s.find((row_now+1)*n+col_now)==s.end() && \
                           grid[row_now+1][col_now]=='1')
                        {
                            q.push((row_now+1)*n+col_now);
                            s.insert((row_now+1)*n+col_now);
                        }
                        
                        //right side
                        if(col_now+1<n && s.find(row_now*n+col_now+1)==s.end() && \
                           grid[row_now][col_now+1]=='1')
                        {
                            q.push(row_now*n+col_now+1);
                            s.insert(row_now*n+col_now+1);
                        }
                        
                        //left side
                        if(col_now-1>=0 && s.find(row_now*n+col_now-1)==s.end() && \
                           grid[row_now][col_now-1]=='1')
                        {
                            q.push(row_now*n+col_now-1);
                            s.insert(row_now*n+col_now-1);
                        }
                    }
                    
                    ++number_of_islands;
                }
            }
        }
        
        return number_of_islands;
    }
};

//DFS iterative
//DFS recursive
//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int row_size=grid.size();
        int col_size=grid[0].size();
        int islands=0;
        
        for(int r=0;r<row_size;++r)
        {
            for(int c=0;c<col_size;++c)
            {                
                if(grid[r][c]=='1')
                {
                    //cout<<r<<" "<<c<<endl;
                    dfs_iterative(grid,r,c);
                    //dfs_recursive(grid,r,c);
                    //bfs(grid,r,c);
                    ++islands;
                }
            }
        }
        
        return islands;                
    }
    
    void dfs_iterative(vector<vector<char>>& grid, int r, int c)        
    {
        stack<pair<int,int>> s;
        int direction[]={1,0,-1,0,1};
        
        s.push(pair<int,int>(r,c));
        while(!s.empty())
        {
            r=s.top().first;
            c=s.top().second;
            s.pop();
            grid[r][c]='X';
            
            for(int i=0;i<4;++i)
            {
                int r_next=r+direction[i];
                int c_next=c+direction[i+1];
                
                if(r_next>=0 && c_next>=0 && r_next<grid.size() && c_next<grid[0].size() && \
                   grid[r_next][c_next]=='1')
                {                    
                    s.push(pair<int,int>(r_next,c_next));
                    //grid[r][c]='X';
                }
            }
        }
    }
    
    void dfs_recursive(vector<vector<char>>& grid, int r, int c)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!='1')
        {
            return;
        }
        
        grid[r][c]='X';
        
        dfs_recursive(grid,r+1,c);
        dfs_recursive(grid,r-1,c);
        dfs_recursive(grid,r,c+1);
        dfs_recursive(grid,r,c-1);
    }
    
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue<pair<int,int>> q;
        int direction[]={1,0,-1,0,1};
        
        q.push(pair<int,int>(r,c));
        grid[r][c]='X';
        while(!q.empty())
        {
            r=q.front().first;
            c=q.front().second;
            q.pop();
            //grid[r][c]='X';
            
            for(int i=0;i<4;++i)
            {
                int r_next=r+direction[i];
                int c_next=c+direction[i+1];
                
                if(r_next>=0 && c_next>=0 && r_next<grid.size() && c_next<grid[0].size() && \
                   grid[r_next][c_next]=='1')
                {                    
                    q.push(pair<int,int>(r_next,c_next));
                    grid[r_next][c_next]='X';
                }
            }
        }        
    }
};

//2022-09-12
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c]=='1')
                {
                    //cout<<r<<" "<<c<<endl;
                    bfs(r,c,grid);
                    ++ans;
                }
            }
        }
        
        return ans;
    }
    
    void bfs(int r, int c, vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<vector<int>> q;
        q.push({r,c});
        grid[r][c]='v';
        
        while(!q.empty())
        {
            int row=q.front()[0];
            int col=q.front()[1];
            q.pop();
            
            if(row-1>=0 && grid[row-1][col]=='1') 
            {
                q.push({row-1,col});
                grid[row-1][col]='v';
            }
            
            if(row+1<m && grid[row+1][col]=='1') 
            {
                q.push({row+1,col});
                grid[row+1][col]='v';
            }
            
            if(col-1>=0 && grid[row][col-1]=='1') 
            {
                q.push({row,col-1});
                grid[row][col-1]='v';
            }
            
            if(col+1<n && grid[row][col+1]=='1') 
            {
                q.push({row,col+1});
                grid[row][col+1]='v';
            }
        }
        
    }
};

//2022-09-12
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c]=='1')
                {
                    //cout<<r<<" "<<c<<endl;
                    dfs(r,c,grid);
                    ++ans;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]!='1') return;
        
        grid[r][c]='v';
        
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
};

//2022-09-12
//time  : O(m*n)
//space : O(m*n)
class union_find
{
private:
    vector<int> parent;
    vector<int> size;    
    
public:
    int count=0;
    
    union_find(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        parent.resize(m*n);
        size.resize(m*n,1);
        
        for(int i=0; i<m*n; ++i)
        {
            if(grid[i/n][i%n]=='1')
            {
                ++count;
                parent[i]=i;
            }
            else
            {
                parent[i]=-1;
            }
        }
    }
    
    void combine(int a, int b)
    {
        int root_a=find(a);
        int root_b=find(b);
        
        if(root_a==root_b) return;
        
        if(size[a]>=size[b])
        {
            parent[root_b]=root_a;
            size[root_a]+=size[root_b];
        }
        else
        {
            parent[root_a]=root_b;
            size[root_b]+=size[root_a];            
        }
        
        --count;
    }
    
    int find(int a)
    {
        if(parent[a]==a) return a;
        
        parent[a]=find(parent[a]);
        return parent[a];
    }
    
    /*int get_total_group_size()
    {               
        int ans=0;
        vector<bool> visited(parent.size(),false);        
        
        for(int i=0; i<parent.size(); ++i)
        {
            if(parent[i]==-1) continue;
            
            int root=find(i);
            if(!visited[root]) 
            {
                ++ans;
                visited[root]=true;
            }            
        }
        
        return ans;
    }*/
    
    void print(int n)
    {
        for(int i=0; i<parent.size(); ++i)
        {
            if(i%n==0) cout<<endl;
            if(parent[i]!=-1) cout<<find(i)<<" ";            
            else cout<<-1<<" ";
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        union_find uf(grid);               
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(grid[r][c]=='1')
                {
                    //cout<<r*n+c<<endl;
                    
                    if(r-1>=0 && grid[r-1][c]=='1') uf.combine(r*n+c,(r-1)*n+c);
                    if(r+1<m && grid[r+1][c]=='1') uf.combine(r*n+c,(r+1)*n+c);
                    if(c-1>=0 && grid[r][c-1]=='1') uf.combine(r*n+c,r*n+c-1);                    
                    if(c+1<n && grid[r][c+1]=='1') uf.combine(r*n+c,r*n+c+1);
                }
            }
        }
        
        //uf.print(n);
        return uf.count;
    }
};

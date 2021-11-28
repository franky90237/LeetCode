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
                    cout<<r<<" "<<c<<endl;
                    dfs(grid,r,c,row_size,col_size);
                    ++islands;
                }
            }
        }
        
        return islands;                
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c, int row_size, int col_size)        
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
                
                if(r_next>=0 && c_next>=0 && r_next<row_size && c_next<col_size && grid[r_next][c_next]=='1')
                {                    
                    s.push(pair<int,int>(r_next,c_next));                    
                }
            }
        }
    }
};

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

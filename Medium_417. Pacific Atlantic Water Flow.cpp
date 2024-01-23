//2022-06-10
//dfs
class Solution 
{
private:
    enum state{NOT_VISITED, NOTHING, LEFT_UP, RIGHT_DOWN, LEFT_UP_RIGHT_DOWN};
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>> ans;
        vector<vector<int>> visited(m,vector<int>(n,NOT_VISITED));
        for(int i=0; i<m; ++i)            
        {            
            for(int j=0; j<n; ++j)
            {
                //cout<<i<<" : "<<j<<endl;
                
                set<int> res=dfs(i,j,heights,visited);
                if(res.size()==2) 
                {                    
                    ans.push_back({i,j});
                    visited[i][j]=LEFT_UP_RIGHT_DOWN;                    
                }
                else if(res.size()==1)
                {
                    if(*(res.begin())==1) visited[i][j]=LEFT_UP;
                    else visited[i][j]=RIGHT_DOWN;
                }
                else visited[i][j]=NOTHING;
                
                //cout<<endl;
            }            
        }
        
        return ans;
    }
    
    set<int> dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& visited)
    {
        int m=heights.size();
        int n=heights[0].size();
        
        //cout<<r<<" "<<c<<endl;
        
        if(visited[r][c]==NOTHING) return set<int>();
        else if(visited[r][c]==LEFT_UP)  return set<int>({1});
        else if(visited[r][c]==RIGHT_DOWN)  return set<int>({2});
        else if(visited[r][c]==LEFT_UP_RIGHT_DOWN)  return set<int>({1,2});                
                
        set<int> side;
        int dir[5]={0,1,0,-1,0};
        for(int i=1; i<5; ++i)
        {
            int r_n=r+dir[i-1];
            int c_n=c+dir[i];
            
            if(r_n<0 || c_n<0) side.insert(1);
            else if(r_n>=m || c_n>=n) side.insert(2);            
            else if(heights[r_n][c_n]<=heights[r][c]) 
            {
                heights[r][c]+=100001;
                
                set<int> tmp=dfs(r_n,c_n,heights,visited);
                side.insert(tmp.begin(),tmp.end());                
                
                heights[r][c]-=100001;
            }
            
            if(side.size()==2) break;
        }
        
        if(side.size()==2) visited[r][c]=LEFT_UP_RIGHT_DOWN;        
        
        //cout<<endl;
        return side;
    }
};

//2022-06-13
//bfs two pass
class Solution 
{   
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>> pacific(m,vector<int>(n,0));
        vector<vector<int>> atlantic(m,vector<int>(n,0));
        
        queue<vector<int>> pQ,aQ;
        
        for(int i=0; i<m; ++i)            
        {
            pacific[i][0]=1;
            atlantic[i][n-1]=1;
            
            pQ.push({i,0});
            aQ.push({i,n-1});
        }
                                     
        for(int i=0; i<n; ++i)       
        {
            pacific[0][i]=1;
            atlantic[m-1][i]=1;
            
            pQ.push({0,i});
            aQ.push({m-1,i});
        }
        
        bfs(pQ,heights,pacific);
        bfs(aQ,heights,atlantic);
        
        //print_v(pacific);
        //print_v(atlantic);
        
        vector<vector<int>> ans;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        
        return ans;
    }
    
    void bfs(queue<vector<int>>& q, vector<vector<int>>& heights, vector<vector<int>>& visited)
    {
        int m=heights.size();
        int n=heights[0].size();
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int r=q.front()[0];
            int c=q.front()[1];
            q.pop();
            
            
            for(int i=0; i<4; ++i)
            {
                int r_n=r+dir[i][0];
                int c_n=c+dir[i][1];
                
                if(r_n<0 || r_n>=m || c_n<0 || c_n>=n || visited[r_n][c_n])
                {
                    continue;
                }
                
                if(heights[r_n][c_n]>=heights[r][c])
                {
                    visited[r_n][c_n]=true;
                    q.push(vector<int>({r_n,c_n}));
                }
            }
        }
    }
    
    void print_v(vector<vector<int>>& v)
    {
        int m=v.size();
        int n=v[0].size();
        
        cout<<m<<":"<<n<<endl;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

//2024-01-23
//time  : O(m*n)
//spcae : O(m*n)
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<bool>> goP(m, vector<bool>(n, false));
        vector<vector<bool>> goA(m, vector<bool>(n, false));
        
        for(int r=0; r<m; ++r)
        {
            dfs(heights, goP, heights[r][0], r, 0);
            dfs(heights, goA, heights[r][n-1], r, n-1);
        }
        
        for(int c=0; c<n; ++c)
        {
            dfs(heights, goP, heights[0][c], 0, c);
            dfs(heights, goA, heights[m-1][c], m-1, c);
        }
        
        vector<vector<int>> res;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {                
                if(goP[i][j] && goA[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& go, int pre, int i, int j)
    {
        int m=heights.size();
        int n=heights[0].size();
        
        if(i < 0 || i >= m || j < 0 || j >= n || go[i][j] || pre > heights[i][j]) return ;
        
        go[i][j]=true;
        
        dfs(heights, go, heights[i][j], i+1, j);
        dfs(heights, go, heights[i][j], i-1, j);
        dfs(heights, go, heights[i][j], i, j+1);
        dfs(heights, go, heights[i][j], i, j-1);
    }
};

//2024-01-23
//time  : O(m*n)
//spcae : O(m*n)
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<bool>> goP(m, vector<bool>(n, false));
        vector<vector<bool>> goA(m, vector<bool>(n, false));
        
        queue<vector<int>> qP;
        queue<vector<int>> qA;
        
        for(int r=0; r<m; ++r)
        {
            goP[r][0]=true;
            qP.push({r, 0});
            
            goA[r][n-1]=true;
            qA.push({r, n-1});
        }
        
        for(int c=0; c<n; ++c)
        {
            goP[0][c]=true;
            qP.push({0, c});
            
            goA[m-1][c]=true;
            qA.push({m-1, c});
        }
        
        bfs(heights, goP, qP);
        bfs(heights, goA, qA);
        
        vector<vector<int>> res;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {                
                if(goP[i][j] && goA[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
    
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& go, queue<vector<int>> q)
    {
        int m=heights.size();
        int n=heights[0].size();
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while(!q.empty())
        {
            int r=q.front()[0];
            int c=q.front()[1];            
            q.pop();
            
            for(int i=0; i<4; ++i)
            {
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || go[nr][nc] || heights[r][c] > heights[nr][nc]) continue;
                go[nr][nc]=true;
                q.push({nr, nc});
            }
        }
    }
};

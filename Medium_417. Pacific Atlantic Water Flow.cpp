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

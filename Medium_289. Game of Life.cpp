//2022-04-26
//time  : O(m*n)
//space : O(m)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m=board.size();
        int n=board[0].size();
        
        vector<int> state(n+1,-1);
        
        for(int i=0; i<m; ++i)
        {
            vector<bool> old_state(m);
            
            for(int j=0; j<n; ++j)
            {
                int ones=neighbor_ones(board,state,i,j);
                //cout<<i<<"-"<<j<<"  "<<ones<<endl;
                
                state[state.size()-1]=board[i][j];
                old_state[j]=board[i][j];
                next_state(board[i][j],ones);                 
            }
            
            for(int idx=0; idx<n; ++idx)
            {
                state[idx]=old_state[idx];
            }
        }
                                
    }
    
    int neighbor_ones(vector<vector<int>>& board, vector<int>& state, int r, int c)
    {
        int m=board.size();
        int n=board[0].size();
        
        int ones=0;
        
        if(c!=0 && state.back()==1) ++ones;
        
        if(r-1>=0)
        {
            for(int i=c-1; i<=c+1 && i<n; ++i)
            {
                if(i<0) continue;
                if(state[i]==1) ++ones;
            }
        }
        
        if(c+1<n && board[r][c+1]==1) ++ones;
        
        if(r+1<m)
        {
            for(int i=c-1; i<=c+1 && i<n; ++i)
            {
                if(i<0) continue;
                if(board[r+1][i]==1) ++ones;
            }
        }
        
        return ones;
    }
    
    void next_state(int& curr_state, int ones)
    {
        if(curr_state==0)
        {
            if(ones==3) 
            {
                curr_state=1;
            }
        }
        else
        {
            if(ones<=1 || ones>=4) 
            {
                curr_state=0;
            }
        }
    }
};

//2022-04-26
//if 1 will change to 0, we change 1 to 2
//if 0 will change to 1, we change 0 to -1
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m=board.size();
        int n=board[0].size();        
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                int ones=neighbor_ones(board,i,j);
                next_state(board[i][j],ones);
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j]==-1) board[i][j]=0;
                else if(board[i][j]==2) board[i][j]=1;
            }
        }
    }
    
    int neighbor_ones(vector<vector<int>>& board, int r, int c)
    {
        int m=board.size();
        int n=board[0].size();
        
        int ones=0;
        
        if(c-1>=0 && (board[r][c-1]==1 || board[r][c-1]==-1)) ++ones;
        
        if(r-1>=0)
        {
            for(int i=c-1; i<=c+1 && i<n; ++i)
            {
                if(i<0) continue;
                if(board[r-1][i]==1 || board[r-1][i]==-1) ++ones;
            }
        }
        
        if(c+1<n && (board[r][c+1]==1 || board[r][c+1]==-1)) ++ones;
        
        if(r+1<m)
        {
            for(int i=c-1; i<=c+1 && i<n; ++i)
            {
                if(i<0) continue;
                if(board[r+1][i]==1 || board[r+1][i]==-1) ++ones;
            }
        }
        
        return ones;
    }
    
    void next_state(int& curr_state, int ones)
    {
        if(curr_state==0)
        {
            if(ones==3) curr_state=2;
        }
        else
        {
            if(ones<2 || ones>3) curr_state=-1;
        }
    }
};

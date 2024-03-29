//2022-10-06
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int r=0; r<m; ++r)
        {
            if(r==0 || r==m-1)
            {
                for(int c=0; c<n; ++c)
                {                    
                    dfs(board, visited, r, c);
                }
            }
            else
            {
                dfs(board, visited, r, 0);
                dfs(board, visited, r, n-1);
            }
        }
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(board[r][c] == 'Y')
                {
                    board[r][c]='O';
                }                
                else if(board[r][c] == 'O')
                {
                    board[r][c]='X';
                }
            }
        }            
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c)
    {
        int m=board.size();
        int n=board[0].size();
        
        if(r >= m || r < 0 || c >= n || c < 0) return;
        if(visited[r][c] || board[r][c] != 'O') return;
        
        visited[r][c]=true;
        board[r][c]='Y';        
        dfs(board, visited, r-1, c);
        dfs(board, visited, r+1, c);
        dfs(board, visited, r, c-1);
        dfs(board, visited, r, c+1);
    }
};

//2022-10-06
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size();
        int n=board[0].size();
        //vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int r=0; r<m; ++r)
        {
            if(r==0 || r==m-1)
            {
                for(int c=0; c<n; ++c)
                {                    
                    dfs(board, r, c);
                }
            }
            else
            {
                dfs(board, r, 0);
                dfs(board, r, n-1);
            }
        }
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(board[r][c] == 'Y')
                {
                    board[r][c]='O';
                }                
                else if(board[r][c] == 'O')
                {
                    board[r][c]='X';
                }
            }
        }            
    }
    
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        int m=board.size();
        int n=board[0].size();
        
        if(r >= m || r < 0 || c >= n || c < 0 || board[r][c]!='O') return;    
                
        board[r][c]='Y';        
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r, c-1);
        dfs(board, r, c+1);
    }
};

//2024-01-23
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size();
        int n=board[0].size();
        
        for(int r=0; r<m; ++r)
        {
            if(board[r][0] == 'O') dfs(board, r, 0);
            if(board[r][n-1] == 'O') dfs(board, r, n-1);
        }
        
        for(int c=0; c<n; ++c)
        {
            if(board[0][c] == 'O') dfs(board, 0, c);
            if(board[m-1][c] == 'O') dfs(board, m-1, c);
        }
        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(board[r][c] == 'O') board[r][c]='X';
                else if(board[r][c] == 'V') board[r][c]='O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        int m=board.size();
        int n=board[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        
        board[r][c]='V';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};

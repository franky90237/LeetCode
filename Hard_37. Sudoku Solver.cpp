//backtracking
class Solution {
private:
    void print_vector(vector<vector<char>>& v)
    {
        int n=8;
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j)
            {
                printf("%c ",v[i][j]);
            }
            cout<<endl;
        }
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) 
    {        
        int n=9;
        
        vector<vector<int>> row(n,vector<int>(n+1,0));
        vector<vector<int>> column(n,vector<int>(n+1,0));
        vector<vector<int>> block(n,vector<int>(n+1,0));        
        for(int i=0; i<n; ++i)
        {
           for(int j=0; j<n; ++j)
           {               
               if(board[i][j]!='.')
               {                   
                   int num=board[i][j]-'0';
                   row[i][num]=1;
                   column[j][num]=1;
                   block[(i/3)*3+j/3][num]=1;                   
               }
           }
        }
        
        solve(0,0,board,row,column,block);
        //print_vector(board);
    }
    
    bool solve(int r, int c, vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& column, vector<vector<int>>& block)
    {
        int n=9;
        
        if(r>=n) return true;
        
        while(board[r][c]!='.')
        {
            if(c+1<n) ++c;
            else
            {
                ++r;
                c=0;
            }
            
            if(r>=n) return true;
        }                
        
        for(int i=1; i<=n; ++i)
        {
            if(is_valid(i,r,c,board,row,column,block))
            {
                //cout<<r<<" " <<c<<" - "<<i<<endl;
                place(i,r,c,board,row,column,block);

                bool res=false;
                if(c+1<n) res=solve(r,c+1,board,row,column,block);
                else      res=solve(r+1,0,board,row,column,block);
                if(res==true) return res;
                
                remove(i,r,c,board,row,column,block);
            }
        }
                
        return false;
    }
    
    bool is_valid(int num, int r, int c, vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& column, vector<vector<int>>& block)
    {                
        int n=9;
        
        int b=(r/3)*3+c/3;
        if(row[r][num]!=0 || column[c][num]!=0 || block[b][num]!=0)
        {
            return false;
        }
        return true;
    }
    
    void place(int num, int r, int c, vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& column, vector<vector<int>>& block)
    {
        board[r][c]=num+'0';
        
        row[r][num]=1;
        column[c][num]=1;
        block[(r/3)*3+c/3][num]=1;
    }
    
    void remove(int num, int r, int c, vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& column, vector<vector<int>>& block)
    {
        board[r][c]='.';
        
        row[r][num]=0;
        column[c][num]=0;
        block[(r/3)*3+c/3][num]=0;
    }
};

/*class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        unordered_set<int> row[9];
        unordered_set<int> column[9];
        unordered_set<int> block[9];
        
        solve(0,0,board,row,column,block);
    }
    
    bool solve(int r, int c, vector<vector<char>>& board, unordered_set<int> row[], unordered_set<int> column[], unordered_set<int> block[])
    {
        int n=9;
        
        while(board[r][c]!='.')
        {
            if(c+1<n) ++c;
            else
            {
                ++r;
                c=0;
            }
        }
        
        if(r>=n) return true;
        
        for(int i=0; i<=n; ++i)
        {
            //cout<<r<<" " <<c<<endl;

            if(is_valid(i,r,c,board,row,column,block))
            {
                //cout<<r<<" " <<c<<endl;
                place(i,r,c,board,row,column,block);

                bool res=false;
                if(c+1<n) res=solve(r,c+1,board,row,column,block);
                else res=solve(r+1,0,board,row,column,block);
                if(res==true) return res;

                remove(i,r,c,board,row,column,block);
            }
        }
        
        
        return false;
    }
    
    bool is_valid(int num, int r, int c, vector<vector<char>>& board, unordered_set<int> row[], unordered_set<int> column[], unordered_set<int> block[])
    {                
        int n=9;
        
        if(row[r].empty())
        {
            for(int i=0; i<n; ++i) if(board[r][i]!='.') row[r].insert(board[r][i]-'0');
        }
        
        if(column[c].empty())
        {
            for(int i=0; i<n; ++i) if(board[i][c]!='.') column[c].insert(board[i][c]-'0');
        }
        
        int b=(r*3)/3+c/3;
        if(block[b].empty())
        {
            int begin_r=r-r%3;
            int begin_c=c-c%3;
            
            for(int i=begin_r; i<begin_r+3; ++i)
            {
                for(int j=begin_c; j<begin_c+3; ++j)
                    if(board[i][j]!='.') block[b].insert(board[i][j]-'0');
            }
        }
        
        
        if(row[r].count(num)!=0 || column[c].count(num)!=0 || block[b].count(num)!=0)
        {
            return false;
        }
        return true;
    }
    
    void place(int num, int r, int c, vector<vector<char>>& board, unordered_set<int> row[], unordered_set<int> column[], unordered_set<int> block[])
    {
        board[r][c]=num+'0';
        
        row[r].insert(num+'0');
        column[c].insert(num+'0');
        block[(r*3)/3+c/3].insert(num+'0');
    }
    
    void remove(int num, int r, int c, vector<vector<char>>& board, unordered_set<int> row[], unordered_set<int> column[], unordered_set<int> block[])
    {
        board[r][c]='.';
        
        row[r].erase(num-'0');
        column[c].erase(num-'0');
        block[(r*3)/3+c/3].erase(num-'0');
    }
};*/

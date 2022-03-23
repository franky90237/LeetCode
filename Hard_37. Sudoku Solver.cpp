class Solution {
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
};

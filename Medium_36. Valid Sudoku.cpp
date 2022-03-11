class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i=0; i<9; ++i)
        {
            unordered_set<char> row,col;
            for(int j=0; j<9; ++j)
            {
                if(row.count(board[i][j])>0 || col.count(board[j][i])>0) return false;
                if(board[i][j]!='.') row.insert(board[i][j]);
                if(board[j][i]!='.') col.insert(board[j][i]);
            }
        }
        
        for(int i=0; i<3; ++i)
        {
            unordered_set<char> left,mid,right;
            for(int j=i*3; j<3+i*3; ++j)
            {
                for(int k=0; k<3; ++k)
                {
                    if(left.count(board[j][k])>0 || mid.count(board[j][k+3])>0 || right.count(board[j][k+6])>0) return false;
                    if(board[j][k]!='.') left.insert(board[j][k]);
                    if(board[j][k+3]!='.') mid.insert(board[j][k+3]);
                    if(board[j][k+6]!='.') right.insert(board[j][k+6]);
                }
            }
        }
        
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        char row[10][10]={0}, col[10][10]={0}, block[10][10]={0};
        
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j]!='.')
                {
                    int val=board[i][j]-'0';
                    if(row[val][i]!=0 || col[val][j]!=0 || block[val][(i/3)*3+j/3]!=0) return false;
                    
                    row[val][i]=1;
                    col[val][j]=1;
                    block[val][(i/3)*3+j/3]=1;
                }
            }
        }
        
        return true;
    }
};

//2022-05-03
//backtracking + dfs
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<bool>> v(m,vector<bool>(n,false));
        string s="";
        
        bool isFind=false;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(board[r][c]==word[0])
                {
                    v[r][c]=true;
                    s.push_back(board[r][c]);
                    
                    isFind=solve(board,word,v,s,r,c);
                    if(isFind) return true;
                    
                    v[r][c]=false;
                    s.pop_back();
                }
            }
        }
        
        return isFind;
    }
    
    bool solve(vector<vector<char>>& board, string& word, vector<vector<bool>>& v, string& s, int r, int c)
    {
        if(s[s.size()-1]!=word[s.size()-1]) return false;
        if(s.size()==word.size()) return true;
            
        int m=board.size();
        int n=board[0].size();
        int dir[5]={0,1,0,-1,0};
        
        for(int i=1; i<5; ++i)
        {
            int rn=r+dir[i-1];
            int cn=c+dir[i];
            //cout<<board[r][c]<<"-   "<<rn<<" "<<cn<<endl;
            
            if(rn>=0 && rn<m && cn>=0 && cn<n && !v[rn][cn])
            {
                v[rn][cn]=true;
                s.push_back(board[rn][cn]);
                
                bool isFind=solve(board,word,v,s,rn,cn);
                if(isFind) return true;
                
                v[rn][cn]=false;
                s.pop_back();
            }
        }
        
        return false;
    }
};

//2022-05-03
//clear backtracking + dfs
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m=board.size();
        int n=board[0].size();
        
        bool isFind=false;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(board[r][c]==word[0])
                {                   
                    isFind=solve(board,word,0,r,c);
                    if(isFind) return true;
                }
            }
        }                
        
        return isFind;        
    }
    
    bool solve(vector<vector<char>>& board, string& word, int idx, int r, int c)
    {
        int m=board.size();
        int n=board[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n) return false;
        if(board[r][c]!=word[idx]) return false;
        if(idx==word.size()-1) return true;
        
        int dir[5]={0,1,0,-1,0};
        bool isFind=false;
        for(int i=1; i<5; ++i)
        {
            //printf("%d, %d,  %d \n",r+dir[i-1],c+dir[i],isFind);
            board[r][c]='?';
            isFind=solve(board,word,idx+1,r+dir[i-1],c+dir[i]);
            if(isFind) return true;
            board[r][c]=word[idx];

        }
        
        return false;
    }
};

//2022-11-24
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m=board.size();
        int n=board[0].size();        
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n;++c)
            {                            
                if(dfs(board, word, r, c, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int cur)
    {
        int m=board.size();
        int n=board[0].size();
        
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[cur] || board[r][c] == '*') return false;
        if(cur == word.size()-1) return true;         
        
        char tmp=board[r][c];
        board[r][c]='*';
        
        bool find=false;
        if(dfs(board, word, r-1, c, cur+1) ||
           dfs(board, word, r+1, c, cur+1) ||
           dfs(board, word, r, c-1, cur+1) ||
           dfs(board, word, r, c+1, cur+1))
        {
            find=true;
        }
        
        board[r][c]=tmp;
        return find;
    }
};

//2024-04-19
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<char>> g(m, vector<char>(n, '0'));
        
        for(auto& cur : guards) g[cur[0]][cur[1]]='G';
        for(auto& cur : walls) g[cur[0]][cur[1]]='W';
        
        for(int r=0; r<m; ++r)
        {
            bool isGuarded=false;
            for(int c=0; c<n; ++c) traverse(g, isGuarded, r, c);            
            
            isGuarded=false;
            for(int c=n-1; c>=0; --c) traverse(g, isGuarded, r, c);            
        }
        
        for(int c=0; c<n; ++c)
        {
            bool isGuarded=false;
            for(int r=0; r<m; ++r) traverse(g, isGuarded, r, c);            
            
            isGuarded=false;
            for(int r=m-1; r>=0; --r) traverse(g, isGuarded, r, c);            
        }
        
        
        int res=0;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c) if(g[r][c] == '0') ++res;
        }
        
        return res;            
    }
    
    void traverse(vector<vector<char>>& g, bool& isGuarded, int r, int c)
    {
        if(g[r][c] == 'G') 
        {
            isGuarded=true;
        }
        else if(g[r][c] == 'W')
        {
            isGuarded=false;        
        }
        else if(isGuarded)
        {
            g[r][c]='1';
        }        
    }
};

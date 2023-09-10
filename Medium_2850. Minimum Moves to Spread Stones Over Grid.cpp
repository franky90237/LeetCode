//2023-09-10
//time  : O(4^3)
//space : O(3*3*3)
class Solution 
{
private:
    vector<vector<int>> begin;
    vector<vector<int>> end;    
    
public:
    int minimumMoves(vector<vector<int>>& grid) 
    {
        for(int r=0; r<3; ++r)
        {
            for(int c=0; c<3; ++c)
            {
                if(grid[r][c] == 0) end.push_back({r, c});
                else if(grid[r][c] >= 2) begin.push_back({r, c});
            }
        }        
        if(begin.size() == 0) return 0;
        
        return solve(grid, 0, grid[begin[0][0]][begin[0][1]]);
    }
    
    int solve(vector<vector<int>>& grid, int cur, int rest)
    {
        //cout<<cur<<" | "<<rest<<endl;
        int n=begin.size();
        if(cur == n) return 0;
        
        int sr=begin[cur][0], sc=begin[cur][1];
        int res=999999;
        for(int i=0; i<end.size(); ++i)
        {
            int tr=end[i][0], tc=end[i][1];
            if(grid[tr][tc] == 1) continue;
            grid[tr][tc] = 1;
            
            int dis=abs(tr-sr)+abs(tc-sc);
            //cout<<cur<<" "<<dis<<endl;
            if(rest-1 == 1) 
            {
                if(cur+1 < n) dis += solve(grid, cur+1, grid[begin[cur+1][0]][begin[cur+1][1]]);
            }
            else 
            {
                dis += solve(grid, cur, rest-1);
            }
            res=min(res, dis);
            
            //cout<<cur<<" "<<dis<<endl;
            grid[tr][tc] = 0;
        }
        
        return res;
    }
};

//2023-09-10
//time  : O(4!)
//space : O(3*3)
class Solution {     
public:
    int minimumMoves(vector<vector<int>>& grid) 
    {
        vector<vector<int>> begin;
        vector<vector<int>> end;   
        for(int r=0; r<3; ++r)
        {
            for(int c=0; c<3; ++c)
            {
                if(grid[r][c] == 0) end.push_back({r, c});
                else if(grid[r][c] >= 2) 
                {
                    for(int i=1; i<grid[r][c]; ++i)
                    {
                        begin.push_back({r, c});
                    }
                }
            }
        }
        if(begin.size() == 0) return 0;
        
        
        sort(end.begin(), end.end());
        int ans=INT_MAX;
        do
        {
            int cnt=0;
            for(int i=0; i<end.size(); ++i)
            {
                cnt += abs(begin[i][0]-end[i][0]) + abs(begin[i][1]-end[i][1]);
            }
            
            ans=min(ans, cnt);
        } while(next_permutation(end.begin(), end.end()));
        
        return ans;
    }
};

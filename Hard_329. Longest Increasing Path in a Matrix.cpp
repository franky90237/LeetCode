//2022-05-23
//time. : O(m*n)
//space : O(m*n)
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=1;
        for(int r=0; r<m ; ++r)
        {            
            for(int c=0; c<n ; ++c)
            {
                res=max(res,solve(dp,matrix,r,c,-1));
            }
            //cout<<endl<<endl;
        }
        
        return res;
    }
    
    int solve(vector<vector<int>>& dp, vector<vector<int>>& matrix, int r, int c, int pre)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n || matrix[r][c]<0) return 0;
        //cout<<matrix[r][c]<<" "<<r<<" "<<c<<" - "<<pre<<endl;
        if(matrix[r][c]<=pre) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        
        
        int dir[5]={0,1,0,-1,0};
        int max_len=0;
        for(int i=1; i<5; ++i)
        {
            int r_next=r+dir[i-1];
            int c_next=c+dir[i];
            
            matrix[r][c]=-matrix[r][c];
            
            int len=1+solve(dp,matrix,r_next,c_next,-matrix[r][c]);
            max_len=max(max_len,len);
            //cout<<len<<" ";
            matrix[r][c]=-matrix[r][c];
        }
        
        dp[r][c]=max_len;
        return max_len;     
    }
};

//2024-02-17
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        dp.resize(m, vector<int>(n, -1));

        int res = 0;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int cnt = f(matrix, r, c);
                res = max(res, cnt);
            }
        }

        /*
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c) cout << dp[r][c] << " "; cout << endl;
        }
        */
        
        return res;
    }
    
    int f(vector<vector<int>>& arr, int r, int c)
    {
        static int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int m = arr.size();
        int n = arr[0].size();

        if (dp[r][c] == -2) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        dp[r][c] = -2;
        //cout << r << " " << c << endl;

        int maxCnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dir[i][0];
            int nc =  c + dir[i][1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || arr[r][c] >= arr[nr][nc]) continue;
            
            int cnt = f(arr, nr, nc);
            maxCnt = max(maxCnt, cnt);
        }

        return dp[r][c] = maxCnt + 1;
    }
};

//2024-02-17
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> g;
    vector<int> degree;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        buildGraph(matrix);
        
        queue<int> q;
        for(int i = 0; i < total; ++i)
        {
            if(degree[i] == 0) q.push(i);
        }
        
        int res = 0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i = 0; i < size; ++i)
            {
                int cur=q.front();
                q.pop();
                
                for(int next : g[cur])
                {
                    --degree[next];
                    if(degree[next] == 0)
                    {
                        q.push(next);
                    }
                }
            }
            
            ++res;
        }
        
        return res;
    }
    
    void buildGraph(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        g.resize(m*n);
        degree.resize(m*n, 0);
        for(int r = 0; r < m; ++r)
        {
            for(int c = 0; c < n; ++c)
            {
                for(int i = 0; i < 4; ++i)
                {
                    int nr = r +dir[i][0];
                    int nc = c +dir[i][1];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || matrix[r][c] >= matrix[nr][nc]) continue;
                    
                    g[r * n + c].push_back(nr * n + nc);
                    ++degree[nr * n + nc];
                }
            }
        }
    }
};

//2024-03-16
//time  : O(n*k*n)
//sapce : O(n*k)
class Solution 
{
private:
    vector<vector<int>> changes;
    vector<vector<int>> dp;
    
public:
    int palindromePartition(string s, int k) 
    {
        int n = s.size();
        
        changes.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int cnt = 0;
                int left = i;
                int right = j;
                while (left < right)
                {
                    if (s[left] != s[right]) ++cnt;
                    ++left;
                    --right;
                }

                changes[i][j] = cnt;
            }
        }

        dp.resize(n+1, vector<int>(k+1, -1));
        return f(s, n, k);        
    }
    
    int f(string& s, int i, int k)
    {
        int n = s.size();
        if (k == 1) return changes[0][i-1];
        if (i == 0) return n;
        if(dp[i][k] != -1) return dp[i][k];

        int res = n;
        for (int j = i; j >= k; --j)
        {
            int cur = f(s, j - 1, k - 1);
            //cout << j << " " << i << endl;
            res = min(res, cur + changes[j - 1][i - 1]);
        }

        return dp[i][k] = res;
    }
};

//2024-03-16
//time  : O(n*k*n)
//sapce : O(n*k)
class Solution {  
public:
    int palindromePartition(string s, int k) 
    {
        int n = s.size();
        
        vector<vector<int>> changes(n, vector<int>(n, 0));	
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int cnt = 0;
                int left = i;
                int right = j;
                while (left < right)
                {
                    if (s[left] != s[right]) ++cnt;
                    ++left;
                    --right;
                }

                changes[i][j] = cnt;
            }
        }

        vector<vector<int>> f(n + 1, vector<int>(k + 1, n));
        for (int i = 1; i <= n; ++i) f[i][1] = changes[0][i - 1];

        for (int c = 2; c <= k; ++c)
        {
            for (int i = c; i <= n; ++i)
            {			
                for (int j = i; j >= c; --j)
                {
                    int cur = f[j - 1][c - 1];
                    //cout << j << " " << i << endl;
                    f[i][c] = min(f[i][c], cur + changes[j - 1][i - 1]);
                }
            }
        }
        
        /*
        for (int i = 0; i <= n; ++i)
        {
            for (int c = 0; c <= k; ++c)
            {
                if (f[i][c] >= n)  cout << "X ";
                else cout << f[i][c] << " ";
            }
            cout << endl;
        }
        */

        return f[n][k];     
    }    
};

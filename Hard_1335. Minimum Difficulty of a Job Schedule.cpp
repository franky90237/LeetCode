//2024-03-20
//time  : O(n*d*n)
//space : O(n*d
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        int n = jobDifficulty.size();
        int maxVal = *max_element(jobDifficulty.begin(), jobDifficulty.end());
        vector<vector<int>> f(n + 1, vector<int>(d + 1, -1));	

        for (int i = 1; i <= n; ++i) f[i][1] = max(f[i - 1][1], jobDifficulty[i - 1]);
        for (int c = 2; c <= d; ++c)
        {
            for (int i = c; i <= n; ++i)
            {
                f[i][c] = INT_MAX;
                maxVal = INT_MIN;
                for (int j = i; j >= c; --j)
                {
                    maxVal = max(maxVal, jobDifficulty[j - 1]);
                    f[i][c] = min(f[i][c], f[j - 1][c - 1] + maxVal);
                }
            }
        }
        
        /*
        for (int i = 0; i <= n; ++i)
        {
            for (int c = 0; c <= d; ++c)
            {
                cout << f[i][c] << " ";
                //if (f[i][c] >= n)  cout << "X ";
                //else cout << f[i][c] << " ";
            }
            cout << endl;
        }
        */
        
        return f[n][d];
    }
};

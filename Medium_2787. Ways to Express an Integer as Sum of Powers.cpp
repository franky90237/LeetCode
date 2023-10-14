//2023-10-14
//time  : O(n*n^(1/x))
//space : O(n*n^(1/x))
class Solution 
{
private:
    int modulo=1e9+7;
    vector<int> input;
    vector<vector<int>> dp;
    
public:
    int numberOfWays(int n, int x) 
    {        
        for (int i = 1; i <= n; ++i)
        {
            long double res = pow(i, x);
            if (res > n) break;

            input.push_back(res);
            //cout << res << " ";
        }
        //cout << endl;
        
        /*std::function<int(int, int)> helper = [&input, &helper](int cur, int remaining) -> int
        {
            int size = input.size();
            if (remaining == 0) return 1;
            if (cur >= size || remaining < 0) return 0;

            int p = helper(cur + 1, remaining - input[cur]);
            int np = helper(cur + 1, remaining);
            return p + np;
        };*/
        
        dp.resize(input.size(), vector<int>(n+1, -1));
        return helper(0, n);
    }
    
    int helper(int cur, int remaining)
    {
        int size = input.size();
        if (remaining == 0) return 1;
        if (cur >= size || remaining < 0) return 0;
        if(dp[cur][remaining] != -1) return dp[cur][remaining];

        long p = helper(cur + 1, remaining - input[cur]);
        long np = helper(cur + 1, remaining);
        dp[cur][remaining] = (p + np)%modulo;
        return dp[cur][remaining];
    }
};

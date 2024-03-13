//2024-03-13
//time  : O(n*k)
//space : O(n*k)
class Solution {
public:
    using ll = long long;
    
    long long maximumStrength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<vector<ll>> f(n + 1, vector<ll>(k + 1, LLONG_MIN));

        for (int i = 0; i <= n; ++i) f[i][0] = 0;

        for (int c = 1; c <= k; ++c)
        {
            ll sign = (c % 2 == 1) ? 1 : -1;
            ll w = sign * (k - c + 1);
            ll preMax = LLONG_MIN;		
            for (int i = c; i <= n; ++i)
            {
                ll p = f[i - 1][c];

                ll cur = safePlus(f[i - 1][c - 1], nums[i - 1] * w);
                preMax = safePlus(preMax, nums[i - 1] * w);
                ll np = max(cur, preMax);
                preMax = np;

                f[i][c] = max(p, np);
            }
        }
        
        /*
        for (int i = 0; i <= n; ++i)
        {
            for (int c = 0; c <= k; ++c)
            {
                if (f[i][c] == LLONG_MIN) cout << "X ";
                else cout << f[i][c] << " ";
            }
            cout << endl;
        }
        */
        
        return f[n][k];
    }
    
    static ll safePlus(ll a, ll b)
    {
        //cout << a << " " << b << endl;
        if (b < 0 && a < LLONG_MIN - b) return LLONG_MIN;
        return a + b;
    }    
};

//2022-10-03
//time  : O(k*n*target)
//space : O(n*target)
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(1, n, k, target, dp);
    }
    
    int solve(int cur, int n, int k, int target, vector<vector<int>>& dp)
    {
        if(target == 0) return cur > n;        
        if(cur > n || target < 0) return 0;
        if(dp[cur][target] != -1) return dp[cur][target];
        
        long res=0;
        for(int i=1; i<=k; ++i)
        {
            if(target-i < 0) break;            
            res+=solve(cur+1, n, k, target-i, dp);
        }
        
        //cout<<res<<" : "<<cur<<" "<<target<<endl;
        
        int mod=1e9+7;
        res=res%mod;
        dp[cur][target]=res;
        return res;
    }
};

//2022-10-03
//time  : O(n*target*k)
//space : O(n*target)
class Solution {
public:
    int numRollsToTarget(int n, int k, int target)
    {
        int mod=1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        
        for(int i=1; i<=n; ++i)
        {
            for(int x=1; x<=target; ++x)
            {
                for(int val=max(x-k, 0); val<=x-1; ++val)
                {
                    dp[i][x]+=dp[i-1][val];
                    dp[i][x]%=mod;
                }
                
                //dp[i][x]%=mod;
            }
        }
        
        /*for(int i=0; i<=n; ++i)
        {
            for(int x=0; x<=target; ++x) cout<<dp[i][x]<<" ";
            cout<<endl;
        }*/
        
        return dp[n][target];
    }
};

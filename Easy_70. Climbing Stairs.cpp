//2022-05-25
//dp iterative
//time  : O(n)
//space : O(n)
class Solution {
public:
    int climbStairs(int n)
    {
        if(n<=2) return n;
        
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3; i<=n; ++i)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};

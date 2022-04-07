//TLE
//time  : O(k*n*n)
//space : O(k*n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int n=prices.size();
        const int k=2+1;
        
        int dp[k][n];
        
        for(int i=0; i<n; ++i) dp[0][i]=0;
        for(int t=0; t<k; ++t) dp[t][0]=0;
        
        for(int t=1; t<k; ++t)
        {
            for(int i=1; i<n; ++i) 
            {
                int sell_at_i_profit=prices[i]-prices[0];
                for(int j=i; j>=1; --j)
                {
                    sell_at_i_profit=max(sell_at_i_profit,prices[i]-prices[j]+dp[t-1][j]);
                }
                
                dp[t][i]=max(dp[t][i-1],sell_at_i_profit);
                
                //cout<<dp[t][i]<<" ";
            }
            //cout<<endl;
        }
        
        return dp[k-1][n-1];
    }
};

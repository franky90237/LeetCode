//2023-08-22
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int maximizeTheProfit(int x, vector<vector<int>>& offers)
    {
        sort(offers.begin(), offers.end());
        vector<int> startIdx;
        for(auto offer: offers)
        {
            startIdx.push_back(offer[0]);
        }
        
        int n=offers.size();
        vector<int> dp(n+1, 0);
        dp[n]=0;
        for(int i=n-1; i>=0; --i)
        {
            auto it=upper_bound(startIdx.begin(), startIdx.end(), offers[i][1]);
            int nxt=it-startIdx.begin();
            dp[i]=max(dp[i+1], offers[i][2]+dp[nxt]);
        }
        
        return dp[0];
    }
};

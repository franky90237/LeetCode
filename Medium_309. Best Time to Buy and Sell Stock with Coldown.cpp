//finate state machine
//reference : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int s0[n];
        int s1[n];
        int s2[n];
        
        s0[0]=0;
        s1[0]=-prices[0];
        s2[0]=0;
        for(int i=1; i<n; ++i)
        {
            s2[i]=s1[i-1]+prices[i];
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
            s0[i]=max(s0[i-1],s2[i-1]);
        }
        
        return max(s0[n-1],s2[n-1]);
    }
};

//2022-07-27
//TLE
//dfs
//time  : O(2^n)
//space : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        return dfs(prices,0,false);
    }
    
    int dfs(vector<int>& prices, int cur, bool have_bought)
    {
        int n=prices.size();
        if(cur>=n) return 0;
        
        if(have_bought)
        {
            int sell = prices[cur] + dfs(prices,cur+2,false);
            int cold = dfs(prices,cur+1,true);
            return max(sell,cold);
        }
        else
        {
            int buy= -prices[cur] + dfs(prices,cur+1,true);
            int cold = dfs(prices,cur+1,false);
            return max(buy,cold);
        }
    }
};

//2022-07-27
//dfs + dp
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return dfs(dp,prices,0,false);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& prices, int cur, bool have_bought)
    {
        int n=prices.size();
        if(cur>=n) return 0;
        if(dp[cur][have_bought]!=-1) return dp[cur][have_bought];
        
        if(have_bought)
        {
            int sell = prices[cur] + dfs(dp,prices,cur+2,false);
            int cold = dfs(dp,prices,cur+1,true);
            dp[cur][have_bought] = max(sell,cold);
            
        }
        else
        {
            int buy= -prices[cur] + dfs(dp,prices,cur+1,true);
            int cold = dfs(dp,prices,cur+1,false);
            dp[cur][have_bought] = max(buy,cold);
        }
        
        return dp[cur][have_bought];
    }
};

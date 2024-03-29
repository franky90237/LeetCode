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

//2022-07-27
//finate state machine
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        
        int hold[n];
        int not_hold[n];
        int cold[n];
        
        hold[0]=-prices[0];
        not_hold[0]=0;
        cold[0]=0;
        
        for(int i=1; i<n; ++i)
        {
            hold[i]=max(hold[i-1],not_hold[i-1]-prices[i]);
            not_hold[i]=max(not_hold[i-1],cold[i-1]);
            cold[i]=hold[i-1]+prices[i];
        }
        
        /*for(int i=0; i<n; ++i) cout<<hold[i]<<" ";
        cout<<endl;
        for(int i=0; i<n; ++i) cout<<not_hold[i]<<" ";
        cout<<endl;
        for(int i=0; i<n; ++i) cout<<cold[i]<<" ";
        cout<<endl;*/
                
        return max(not_hold[n-1],cold[n-1]);
    }
    
};

//2022-07-27
//different state transition
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        
        int hold[n];
        int not_hold[n];
        int rest[n];
        
        hold[0]=-prices[0];
        not_hold[0]=0;
        rest[0]=0;
        
        for(int i=1; i<n; ++i)
        {
            hold[i]=max(hold[i-1],rest[i-1]-prices[i]);
            not_hold[i]=max(not_hold[i-1],hold[i-1]+prices[i]);
            rest[i]=max(rest[i-1],not_hold[i-1]);
        }
        
        /*for(int i=0; i<n; ++i) cout<<hold[i]<<" ";
        cout<<endl;
        for(int i=0; i<n; ++i) cout<<not_hold[i]<<" ";
        cout<<endl;
        for(int i=0; i<n; ++i) cout<<rest[i]<<" ";
        cout<<endl;*/
        
        return max(not_hold[n-1],rest[n-1]);
    }
    
};

//2023-12-21
//time  : O(n)
//space : O(n)
class Solution {
private:
    vector<vector<int>> dp;
    
public:
    int maxProfit(vector<int>& prices) 
    {
        dp.resize(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, false);
    }
    
    int solve(vector<int>& prices, int idx, bool hold)
    {
        if(idx >= prices.size()) return 0;        
        if(dp[idx][hold] != -1) return dp[idx][hold];
        
        if(hold)
        {
            dp[idx][hold]=max(solve(prices, idx+1, hold), solve(prices, idx+2, !hold) + prices[idx]);
        }
        else
        {
           dp[idx][hold]=max(solve(prices, idx+1, hold), solve(prices, idx+1, !hold) - prices[idx]);
        }
        
        return dp[idx][hold];
    }
};

//2024-02-13
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        dp.resize(n, vector<int>(2, -1));
        
        return f(prices, 0, false);
    }
    
    int f(vector<int>& prices, int i, bool isHold)
    {
        int n=prices.size();
        if(i >= n) return 0;
        if(dp[i][isHold] != -1) return dp[i][isHold];
        
        if(isHold) dp[i][isHold] = max(f(prices, i+2, false) + prices[i], 
                              f(prices, i+1, true));
        else dp[i][isHold] = max(f(prices, i+1, true) - prices[i], 
                        f(prices, i+1, false));
        
        return dp[i][isHold];
    }
};

//2024-02-13
//time  : O(n)
//space : O(n)
class Solution {        
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        
        for(int i=n-1; i>=0; --i)
        {
            dp[i][true] = max(dp[i+2][false] + prices[i], dp[i+1][true]);
            dp[i][false] = max(dp[i+1][true] - prices[i], dp[i+1][false]);
        }
        
        return dp[0][false];
    }      
};

//2024-02-13
//time  : O(n)
//space : O(1)
class Solution {        
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();        
        
        int hold_1 = 0;
        int notHold_1 = 0, notHold_2 = 0;
        
        for(int i=n-1; i>=0; --i)
        {
            int new_hold_1 = max(prices[i] + notHold_2, hold_1);
            int new_notHold_1 = max(-prices[i] + hold_1, notHold_1);
            
            hold_1 = new_hold_1;
            notHold_2 = notHold_1;
            notHold_1 = new_notHold_1;                        
        }
        
        return notHold_1;
    }      
};

//dp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {                
        int n=prices.size();
        int last=n-1;
        while(prices[last]==0) --last;
                
        n=last+1;
        int table[n];
        table[n-1]=0;
        for(int i=n-2; i>=0; --i)
        {
            int max_profit=table[i+1];
            for(int j=i+1; j<n; ++j)
            {
                int diff=(prices[j]-prices[i] < 0) ? 0 : prices[j]-prices[i];
                
                max_profit=max(max_profit,diff+table[j]);
            }
            
            table[i]=max_profit;
        }
        
        //for(auto& i:table) cout<<i<<" ";
        
        return table[0];
    }
};

//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int profit=0;
        
        for(int i=1; i<n; ++i)
        {
            int diff=prices[i]-prices[i-1];
            if(diff>0)
            {
                profit+=diff;
            }
        }
        
        return profit;
    }
};

//finate state machine
//reference : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
//time  : O(n)
//space : O(n) (can be reduced to 1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int s0[n];
        int s1[n];
        
        s0[0]=0;
        s1[0]=-prices[0];        
        for(int i=1; i<n; ++i)
        {
            s0[i]=max(s0[i-1],s1[i-1]+prices[i]);
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
        }
        
        /*for(auto& i:s0) cout<<i<<"  ";
        cout<<endl;
        for(auto& i:s1) cout<<i<<" ";*/
        
        return s0[n-1];
    }
};

//2022-07-21
//greedy
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit=0;
        int buy=prices[0];
        
        for(auto& price:prices)
        {
            if(price>buy)
            {
                profit+=price-buy;                
            }
            
            buy=price;
        }
        
        return profit;
    }
};

//2022-07-22
//finate state machine (dp)
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int hold[n];
        int notHold[n];
        
        hold[0]=-prices[0];
        notHold[0]=0;
        
        for(int i=1; i<n; ++i)
        {
            hold[i]=max(hold[i-1],notHold[i-1]-prices[i]);
            notHold[i]=max(notHold[i-1],hold[i-1]+prices[i]);
        }
        
        /*for(int i=0; i<n; ++i)
        {
            cout<<hold[i]<<" ";
            cout<<notHold[i]<<endl;
        }*/
        
        return notHold[n-1];        
    }
};

//2023-10-04
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[n-1][0]=0;
        dp[n-1][1]=prices[n-1];
        
        for(int i=n-2; i>=0; --i)
        {
            dp[i][0]=max(dp[i+1][0], dp[i+1][1]-prices[i]);
            dp[i][1]=max(dp[i+1][1], dp[i+1][0]+prices[i]);
        }
        
        return dp[0][0];
    }
};

//2023-12-20
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
            dp[idx][hold]=max(solve(prices, idx+1, hold), solve(prices, idx+1, !hold) + prices[idx]);
        }
        else
        {
           dp[idx][hold]=max(solve(prices, idx+1, hold), solve(prices, idx+1, !hold) - prices[idx]);
        }
        
        return dp[idx][hold];
    }
};

//2023-12-20
//time  : O(n)
//space : O(n)
class Solution {
private:
    vector<vector<int>> dp;
    
public:
    int maxProfit(vector<int>& prices) 
    {
        dp.resize(prices.size(), vector<int>(2, -1));
        return solve(prices, prices.size()-1, false);
    }
    
    int solve(vector<int>& prices, int idx, bool hold)
    {
        if(idx == 0) return hold ? -prices[0] : 0;
        if(dp[idx][hold] != -1) return dp[idx][hold];
                
        if(hold)
        {
            dp[idx][hold]=max(solve(prices, idx-1, hold), solve(prices, idx-1, !hold) - prices[idx]);
        }
        else
        {
           dp[idx][hold]=max(solve(prices, idx-1, hold), solve(prices, idx-1, !hold) + prices[idx]);
        }
        
        return dp[idx][hold];
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
        int n=prices.size();
        dp.resize(n+1, vector<int>(2, 0));
        for(int i=n-1; i>=0; --i)
        {
            dp[i][true]=max(dp[i+1][true], dp[i+1][false]+prices[i]);
            dp[i][false]=max(dp[i+1][false], dp[i+1][true]-prices[i]);
        }
        
        return dp[0][false];
    }
};

//2023-12-21
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int dp0=0;
        int dp1=0;
        for(int i=n-1; i>=0; --i)
        {            
            int next_dp0=max(dp0, dp1-prices[i]);
            int next_dp1=max(dp1, dp0+prices[i]);
            
            dp0=next_dp0;
            dp1=next_dp1;      
        }
        
        return dp0;
    }
};

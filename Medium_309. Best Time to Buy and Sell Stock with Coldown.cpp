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

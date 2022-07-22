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

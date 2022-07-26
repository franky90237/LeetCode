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

//time  : O(k*n)
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
            int max_diff=-prices[0];
            for(int i=1; i<n; ++i) 
            {
                max_diff=max(max_diff,-prices[i]+dp[t-1][i]);
                
                dp[t][i]=max(dp[t][i-1],prices[i]+max_diff);
                
                //cout<<dp[t][i]<<" ";
            }
            //cout<<endl;
        }
        
        return dp[k-1][n-1];
    }
};

//time  : O(k*n)
//space : O(k*n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int n=prices.size();
        const int k=2+1;
        
        int dp[k][n];
        int max_diff[k];
        for(int i=0; i<n; ++i) dp[0][i]=0;
        for(int t=0; t<k; ++t) 
        {
            dp[t][0]=0;
            max_diff[t]=-prices[0];
        }
        
        for(int i=1; i<n; ++i)
        {
            for(int t=1; t<k; ++t)
            {
                max_diff[t]=max(max_diff[t],-prices[i]+dp[t-1][i]);
                dp[t][i]=max(dp[t][i-1],prices[i]+max_diff[t]);
                
                //cout<<dp[t][i]<<" ";
            }
            //cout<<endl;
        }
        
        return dp[k-1][n-1];
    }
};

//time  : O(k*n)
//space : O(k)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int n=prices.size();
        const int k=2+1;
        
        int dp[k];
        int max_diff[k];       
        for(int t=0; t<k; ++t) 
        {
            dp[t]=0;
            max_diff[t]=-prices[0];
        }
        
        for(int i=1; i<n; ++i)
        {
            for(int t=1; t<k; ++t)
            {
                max_diff[t]=max(max_diff[t],-prices[i]+dp[t-1]);
                dp[t]=max(dp[t],prices[i]+max_diff[t]);
                
                //cout<<dp[t]<<" ";
            }
            //cout<<endl;
        }
        
        return dp[k-1];
    }
};

//time  : O(k*n)
//space : O(k)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int n=prices.size();
        
        int buy1=-prices[0];
        int sell1=0;
        int buy2=-prices[0];
        int sell2=0;
        
        for(int i=1; i<n; ++i)
        {
            buy1=max(buy1,-prices[i]);
            sell1=max(sell1,buy1+prices[i]);
            buy2=max(buy2,sell1-prices[i]);
            sell2=max(sell2,buy2+prices[i]);
           
            //cout<<buy1<<" "<<sell1<<" "<<buy2<<" "<<sell2<<" "<<endl;           
        }
        
        return sell2;
    }
};

//2022-07-26
//TLE
//dp
//time  : O(k*n*n)
//space : O(k*n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int n=prices.size();
        int dp[3][n];
        
        for(int i=0; i<n; ++i) dp[0][i]=0;
        for(int k=0; k<=2; ++k) dp[k][0]=0;
        
        //dp[k][i] = max( dp[k][i-1],  (x=0 to i-1) max(prices[i]-prices[x]+dp[k-1][x-1]) )
        for(int k=1; k<=2; ++k)
        {
            for(int i=1; i<n; ++i)
            {
                int sell_on_i=0;
                for(int x=0; x<i; ++x)
                {                    
                    if(x==0) sell_on_i=max(sell_on_i,prices[i]-prices[x]);
                    else sell_on_i=max(sell_on_i,prices[i]-prices[x]+dp[k-1][x-1]);
                }
                dp[k][i]=max(dp[k][i-1],sell_on_i);
            }            
        }
        
        return dp[2][n-1];
    }
};

//2022-07-26
//dp
//time  : O(k*n)
//space : O(k*n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        const int n=prices.size();
        int dp[3][n];
        
        for(int i=0; i<n; ++i) dp[0][i]=0;
        for(int k=0; k<=2; ++k) dp[k][0]=0;
        
        //dp[k][i] = max( dp[k][i-1],  (x=0 to i-1) max(prices[i]-prices[x]+dp[k-1][x-1]) )
        //(x=0 to i-1) max(prices[i]-prices[x]+dp[k-1][x-1]) ->
        //(x=0 to i-1) prices[i] + max(-prices[x]+dp[k-1][x-1])
        for(int k=1; k<=2; ++k)
        {
            int diff=INT_MIN;
            for(int i=1; i<n; ++i)
            {
                if(i==1) diff=max(diff,-prices[i-1]);
                else diff=max(diff,-prices[i-1]+dp[k-1][i-2]);
                
                dp[k][i]=max(dp[k][i-1],prices[i]+diff);
            }            
        }
        
        return dp[2][n-1];
    }
};

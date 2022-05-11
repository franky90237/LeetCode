//2022-05-11
//TLE
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int res=solve(coins,0,amount);
        return (res>10000) ? -1 : res;
    }
    
    int solve(vector<int>& coins, int now, int amount)
    {
        if(amount==0) return 0;
        if(amount<0) return 10000;
        
        int n=coins.size();
        int min_cnt=10000+1;
        for(int i=0; i<n; ++i)
        {
            int cnt=1+solve(coins,i,amount-coins[i]);
            //printf("%d %d %d \n",i, amount, cnt);
            min_cnt=min(min_cnt,cnt);
        }
        //cout<<min_cnt<<endl;
        return min_cnt;
    }
};

//2022-05-11
//dp recursive
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        int dp[amount+1];
        for(int i=0; i<amount+1; ++i) dp[i]=-1;
        
        int res=solve(coins,dp,0,amount);
        return (res>10000) ? -1 : res;
    }
    
    int solve(vector<int>& coins, int dp[], int now, int amount)
    {
        if(amount==0)      return 0;
        if(amount<0)       return 10000;
        if(dp[amount]!=-1) return dp[amount];
        
        int n=coins.size();
        int min_cnt=10000+1;
        for(int i=0; i<n; ++i)
        {
            int cnt=1+solve(coins,dp,i,amount-coins[i]);
            //printf("%d %d %d \n",i, amount, cnt);
            min_cnt=min(min_cnt,cnt);
        }
        
        dp[amount]=min_cnt;
        return min_cnt;
    }
};

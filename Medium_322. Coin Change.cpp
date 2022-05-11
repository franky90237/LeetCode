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

//2022-05-11
//dp iterative
//time  : O(n*amount)
//space : O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if(amount==0) return 0;
        
        int n=coins.size();
        int dp[amount+1];
        for(int i=0; i<=amount; ++i) dp[i]=0;
        
        for(int i=1; i<=amount; ++i)
        {
            int min_val=10001;
            for(int j=0; j<n; ++j)
            {
                int rest=i-coins[j];
                if(rest<0) continue;
                min_val=min(min_val,1+dp[rest]);
            }
            //printf("%d, %d \n",i,min_val);
            dp[i]=min_val;
        }
        
        return (dp[amount]>=10001) ? -1 : dp[amount];
    }
};

//2022-05-11
//bfs with visited
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if(amount==0) return 0;
        
        int n=coins.size();
        
        bool visited[amount+1];
        for(int i=0; i<amount; ++i) visited[i]=false;
        queue<int> q;
        for(int i=0; i<n; ++i)
        {
            if(amount-coins[i]==0) return 1;
            if(amount-coins[i]<0) continue;
            
            visited[amount-coins[i]]=true;
            q.push(amount-coins[i]);
        }
        
        int cnt=2;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0; i<size; ++i)
            {
                int tmp=q.front();
                q.pop();
                if(tmp<0) continue;
                
                for(int j=0; j<n; ++j)
                {
                    //printf("%d %d \n",tmp,tmp-coins[j]);
                    if(tmp-coins[j]<0) continue;
                    if(visited[tmp-coins[j]]) continue;
                    if(tmp-coins[j]==0) return cnt;
                    
                    visited[tmp-coins[j]]=true;
                    q.push(tmp-coins[j]);
                }
                //cout<<endl<<endl;
            }
            //cout<<endl<<endl;
            ++cnt;
        }
        
        return -1;
    }
};

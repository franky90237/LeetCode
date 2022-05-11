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
        for(int i=now; i<n; ++i)
        {
            int cnt=1+solve(coins,i,amount-coins[i]);
            //printf("%d %d %d \n",i, amount, cnt);
            min_cnt=min(min_cnt,cnt);
        }
        //cout<<min_cnt<<endl;
        return min_cnt;
    }
};

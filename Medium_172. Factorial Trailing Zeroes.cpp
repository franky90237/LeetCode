//2022-05-12
//time  : O(n)
//space : O(n)
class Solution {
public:
    int trailingZeroes(int n)
    {
        if(n<=4) return 0;
        
        int dp[10001]={0};
        
        int len=n/5;
        int sum=0;
        int res=0;
        for(int i=1; i<=len; ++i)
        {
            sum+=5;
            dp[sum]=1+dp[sum/5];
            res+=dp[sum];
        }
        
        return res;
    }
};

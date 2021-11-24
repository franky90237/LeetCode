class Solution {
public:
    int numSquares(int n) 
    {       
        int *dp=new int[n+1];
        memset(dp,0,sizeof(int)*(n+1));
        //for(int i=0;i<=n;++i) dp[i]=-1;        
        
        return dp_numSquares(n,dp);
        //int min_val=dp_numSquares(n,dp);
        //for(int i=0;i<=n;++i) cout<<dp[i]<<endl;
        //return min_val;
    }
    
    int dp_numSquares(int n, int dp[])
    {
        if(dp[n]!=0) return dp[n];
        
        if(n==1) 
        {
            dp[n]=1;
            return 1;
        }
        
        int root=sqrt(n);
        if(n==root*root)
        {
            dp[n]=1;
            return 1;
        }
        
        int min_value=n;
        while(root>0)
        {        
            min_value=min(dp_numSquares(n-root*root,dp)+dp_numSquares(root*root,dp),min_value);
            --root;
        }
        
        dp[n]=min_value;
        return min_value;
    }
};

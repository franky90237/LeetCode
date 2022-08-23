//2022-08-21
//MLE
//dp recursive
class Solution 
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int n=stations.size();
        if(n==0) return startFuel>=target ? 0 : -1;        
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(stations.back()[0]+1, vector<int>(target+1,-1) ) );
        
        int ans=dfs(0,0,startFuel,target,stations,dp);
        
        return ans==INT_MAX ? -1 : ans;
    }
    
    int dfs(int cur, int start, int startFuel, int target, vector<vector<int>>& stations, vector<vector<vector<int>>>& dp)
    {
        int n=stations.size();
        
        //cout<<cur<<" : ("<<start<<","<<startFuel<<")"<<endl;
        if(start+startFuel>=target) return 0;
        if(cur==n) return INT_MAX;
        if(dp[cur][start][startFuel]!=-1) return dp[cur][start][startFuel];
        
        int ans=INT_MAX;
                
        for(int i=cur; i<n; ++i)
        {
            int pos=stations[i][0];
            int fuel=stations[i][1];
            
            if(startFuel-(pos-start)<0) break;
            
            int len=dfs(i+1,pos,startFuel-(pos-start)+fuel,target,stations,dp);
            if(len!=INT_MAX) ++len;
                        
            ans=min(ans,len);            
        }
        
        //cout<<endl;
        //cout<<cur<<" "<<ans<<" : "<<start<<" "<<startFuel<<endl;
        dp[cur][start][startFuel]=ans;
        return ans;
    }
};

//2022-08-22
//dp iterative
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int n=stations.size();
        if(n==0) return (startFuel>=target) ? 0 : -1;
        
        long dp[n][n+1];        
        for(int i=0; i<n; ++i) dp[i][0]=startFuel;
        dp[0][1] = startFuel>=stations[0][0] ? startFuel+stations[0][1] : -1;
        
        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<=i+1; ++j)
            {
                if(j==i+1)
                {
                    if(dp[i-1][j-1]>=stations[i][0]) dp[i][j]=dp[i-1][j-1]+stations[i][1];
                    else dp[i][j]=-1;                   
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    
                    if(dp[i-1][j-1]>=stations[i][0]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i][1]);                    
                }
            }
        }
        
        /*for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=i+1; ++j) cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        
        for(int j=0; j<=n; ++j)
        {
            if(dp[n-1][j]>=target) return j;
        }
        
        return -1;
    }
};

//2022-08-22
//dp iterative
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int n=stations.size();
        if(n==0) return (startFuel>=target) ? 0 : -1;
        
        long dp[n][n+1];        
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n+1; ++j) dp[i][j]=-1;            
        }            
        for(int i=0; i<n; ++i) dp[i][0]=startFuel;
        dp[0][1] = startFuel>=stations[0][0] ? startFuel+stations[0][1] : -1;
        
        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<=i+1; ++j)
            {                
                dp[i][j]=dp[i-1][j];                
                if(dp[i-1][j-1]>=stations[i][0]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i][1]);
            }
        }
        
        /*for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n+1; ++j) cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        
        for(int j=0; j<=n; ++j)
        {
            if(dp[n-1][j]>=target) return j;
        }
        
        return -1;
    }
};

//2022-08-22
//clear, dp iterative
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int n=stations.size();
        if(n==0) return (startFuel>=target) ? 0 : -1;
        
        long dp[n+1][n+1];
        memset(dp,0,sizeof(dp[0][0])*(n+1)*(n+1));
        for(int i=0; i<=n; ++i) dp[i][0]=startFuel;       
        
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=i; ++j)
            {                
                dp[i][j]=dp[i-1][j];                
                if(dp[i-1][j-1]>=stations[i-1][0]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i-1][1]);
            }
        }
        
        /*for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j) cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        
        for(int j=0; j<=n; ++j)
        {
            if(dp[n-1][j]>=target) return j;
        }
        
        return -1;
    }
};

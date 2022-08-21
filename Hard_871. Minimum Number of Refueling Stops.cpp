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

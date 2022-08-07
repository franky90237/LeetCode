//2022-08-07
//TLE
//dp recursive
class Solution {
public:
    int longestIdealString(string s, int k)
    {
        int n=s.size();
        vector<int> dp(n,-1);
        
        solve(-1,0,s,k,dp);
        
        return dp[0];
    }
    
    int solve(int pre, int cur, string& s, int k, vector<int>& dp)
    {
        /*
        a,b,c,d        
        */
        
        int n=s.size();
        
        if(cur==n) return 0;        
        if(dp[cur]!=-1) return dp[cur];
        
        int max_len=0;
        for(int i=cur; i<n; ++i)
        {
            if(absolute_difference_lessK(s,pre,i,k))
            {
                int cur_len = 1 + solve(i,i+1,s,k,dp);
                max_len=max(max_len,cur_len);
            }
        }
        
        dp[cur]=max_len;
        return dp[cur];
    }
    
    bool absolute_difference_lessK(string& s, int pre, int cur, int k)
    {
        return (pre==-1 || abs(s[cur]-s[pre])<=k);
    }
};

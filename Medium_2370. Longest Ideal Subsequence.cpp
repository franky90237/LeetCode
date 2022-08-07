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

//2022-08-07
//TLE
//dp iterative
//time  : O(n*n)
//space L O(n)
class Solution {
public:
    int longestIdealString(string s, int k)
    {
        int n=s.size();
        vector<int> dp(n,1);
        
        int ans=0;
        for(int cur=1; cur<n; ++cur)
        {
            for(int pre=0; pre<cur; ++pre)
            {
                if(abs(s[cur]-s[pre])<=k)
                {
                    dp[cur]=max(dp[cur],1+dp[pre]);
                }
            }
            
            ans=max(ans,dp[cur]);
        }
        
        //for(auto& i:dp) cout<<i<<" ";
        return ans;
    }    
};

//2022-08-07
//dp iterative
//time  : O(n*k)
//space : O(26)
class Solution {
public:
    int longestIdealString(string s, int k)
    {
        int n=s.size();
        int dp[26]={0};
        
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            int idx=s[i]-'a';
            int start=max(0,idx-k);
            int end=min(25,idx+k);
            
            while(start<=end)
            {                
                dp[idx]=max(dp[idx],dp[start]);                
                ++start;
            }
            
            ++dp[idx];
            ans=max(ans,dp[idx]);
        }
        
        //for(auto& i:dp) cout<<i<<" ";
        return ans;
    }    
};

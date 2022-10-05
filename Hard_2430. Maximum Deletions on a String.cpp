//2022-10-05
//TLE
//time  : O(n*n*n)
//space : O(n)
class Solution {
public:
    int deleteString(string s) 
    {
        int n=s.size();
        vector<int> dp(n+1, 1);
        dp[n]=0;    
                
        for(int i=n-1; i>=0; --i)
        {
            int len=n-i;
            for(int k=1; k<=len/2; ++k)
            {
                if(match(s, i, k))
                {
                    dp[i]=max(dp[i], 1+dp[i+k]);
                }                
            }                        
        }
        
        for(int i=0; i<n; ++i) cout<<dp[i]<<" ";
        cout<<endl;
        
        return dp[0];
    }
    
    bool match(string& s, int start, int len)
    {
        int x=start;
        int y=start+len;
        //cout<<x<<", "<<y<<endl;
        
        for(int i=1; i<=len; ++i)
        {
            if(s[x] != s[y]) return false;
            ++x;
            ++y;
        }
        
        //cout<<endl;
        return true;
    }
};

//2022-10-05
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int deleteString(string s) 
    {
        int n=s.size();
        
        vector<vector<int>> lcs(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; --i)
        {
            for(int k=n-1; k>=0; --k)
            {
                if(s[i] == s[k])
                {
                    lcs[i][k]=1+lcs[i+1][k+1];
                }
            }
        }
        
        vector<int> dp(n+1, 1);
        dp[n]=0;    
                
        for(int i=n-1; i>=0; --i)
        {
            int len=n-i;
            for(int k=1; k<=len/2; ++k)
            {
                if(lcs[i][i+k] >= k)
                {
                    dp[i]=max(dp[i], 1+dp[i+k]);
                }                
            }                        
        }
        
        //for(int i=0; i<n; ++i) cout<<dp[i]<<" ";
        //cout<<endl;
        
        return dp[0];
    }
};

//2022-10-05
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int deleteString(string s) 
    {
        int n=s.size();
        
        vector<vector<int>> lcs(n+1, vector<int>(n+1, 0));        
        vector<int> dp(n+1, 1);
        
        for(int i=n-1; i>=0; --i)
        {            
            for(int k=i+1; k<n; ++k)
            {
                if(s[i] == s[k])
                {
                    lcs[i][k]=1+lcs[i+1][k+1];
                }
                
                if(lcs[i][k] >= k-i)
                {
                    dp[i]=max(dp[i], 1+dp[k]);
                }                
            }
        }
        
        //for(int i=0; i<n; ++i) cout<<dp[i]<<" ";
        //cout<<endl;
        
        return dp[0];
    }
};

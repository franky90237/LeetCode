//2022-04-27
//time  : O(n*n*n)
//space : O(1)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n==1) return s;
        
        int range[2]={0,-1};
        int len=0;
        for(int i=0; i<n; ++i)
        {
            int j=n-1;
            if(j-i+1<=len) break;
            for(; j>=i; --j)
            {
                if(j-i+1<=len) break;
                
                int l=i;
                int r=j;
                while(l<r)
                {
                    if(s[l]!=s[r]) break;
                    ++l;
                    --r;
                }
                
                if(l>=r)
                {
                    len=j-i+1;
                    
                    range[0]=i;
                    range[1]=j;
                    
                    break;
                }
            }
        }
        
        string res="";
        for(int i=range[0]; i<=range[1]; ++i) res.push_back(s[i]);
                                                            
        return res;
    }
};

//2022-04-27
//dp
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n==1) return s;
        
        
        int range[2]={0};
        int len=0;
        
        int dp[n][n];
        for(int i=0; i<n; ++i) 
        {
            dp[i][i]=1;
            
            if(i+1<n) 
            {
                if(s[i]==s[i+1])
                {
                    dp[i][i+1]=2;
                    
                    if(len<2)
                    {
                        len=2;
                        range[0]=i;
                        range[1]=i+1;
                    }
                }
                else dp[i][i+1]=0;
            }
            
            for(int j=2; j<n; ++j)
            {
                dp[i][j]=-1;
            }
        }
        
        for(int i=0; i>=n; ++i)
        {
            int j=i+2;
            
            while(j<n)
            {
                cout<<i<<" "<<j<<endl;
                if(s[j]==s[i])
                {
                    if(dp[i+1][j-1]==0) dp[i][j]=0;
                    else if(dp[i+1][j-1]==1) dp[i][j]=1;
                    else
                    {
                        int 
                        while(dp
                    }
                    
                    if(i-j+1>len)
                    {
                        len=j-i+1;
                        range[0]=j;
                        range[1]=i;
                    }
                }
                
                ++j;
            }
        }
        
        string res="";
        for(int i=range[0]; i<=range[1]; ++i) res.push_back(s[i]);
                                                            
        return res;
    }
};

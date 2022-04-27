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
                    dp[i][i+1]=1;
                    
                    if(len<2)
                    {
                        len=2;
                        range[0]=i;
                        range[1]=i+1;
                    }
                }
                else dp[i][i+1]=0;
            }
            
            for(int j=i+2; j<n; ++j)
            {
                dp[i][j]=-1;
            }
        }
        
        /*for(int i=0; i<n; ++i) 
        {
            for(int j=0; j<n; ++j)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        for(int i=0; i<n; ++i)
        {
            if(n-i<=len) break;
                                                
            for(int j=i+2; j<n; ++j)
            {
                if(j-i+1<=len) continue;
                
                if(dp[i][j]!=-1) 
                {
                    if(dp[i][j]==1 && j-i+1>len)
                    {
                        len=j-i+1;
                        range[0]=i;
                        range[1]=j;
                    }
                    continue;
                }
                
                //cout<<i<<" "<<j<<endl;
                if(s[i]==s[j])
                {                    
                    if(dp[i+1][j-1]==0) dp[i][j]=0;
                    else if(dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        int l=i;
                        int r=j;
                        while(dp[l+1][r-1]==-1)
                        {
                            //if(i==3 && j==9) cout<<l<<" "<<r<<" - "<<dp[l][r]<<endl;
                            ++l;
                            --r;
                        }
                                                
                        while(l>=i)
                        {
                            if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1];
                            else dp[l][r]=0;
                            
                            --l;
                            ++r;
                        }
                    }
                    
                    if(dp[i][j]==1 && j-i+1>len)
                    {
                        len=j-i+1;
                        range[0]=i;
                        range[1]=j;
                    }
                }
                else dp[i][j]=0;
            }
        }
        
        string res="";
        for(int i=range[0]; i<=range[1]; ++i) res.push_back(s[i]);
                                                            
        return res;
    }
};

//2022-04-27
//clear dp
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n==1) return s;        
                        
        bool dp[n][n];
        for(int i=0; i<n; ++i) 
        {
            dp[i][i]=true;
        }    
        
        int range[2]={0};
        int max_len=0;
        for(int end=1; end<n; ++end)
        {                      
            for(int start=end-1; start>=0; --start)
            {                
                if(s[start]!=s[end]) 
                {
                    dp[start][end]=false;
                }
                else
                {
                    if(end-start==1) dp[start][end]=true;
                    else dp[start][end]=dp[start+1][end-1];
                    //cout<<start<<" "<<end<<" - "<<dp[start][end]<<endl;
                    if(dp[start][end] && max_len<end-start+1)
                    {                        
                        max_len=end-start+1;
                        range[0]=start;
                        range[1]=end;
                    }
                }
            }
        }
        
        string res="";
        for(int i=range[0]; i<=range[1]; ++i) res.push_back(s[i]);                                                            
        return res;
    }
};

//2022-04-27
//center-based
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n==1) return s;        
        
        int range[2]={0,0};
        int max_len=0;
        
        for(int i=0; i<n; ++i)
        {
            //skip the unnecessary i
            int one_min=min(i*2+1,(n-i)*2+1);
            int two_min=min(i*2+2,(n-i-1)*2+2);
            if(max(one_min,two_min)<=max_len) continue;
            
            int len=1;
            int l=i-1;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                len+=2;
                --l;
                ++r;
            }
            if(len>max_len)
            {
                max_len=len;
                range[0]=l+1;
                range[1]=r-1;
            }
            
            if(i+1<n && s[i]==s[i+1])
            {
                len=2;
                l=i-1;
                r=i+2;
                while(l>=0 && r<n && s[l]==s[r])
                {
                    len+=2;
                    --l;
                    ++r;
                }
                if(len>max_len)
                {
                    max_len=len;
                    range[0]=l+1;
                    range[1]=r-1;
                }
            }
        }
        
        string res="";
        for(int i=range[0]; i<=range[1]; ++i) res.push_back(s[i]);
        
        return res;
    }
};

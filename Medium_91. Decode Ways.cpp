//2022-06-08
//TLE
class Solution {
public:
    int numDecodings(string s)
    {        
        return solve(0,s);
    }
    
    int solve(int now, string& s)
    {
        int n=s.size();
        if(now>=n) return 1;
        if(s[now]=='0') return 0;
        
        int one_digit=solve(now+1,s);
        int two_digit=0;
        if(now+1<n && stoi(s.substr(now,2))<=26)
        {
            two_digit=solve(now+2,s);
        }
        
        return one_digit+two_digit;
    }
};

//2022-06-08
//dp recursive
class Solution {
public:
    int numDecodings(string s)
    {
        int n=s.size();
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=-1;
        
        return solve(0,s,dp);
    }
    
    int solve(int now, string& s, int dp[])
    {
        int n=s.size();
        if(now>=n) return 1;
        if(s[now]=='0') return 0;
        if(dp[now]!=-1) return dp[now];
        
        int one_digit=solve(now+1,s,dp);
        int two_digit=0;
        if(now+1<n && stoi(s.substr(now,2))<=26)
        {
            two_digit=solve(now+2,s,dp);
        }
        
        dp[now]=one_digit+two_digit;
        return dp[now];
    }
};

//2022-06-08
//dp iterative
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numDecodings(string s)
    {
        int n=s.size();
        
        if(s[0]=='0') return 0;
        if(n==1) return 1;       
        
        int dp[n];
        dp[0]=1;
        if(s[1]=='0') 
        {
            if(stoi(s.substr(0,2))>26) return 0;
            else dp[1]=1;
        }
        else             
        {
            if(stoi(s.substr(0,2))>26) dp[1]=1;
            else dp[1]=2;
        }
        
        for(int i=2; i<n; ++i)
        {
            int one_digit=0;
            if(s[i]!='0') one_digit=dp[i-1];
            
            int two_digit=0;
            if(s[i-1]!='0' && stoi(s.substr(i-1,2))<=26)
            {
                two_digit=dp[i-2];
            }
            
            dp[i]=one_digit+two_digit;
            if(dp[i]==0) return 0;
        }
        
        return dp[n-1];
    }
};

//2022-10-01
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numDecodings(string s) 
    {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
    
    int solve(string& s, int cur, vector<int>& dp)
    {
        int n=s.size();
        if(cur >= n) return 1;
        if(dp[cur] != -1) return dp[cur];
        
        int cnt=0;
        int one=s[cur]-'0';
        int two=(cur+1 < n) && one != 0 ? one*10+(s[cur+1]-'0') : 99;
        //int two=99;
        //if(cur+1 <n) two=one*10+(s[cur+1]-'0');
        
        if(valid(one))
        {
            cnt+=solve(s, cur+1, dp);
        }
        if(valid(two))
        {
            cnt+=solve(s, cur+2, dp);
        }
        
        dp[cur]=cnt;
        return cnt;
    }
    
    bool valid(int num)
    {
        return 1 <= num && num <= 26;
    }
};

//2022-10-01
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numDecodings(string s) 
    {
        int n=s.size();
        int dp[n+1];
        for(int i=0; i < n; ++i) dp[i]=0;
        if(valid(s[n-1]-'0')) dp[n-1]=1;
        dp[n]=1;
        
        for(int i=n-2; i>=0; --i)
        {
            int one = s[i]-'0';
            int two = one!=0 ? one*10+s[i+1]-'0' : 99;
            
            int cnt=0;
            if(valid(one)) cnt+=dp[i+1];
            if(valid(two)) cnt+=dp[i+2];            
            
            dp[i]=cnt;
        }
        
        return dp[0];
    }  
    
    bool valid(int num)
    {
        return 1 <= num && num <= 26;
    }
};

//2024-01-31
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numDecodings(string s) 
    {
        int n=s.size();
        vector<int> dp(n+1, 0);
        dp[n]=1;
        dp[n-1] = (s[n-1] != '0');
        
        for(int i=n-2; i>=0; --i)
        {
            if(s[i] == '0') continue;
            
            string first=s.substr(i, 1);
            if(stoi(first) <= 26) dp[i] += dp[i+1];
            
            string second=s.substr(i, 2);
            if(stoi(second) <= 26) dp[i] += dp[i+2];            
        }
        
        return dp[0];
    }      
};

//2024-01-31
//time  : O(n)
//space : O(1)
class Solution {
public:
    int numDecodings(string s) 
    {
        int n=s.size();
        vector<int> dp(n+1, 0);
        dp[n]=1;
        dp[n-1] = (s[n-1] != '0');
        
        int dp_i1=(s[n-1] != '0');
        int dp_i2=1;
        
        for(int i=n-2; i>=0; --i)
        {
            if(s[i] == '0') 
            {
                dp_i2=dp_i1;
                dp_i1=0;                
                continue;
            }
            
            int new_i1=0;            
            string first=s.substr(i, 1);
            if(stoi(first) <= 26) new_i1 += dp_i1;
            
            string second=s.substr(i, 2);
            if(stoi(second) <= 26) new_i1 += dp_i2;
            
            dp_i2=dp_i1;
            dp_i1=new_i1;
        }
        
        return dp_i1;
    }      
};

//2022-10-30
//time  : O(m*n*k), k is the len for '*'
//spcee : O(m*n)
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int m=s.size();
        int n=p.size();        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(s, p, 0, 0, dp);
    }
    
    bool solve(string& s, string& p, int curS, int curP, vector<vector<int>>& dp)
    {
        int m=s.size();
        int n=p.size();
        //cout<<curS<<" "<<curP<<" | "<<s[curS]<<" "<<p[curP]<<endl;
        
        if(curS >= m && curP >= n) return true;
        if(curP >= n) return false;
        if(curS >= m)
        {
            for(int i=curP; i<n; ++i)
            {
                if(p[i] != '*') return false;
            }
            
            return true;
        }
        if(dp[curS][curP] != -1) return dp[curS][curP];
        
        int ans=false;
        if(p[curP] == '?')
        {
            ans=solve(s, p, curS+1, curP+1, dp);
        }
        else if(p[curP] == '*')
        {            
            while(curP+1 < n && p[curP+1] == '*') ++curP;
            
            for(int i=curS; i<=m; ++i)
            {                                
                ans=solve(s, p, i, curP+1, dp);
                if(ans) break;
            }
        }
        else
        {
            if(p[curP] != s[curS]) ans=false;
            else ans=solve(s, p, curS+1, curP+1, dp);
        }
        
        //cout<<curS<<" "<<curP<<" "<<ans<<endl;
        dp[curS][curP]=ans;        
        return ans;
    }
};

//2022-11-02
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int n=s.size();
        int is=0;
        int ip=0;
        int matchToAsterisk=-1;
        int asterisk=-1;
        while(is < s.size())
        {
            if(s[is] == p[ip] || p[ip] == '?')
            {
                ++is;
                ++ip;
            }
            else if(ip < p.size() && p[ip] == '*')
            {
                matchToAsterisk=is;
                asterisk=ip;
                ++ip;
            }
            else if(asterisk != -1)
            {
                is=matchToAsterisk+1;
                ip=asterisk;         
            }
            else 
            {
                return false;
            }
        }
        
        while(ip < p.size())
        {
            if(p[ip] != '*') return false;
            ++ip;
        }
        
        return true;
    }
};

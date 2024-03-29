//2022-09-28
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        /*

        "abbbbbbbbbbbbc"
        "a***b.*.*.*.b*"
        "ab"
        ".*c"
        "a"
        ".*..a*"

        "abcaaaaaaabaabcabac"
        ".*ab.a.*a*a*.*b*b*"

        abca   aaaaaabaabcabac
        .*ab.a .*a*a*.*b*b*

        abca   aaaaaa  baabcabac
        .*ab.a .*a*a*  .*         b*b*
        */        
        
        int push=1;
        for(int i=1; i<p.size(); ++i)
        {
            p[push]=p[i];
            
            if(p[i] == '*')
            {            
                while(i < p.size() && p[i] == '*') ++i;
                --i;
            }
            
            ++push;
        }
        
        p.resize(push);
        //cout<<p<<endl;
                        
        return solve(s, p, 0, 0);
    }
    
    bool solve(string& s, string& p, int si, int pi)
    {
        //cout<<si<<" "<<pi<<endl;
        
        if(si >= s.size() && pi >= p.size()) return true;
        if(si < s.size() && pi >= p.size()) return false;
        if(si >= s.size() && pi < p.size())
        {
            int cnt=p.size()-pi;
            if(cnt%2==1) return false;
            
            ++pi;
            while(pi < p.size())
            {
                if(p[pi] != '*') return false;
                pi+=2;
            }
            
            return true;
        }
        
        //cout<<si<<" "<<pi<<" | "<<s[si]<<" "<<p[pi]<<endl;
        
        if(p[pi] == '.')
        {
            if(pi == p.size()-1) return solve(s, p, si+1, pi+1);
            
            if(p[pi+1] == '*')
            {
                bool flag=solve(s, p, si, pi+2);
                if(flag) return true;
                             
                for(int i=si; i < s.size(); ++i)
                {
                    flag=solve(s, p, i+1, pi+2);
                    if(flag) return true;
                }
                
                return flag;
            }
            else
            {
                return solve(s, p, si+1, pi+1);
            }
        }
        else
        {
            /*if(p[pi] == '*')
            {
                cout<<"error : p[pi] == '*'"<<endl;                
            }*/
            
            if(pi == p.size()-1) 
            {
                if(s[si] != p[pi]) return false;
                return solve(s, p, si+1, pi+1);
            }
            
            if(p[pi+1] == '*')
            {
                bool flag=solve(s, p, si, pi+2);
                if(flag) return true;
                
                for(int i=si; i < s.size() && s[i] == p[pi]; ++i)
                {
                    flag=solve(s, p, i+1, pi+2);
                    if(flag) return true;
                }
                
                return flag;
            }
            else
            {
                if(s[si] != p[pi]) return false;                
                return solve(s, p, si+1, pi+1);
            }
        }
    }
};

//2022-09-28
//dp
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        /*

        "abbbbbbbbbbbbc"
        "a***b.*.*.*.b*"
        "ab"
        ".*c"
        "a"
        ".*..a*"

        "abcaaaaaaabaabcabac"
        ".*ab.a.*a*a*.*b*b*"

        abca   aaaaaabaabcabac
        .*ab.a .*a*a*.*b*b*

        abca   aaaaaa  baabcabac
        .*ab.a .*a*a*  .*         b*b*
        */        
        
        int push=1;
        for(int i=1; i<p.size(); ++i)
        {
            p[push]=p[i];
            
            if(p[i] == '*')
            {            
                while(i < p.size() && p[i] == '*') ++i;
                --i;
            }
            
            ++push;
        }
        
        p.resize(push);
        //cout<<p<<endl;
        
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solve(s, p, 0, 0, dp);
    }
    
    bool solve(string& s, string& p, int si, int pi, vector<vector<int>>& dp)
    {
        //cout<<si<<" "<<pi<<endl;
        
        if(si >= s.size() && pi >= p.size()) return true;
        if(si < s.size() && pi >= p.size()) return false;
        if(si >= s.size() && pi < p.size())
        {
            int cnt=p.size()-pi;
            if(cnt%2==1) return false;
            
            ++pi;
            while(pi < p.size())
            {
                if(p[pi] != '*') return false;
                pi+=2;
            }
            
            return true;
        }
        if(dp[si][pi] != -1) return dp[si][pi];
        //cout<<si<<" "<<pi<<" | "<<s[si]<<" "<<p[pi]<<endl;
        
        if(p[pi] == '.')
        {
            if(pi == p.size()-1) return solve(s, p, si+1, pi+1, dp);
            
            if(p[pi+1] == '*')
            {
                bool flag=solve(s, p, si, pi+2, dp);
                if(flag) return true;
                             
                for(int i=si; i < s.size(); ++i)
                {
                    flag=solve(s, p, i+1, pi+2, dp);
                    if(flag) return true;
                }
                
                dp[si][pi]=flag;
                return flag;
            }
            else
            {
                dp[si][pi]=solve(s, p, si+1, pi+1, dp);
                return dp[si][pi];
            }
        }
        else
        {
            /*if(p[pi] == '*')
            {
                cout<<"error : p[pi] == '*'"<<endl;                
            }*/
            
            if(pi == p.size()-1) 
            {
                if(s[si] != p[pi]) return false;
                return solve(s, p, si+1, pi+1, dp);
            }
            
            if(p[pi+1] == '*')
            {
                bool flag=solve(s, p, si, pi+2, dp);
                if(flag) return true;
                
                for(int i=si; i < s.size() && s[i] == p[pi]; ++i)
                {
                    flag=solve(s, p, i+1, pi+2, dp);
                    if(flag) return true;
                }
                
                dp[si][pi]=flag;
                return flag;
            }
            else
            {
                if(s[si] != p[pi]) 
                {
                    dp[si][pi]=false;
                    return false;
                }
                
                dp[si][pi]=solve(s, p, si+1, pi+1, dp);
                return dp[si][pi];
            }
        }
    }
};

//202-09-29
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        /*

        "aa"
        "a*"
        "a"
        ".*..a*"
        "abcaaaaaaabaabcabac"
        ".*ab.a.*a*a*.*b*b*"
        */
        
        return solve(s, p, 0, 0);
    }
    
    bool solve(string& s, string& p, int i, int k)
    {
        if(i >= s.size() && k >= p.size()) return true;
        if(i < s.size() && k >=p.size()) return false;
        if(i >= s.size() && k < p.size())
        {
            while(k < p.size())
            {                
                if(k+1 >= p.size() || p[k+1] != '*') return false;
                k+=2;
            }
                        
            return true;
        }
        
        //cout<<i<<" "<<k<<" | "<<s[i]<<" "<<p[k]<<endl;
        
        if(k+1 < p.size() && p[k+1] == '*')
        {
            //get empty
            bool canMatch=solve(s, p, i, k+2);
            if(canMatch) return true;
            
            if(s[i] == p[k] || p[k] == '.')  canMatch=solve(s, p, i+1, k);                
            
            return canMatch;
        }
        else
        {
            if(s[i] == p[k] || p[k] == '.') return solve(s, p, i+1, k+1);
            return false;
        }
    }
};

//202-09-29
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        /*

        "aa"
        "a*"
        "a"
        ".*..a*"
        "abcaaaaaaabaabcabac"
        ".*ab.a.*a*a*.*b*b*"
        
        s = ac
        p = ab*c
        */
        
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0]=true;
        for(int i=1; i<=s.size(); ++i) dp[i][0]=false;
        for(int k=2; k<=p.size(); ++k)
        {
            if(k%2 == 1)
            {
                dp[0][k]=false;
            }
            else
            {
                if(p[k-1] == '*') dp[0][k]=dp[0][k-2];
                else dp[0][k]=false;
            }
        }
                
        for(int i=1; i<=s.size(); ++i)
        {
            for(int k=1; k<=p.size(); ++k)
            {
                if(p[k-1] == '*')
                {
                    //empty
                    if(k-2 >= 0) dp[i][k]=dp[i][k-2];
                    
                    if(k-2 >= 0 && (p[k-2] == s[i-1] || p[k-2] == '.'))
                    {
                        dp[i][k]= dp[i][k] | dp[i-1][k];
                    }
                }
                else
                {
                    if(s[i-1] == p[k-1] || p[k-1] == '.') dp[i][k]=dp[i-1][k-1];
                    else dp[i][k]=false;
                }
            }
        }
                
        return dp[s.size()][p.size()];
    }
};

//2024-02-28
//time  : O(m*n)
//space : O(m*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    bool isMatch(string a, string b) 
    {
        int m = a.size();
        int n = b.size();
        dp.resize(m, vector<int>(n, -1));
        return check(a, b, 0, 0);
    }
    
    bool check(string& a, string& b, int i, int j)
    {
        //cout << i << " " << j << " | " << endl;
        int m = a.size();
        int n = b.size();

        if (i == m && j >= n) return true;
        if (j >= n) return false;
        if (i == m)
        {
            int len = n - j;
            if (len % 2 == 1) return false;

            for (int cur = j + 1; cur < n; cur += 2) if (b[cur] != '*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        bool isMatch = false;
        if ((a[i] == b[j] || b[j] == '.') && ((j == n - 1) || (j + 1 < n && b[j + 1] != '*')))
        {
            isMatch = check(a, b, i + 1, j + 1);
        }	
        else if (j + 1 < n && b[j + 1] == '*')
        {
            isMatch = check(a, b, i, j + 2);
            if (a[i] == b[j] || b[j] == '.') isMatch |= check(a, b, i + 1, j + 2) || check(a, b, i + 1, j);
        }

        //cout << i << " " << j << " | " << isMatch << endl;
        return dp[i][j] = isMatch;
    }    
};

//2024-02-28
//time  : O(m*n)
//space : O(m*n)
class Solution {   
public:
    bool isMatch(string a, string b) 
    {
        int m = a.size();
        int n = b.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;        
        for (int j = n - 1; j >= 0; --j)
        {
            int len = n - j;
            if (len % 2 == 1) continue;
            if(j + 1 < n && b[j + 1] != '*') break;
            
            dp[m][j] = true;            
        }
        
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                bool isMatch = false;
                if (j + 1 < n && b[j + 1] == '*')
                {
                    isMatch = dp[i][j + 2];
                    if (a[i] == b[j] || b[j] == '.') isMatch |= dp[i + 1][j + 2] || dp[i + 1][j];
                }
                else if (a[i] == b[j] || b[j] == '.')
                {
                    isMatch = dp[i + 1][j + 1];
                }
                
                dp[i][j] = isMatch;
            }
        }
        
        return dp[0][0];
    }       
};

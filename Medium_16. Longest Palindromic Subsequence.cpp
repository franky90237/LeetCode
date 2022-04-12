//2022-04-12
//TLE
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        
        if(n==1) return 1;
        if(check_palindrome(s)) return n;
        
        for(int cnt=n-1; cnt>=2; --cnt)
        {
            string tmp="";
            if(subquence(s,tmp,0,cnt)) return cnt;
        }
        
        return 1;
    }
    
    bool subquence(string& s, string& tmp, int now, int cnt)
    {
        if(tmp.size()==cnt)
        {
            //cout<<tmp<<endl;
            return check_palindrome(tmp);
        }
        
        for(int i=now; i<s.size(); ++i)
        {
            tmp.push_back(s[i]);
            
            bool is_palindrome=subquence(s,tmp,i+1,cnt);
            if(is_palindrome) return true;
            
            tmp.pop_back();
        }
        
        return false;
    }
    
    bool check_palindrome(string& s)
    {
        int n=s.size();
        for(int i=0; i<n-i-1; ++i)
        {
            if(s[i]!=s[n-i-1]) return false;
        }
        
        return true;
    }
};

//2022-04-12
//TLE
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        
        if(n==1) return 1;
        
        return solve(s,0,n-1);
    }
    
    int solve(string& s, int i, int n)
    {
        if(i==n) return 1;
        if(i>n) return 0;
        
        if(s[i]==s[n]) return 2+solve(s,i+1,n-1);
        
        return max(solve(s,i+1,n),solve(s,i,n-1));
    }
};

//2022-04-12
//TLE
//dp
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        
        if(n==1) return 1;
        
        unordered_map<string,int> m;
        return solve(m,s,0,n-1);
    }
    
    int solve(unordered_map<string,int>& m, string& s, int i, int n)
    {
        string sub=s.substr(i,n-i+1);
        if(m.find(sub)!=m.end()) return m[sub];
        
        if(i==n) return 1;
        if(i>n) return 0;
        
        if(s[i]==s[n])
        {
            int len=solve(m,s,i+1,n-1);
            string sub_lr=s.substr(i+1,n-i-1);
            m[sub_lr]=len;
            
            m[sub]=2+len;
            return 2+len;
        }
        
        int l_len=solve(m,s,i+1,n);
        string l_sub=s.substr(i+1,n-i);
        m[l_sub]=l_len;
        
        int r_len=solve(m,s,i,n-1);
        string r_sub=s.substr(i,n-i);
        m[r_sub]=r_len;
        
        int max_len=max(l_len,r_len);
        m[sub]=max_len;
        return max_len;
    }
};

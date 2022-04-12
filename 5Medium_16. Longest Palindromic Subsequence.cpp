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

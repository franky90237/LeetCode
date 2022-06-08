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

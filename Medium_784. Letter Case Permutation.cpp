//2022-05-02
//backtracking
class Solution {
public:
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> res;
        
        int cnt=0;
        for(auto& c:s)
        {
            if(isalpha(c)) c=tolower(c);
            else ++cnt;
        }
        
        if(cnt==s.size()) return {s};
        
        solve(res,s,0);
        
        return res;
    }
    
    void solve(vector<string>& res, string& s, int now)
    {
        int n=s.size();
        if(now>=n) 
        {
            res.push_back(s);
            return;
        }
        
        while(now< n&& '0'<=s[now] && s[now]<='9') ++now;
        int next=now+1;
        while(next<n && '0'<=s[next] && s[next]<='9') ++next;
        
        solve(res,s,next);
        s[now]=toupper(s[now]);        
        
        solve(res,s,next);
        s[now]=tolower(s[now]);
    }
};

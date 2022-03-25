class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {        
        unordered_set<string> cache[n+1];        
        solve(cache,n);
        
        vector<string> res;
        for(auto& s:cache[n]) res.push_back(s);
        
        //cout<<res.size();
        return res;
    }
    
    void solve(unordered_set<string> cache[], int n)
    {
        if(n==1) 
        {
            cache[n].insert("()");
            return;
        }
        
        solve(cache,n-1);
        
        for(auto& s:cache[n-1])
        {            
            for(int j=0; j<s.size(); ++j)
            {
                if(s[j]=='(')
                {
                    string tmp="("+s;                    
                    cache[n].insert(tmp.insert(j+1,")"));
                }
            }
            
            string tmp="("+s;
            cache[n].insert(tmp.insert(s.size(),")"));
        }
    }
};

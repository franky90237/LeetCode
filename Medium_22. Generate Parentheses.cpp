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

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string tmp;
        solve(n,n,tmp,res);
        
        return res;
    }
    
    void solve(int open, int close, string& tmp, vector<string>& res)
    {
        //cout<<tmp<<endl;
        if(open==0 && close==0)
        {
            res.emplace_back(tmp);
            return;
        }                
        
        if(open<=close && open>0)
        {
            tmp.push_back('(');
            solve(open-1,close,tmp,res);
            tmp.pop_back();
        }
        
        if(close>0)
        {
            tmp.push_back(')');
            solve(open,close-1,tmp,res);
            tmp.pop_back();
        }
    }
};

//2022-07-18
//backtracking + backtracking
//time : O(Catalan number(n))
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string tmp="";        
        backtracking(0,0,n,tmp,ans);
        cout<<ans.size()<<endl;
        return ans;
    }
    
    void backtracking(int left, int right, int n, string& tmp, vector<string>& ans)
    {
        if(tmp.size()==n*2)
        {
            ans.push_back(tmp);
            return;
        }                
                
        if(left < n)
        {
            tmp.push_back('(');
            backtracking(left+1,right,n,tmp,ans);
            tmp.pop_back();
        }
        
        if(left > right)
        {
            tmp.push_back(')');
            backtracking(left,right+1,n,tmp,ans);
            tmp.pop_back();            
        }
    }
};

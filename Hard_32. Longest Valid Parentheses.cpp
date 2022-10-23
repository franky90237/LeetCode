//2022-10-22
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n=s.size();
        vector<int> dp(n, 0);
        
        int ans=0;
        for(int i=0; i<n; ++i)
        {            
            int pre = (i-1 >= 0) ? dp[i-1] : -1;
            if(i > pre && s[i] == '(')
            {
                int idx=calculate(s, i);
                dp[i]=idx;
                ans=max(ans, idx-i+1);
                
                if(idx == n-1) break;
            }   
            else
            {
                dp[i]=pre;
            }
        }
        
        return ans;
    }
    
    int calculate(string& s, int i)
    {
        int n=s.size();
        int idx=-1;
        int l=0;
        int r=0;
        while(i < n && l >= r)
        {
            if(n-i < l-r) break;
            
            if(s[i] == '(')
            {
                ++l;
            }
            else
            {
                ++r;
            }
            
            if(l == r)
            {
                idx=i;
            }
            
            ++i;
        }
        
        return idx;
    }
};

//2022-10-23
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n=s.size();
        if(n <= 1) return 0;
        
        vector<int> dp(n, 0);        
        if(s[0] == '(' && s[1]==')') dp[1]=2;
        
        int ans=dp[1];
        for(int i=2; i<n; ++i)
        {
            if(s[i] == '(')
            {
                dp[i]=0;
            }
            else if(s[i-1] == '(' && s[i] == ')')
            {
                dp[i]=dp[i-2]+2;
            }
            else // ))
            {
                int len=dp[i-1];
                int preIdx=i-1-len;
                if(preIdx >= 0 && s[preIdx] == '(')
                {
                    if(preIdx-1 >= 0) dp[i]=dp[preIdx-1]+dp[i-1]+2;
                    else dp[i]=dp[i-1]+2;
                }
            }
            
            ans=max(ans, dp[i]);
        }
        
        return ans;
    }
};

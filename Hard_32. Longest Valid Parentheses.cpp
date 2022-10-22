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

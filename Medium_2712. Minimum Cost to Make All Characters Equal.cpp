//2023-06-03
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long minimumCost(string s) 
    {
        int n=s.size();
        vector<long long> prefix(n, 0);
        vector<long long> posfix(n, 0);
        
        for(int i=1; i<n; ++i)
        {
            if(s[i] != s[i-1])
            {
                prefix[i] = prefix[i-1] + i;                
            }
            else
            {
                prefix[i] = prefix[i-1];
            }
        }
        
        for(int i=n-2; i>=0; --i)
        {
            if(s[i] != s[i+1])
            {
                posfix[i] = posfix[i+1] + (n-i-1);
            }
            else
            {
                posfix[i] = posfix[i+1];
            }
        }
        
        long long ans=prefix[0]+posfix[0];
        for(int i=1; i<n; ++i)
        {
            ans = min(ans, prefix[i]+posfix[i]);
        }
        
        return ans;
    }
};

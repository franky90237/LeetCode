//2022-09-04
//tiem  : O(2^n)
//space : O(n)
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        
        for(int i=1; i<=9; ++i)
        {
            dfs(i, n-1, k, ans);
        }
        
        return ans;
    }
    
    void dfs(int val, int n, int k, vector<int>& ans)
    {
        if(n==0)
        {
            ans.push_back(val);
            return;
        }
        
        int minus=(val%10)-k;
        if(minus>=0) dfs(val*10+minus, n-1, k, ans);
        
        if(k==0) return;
        
        int plus=(val%10)+k;
        if(plus<=9) dfs(val*10+plus, n-1, k, ans);                
    }
};

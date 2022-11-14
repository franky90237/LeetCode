//2022-11-13
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int maxPalindromes(string s, int k) 
    {
        int n=s.size();
        if(k == 1) return n;
        
        vector<vector<bool>> range(n, vector<bool>(n, false));        
        calculate_palindrome(s, range);
        
        /*for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j) cout<<range[i][j]<<" ";
            cout<<endl;
        }*/
        
        vector<int> dp(n, 0);        
        for(int i=k-1; i<n; ++i)
        {            
            dp[i]=max((int)range[0][i], dp[i-1]);
            for(int x=0; x<=i; ++x)
            {                
                if(i-x >= k) dp[i] = max(dp[i], dp[x] + range[x+1][i]);
                else dp[i] = max(dp[i], dp[x]);
            }
            //cout<<i<<" "<<dp[i]<<endl;
        }
            
        return dp[n-1];
    }
    
    void calculate_palindrome(string& s, vector<vector<bool>>& range)
    {
        int n=s.size();
        for(int i=0; i<n; ++i)
        {
            range[i][i]=true;
            
            int l=i-1;
            int r=i+1;
            while(l >=0 && r < n && s[l] == s[r])
            {
                range[l][r]=true;
                --l;
                ++r;
            }
            
            l=i;
            r=i+1;
            while(l >=0 && r < n && s[l] == s[r])
            {
                range[l][r]=true;
                --l;
                ++r;
            }  
        }
    }   
};

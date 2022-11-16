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

//2022-11-16
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int maxPalindromes(string s, int k) 
    {
        if(k == 1) return s.size();
        
        vector<vector<int>> p;
        searchPalindrome(s, k, p);               
        
        int n=p.size();
        int ans=0;
        int pre_end=-1;
        for(int cur=0; cur<n; ++cur)
        {
            int cur_start=p[cur][0];            
            if(pre_end < cur_start) 
            {
                pre_end=p[cur][1];
                ++ans;                
            }
            else
            {
                pre_end=min(pre_end, p[cur][1]);
            }
        }
        
        return ans;
    }
    
    void searchPalindrome(string s, int k, vector<vector<int>>& p)
    {
        int n=s.size();
        for(int i=0; i<n; ++i)
        {
            int l=i;
            int r=i;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                if(r-l+1 >= k) p.push_back({l, r});
                --l;
                ++r;
            }                      
            
            l=i;
            r=i+1;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                if(r-l+1 >= k) p.push_back({l, r});
                --l;
                ++r;
            }            
        }
    }
};

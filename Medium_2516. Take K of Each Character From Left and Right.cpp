//2022-12-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    int takeCharacters(string s, int k)
    {
        if(k == 0) return 0;
        
        int n=s.size();        
        vector<int> table(3, 0);        
                
        int r=n-1;
        while(r >= 0)
        {
            ++table[s[r]-'a'];
            if(check(table, k)) 
            {                
                break;
            }
               
            --r;
        }
        if(r < 0) return -1;
        
        int ans=n-r;
        int l=0;
        while(l <= r && r < n)
        {
            if(l+1 > ans) break;
            
            ++table[s[l]-'a'];
            while(r < n && table[s[r]-'a'] >= k+1)
            {
                --table[s[r]-'a'];
                ++r;
            }
            
            ans=min(ans, l+1+n-r);
            ++l;
        }
        
        return ans;
    }
               
    bool check(vector<int>& table, int k)
    {
        return table[0] >= k && table[1] >= k && table[2] >= k;
    }
};

//2022-01-09
//time  : O(n)
//space : O(1)
class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        vector<int> table(3, 0);
        for(auto c: s)
        {
            ++table[c-'a'];
        }
        
        if(!match(table ,k)) return -1;
                
        int n=s.size();
        int l=0;
        int r=0;
        int ans=n;
        while(r < n)
        {
            --table[s[r]-'a'];
            
            while(l <= r && !match(table, k))
            {
                ++table[s[l]-'a'];
                ++l;                
            }
            
            ans = min(ans, n-(r-l+1));
            
            ++r;
        }
        
        return ans;
    }
    
    bool match(vector<int>& table, int k)
    {
        return table[0] >= k && table[1] >= k && table[2] >= k;
    }
};

class Solution {
public:
    bool validPalindrome(string s) 
    {
        int n=s.size();
        
        for(int i=0; i<n/2; ++i)
        {
            if(s[i]!=s[n-i-1])
            {
                return validPalindrome(s,i+1,n-i-1) || validPalindrome(s,i,n-i-2);
            }
        }
        
        return true;
    }
    
    bool validPalindrome(string& s, int i, int n)
    {
        while(i<n)
        {
            if(s[i]!=s[n]) return false;
            ++i;
            --n;
        }
        
        return true;    
    }
};

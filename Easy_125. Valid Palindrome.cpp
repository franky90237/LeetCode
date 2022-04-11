class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n=preprocess(s);
        //cout<<n<<" "<<s<<endl;
        
        for(int i=0; i<n-i-1; ++i)
        {
            if(s[i]!=s[n-i-1]) return false;
        }
        
        return true;
    }
    
    int preprocess(string& s)
    {
        int n=s.size();
        
        int alnum=0;
        for(int i=0; i<n; ++i)
        {
            if(isalnum(s[i]))
            {
                s[i]=tolower(s[i]);
                swap(s[i],s[alnum]);
                ++alnum;
            }
        }
        
        return alnum;
    }
};

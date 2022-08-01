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

class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n=s.size();
        
        int l=0, r=n-1;
        while(l<r)
        { 
            if(!isalnum(s[l])) ++l;
            if(!isalnum(s[r])) --r;
            //cout<<s[l]<<" "<<s[r]<<endl;
            if(isalnum(s[l]) && isalnum(s[r]))
            {
                if(tolower(s[l])!=tolower(s[r])) return false;
                ++l;
                --r;
            }
        }
        
        return true;
    }
};

//2022-08-01
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool isPalindrome(string s)
    {
        int left=0;
        int right=s.size()-1;
        
        while(left<right)
        {            
            while(left<right && !isalnum(s[left])) ++left;
            while(left<right && !isalnum(s[right])) --right;
            
            //cout<<s[left]<<" "<<s[right]<<endl;
            if(tolower(s[left])!=tolower(s[right])) return false;
            ++left;
            --right;            
        }
        
        return true;
    }
};

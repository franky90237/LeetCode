//2022-05-23
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n=s.size();
        
        int res=n;
        for(int cnt=2; cnt<=n; ++cnt)
        {
            for(int start=0; start+cnt-1<n; ++start)
            {
                //cout<<s.substr(start,cnt)<<" "<<start+cnt-1<<endl;
                res+=is_palindromic(s,start,start+cnt-1);
            }
        }
        
        return res;
    }
    
    bool is_palindromic(string& s, int start, int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end]) return false;
            
            ++start;
            --end;
        }
        
        return true;
    }
};

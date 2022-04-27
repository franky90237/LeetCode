//2022-04-27
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n==1) return s;
        
        int range[2]={0,-1};
        int len=0;
        for(int i=0; i<n; ++i)
        {
            int j=n-1;
            if(j-i+1<=len) break;
            for(; j>=i; --j)
            {
                if(j-i+1<=len) break;
                
                int l=i;
                int r=j;
                while(l<r)
                {
                    if(s[l]!=s[r]) break;
                    ++l;
                    --r;
                }
                
                if(l>=r)
                {
                    len=j-i+1;
                    
                    range[0]=i;
                    range[1]=j;
                    
                    break;
                }
            }
        }
        
        string res="";
        for(int i=range[0]; i<=range[1]; ++i) res.push_back(s[i]);
                                                            
        return res;
    }
};

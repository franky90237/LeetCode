//2022-07-07
//KMP
//time  : O(m+n)
//space : O(n)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(needle=="") return 0;
        
        int n=needle.size();
        int longest_prefix_sufix[n];
        longest_prefix_sufix[0]=0;
        
        int pre=0;
        int i=1;
        while(i<n)
        {
            if(needle[pre]==needle[i])
            {
                longest_prefix_sufix[i]=pre+1;
                ++pre;
                ++i;
            }
            else
            {
                if(pre==0)
                {
                    longest_prefix_sufix[i]=0;
                    ++i;
                }
                else
                {
                    pre=longest_prefix_sufix[pre-1];
                }
            }
        }
                
        //for(auto& lps:longest_prefix_sufix) cout<<lps<<" ";
        
        int m=haystack.size();        
        pre=0;
        i=0;        
        while(i<m)
        {
            if(haystack[i]==needle[pre])
            {
                ++i;
                ++pre;
                if(pre==n) return i-pre;
            }
            else
            {
                if(pre==0) ++i;
                else
                {
                    pre=longest_prefix_sufix[pre-1];
                }
            }
        }
        
        //cout<<endl<<i<<" "<<pre<<endl;
        //if(pre==n) return i-pre;
        return -1;        
    }
};

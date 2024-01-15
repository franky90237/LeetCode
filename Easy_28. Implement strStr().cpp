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

//2024-01-15
//time  : O(n+m)
//spcae : O(m)
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        vector<int> LPS = getLPS(needle);
        //for(int i : LPS) cout<<i<<" "; cout<<endl;
        //int LPS[] = {0,0,0,0,0,0,0,0,0};
        
        int i=0;
        int j=0;
        while(i < haystack.size() && j < needle.size())
        {
            //cout<<i<<" "<<j<<endl;
            if(haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                if(j == 0) ++i;                
                else j = LPS[j-1];
            }
        }
        
        if(j == needle.size()) return i-needle.size();
        return -1;
    }
    
    vector<int> getLPS(string& s)
    {
        int n=s.size();
        
        vector<int> LPS(n, 0);
        int i=0;
        int j=1;
        
        while(j < s.size())
        {
            //cout<<i<<" "<<j<<endl;
            if(s[i] == s[j])
            {
                LPS[j]=i+1;
                ++i;
                ++j;                
            }
            else
            {
                if(i == 0) ++j;                
                else i = LPS[i-1];
            }
        }
        
        return LPS;
    }
};

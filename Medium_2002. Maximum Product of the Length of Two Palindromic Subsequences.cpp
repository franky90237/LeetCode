//time  : O(2^(2n))
//space : O(2^n)
class Solution {
public:
    int maxProduct(string s) 
    {
        int n=s.size();
        
        int total=1<<n;
        int len[total];
        for(int i=0; i<total; ++i) 
        {            
            len[i]=palindrome_length(s,i);
            //cout<<bitset<10>(i)<<": "<<len[i]<<endl;
        }
        
        int max_len=0;
        for(int s1=0; s1<total; ++s1)
        {
            for(int s2=0; s2<total; ++s2)
            {
                if((s1 & s2) == 0)
                {
                    max_len=max(max_len,len[s1]*len[s2]);
                }
            }
        }
        
        return max_len;
    }
    
    int palindrome_length(string& s, int subsequence)
    {
        int n=s.size();
        int msb=n-1;
        int lsb=0;
        int len=0;
        
        while(msb>=lsb)
        {
            //if(subsequence==5) cout<<s[msb]<<" "<<s[lsb]<<endl;
            if((subsequence & (1<<lsb)) == 0) ++lsb;
            else if((subsequence & (1<<msb)) == 0) --msb;
            else if(s[lsb]!=s[msb]) return 0;
            else
            {
                if(lsb==msb) len+=1;
                else len+=2;
                
                ++lsb;
                --msb;
            }
        }
        
        return len;
    }
};

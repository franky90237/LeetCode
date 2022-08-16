//2022-08-16
//time  : O(m), m is the number of bits of n
//space : O(1)
class Solution {
public:
    int binaryGap(int n)
    {
        int start=-1;    
        
        int idx=0;
        int ans=0;
        while(n!=0)
        {
            int q=n&1;
            
            if(q==1)
            {
                if(start==-1) start=idx;
                else
                {
                    ans=max(ans,idx-start);
                    start=idx;
                }
            }
            
            ++idx;
            n=n>>1;
        }
                
        return ans;
    }
};

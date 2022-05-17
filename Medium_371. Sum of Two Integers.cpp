class Solution {
public:
    int getSum(int a, int b)
    {
        int res=0;
        int carry=0;
        
        for(int i=0; i<=11; ++i)
        {
            int ai=a & 1;
            int bi=b & 1;
            
            int sum=ai ^ bi ^ carry;
            carry= (ai&bi) | (bi&carry) | (ai&carry);
            
            res=res | (sum<<i);
            a=a>>1;
            b=b>>1;
        }
        
        return res;
    }
};

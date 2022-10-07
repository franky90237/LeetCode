//2022-05-18
//time  : O(32)
//space : O(1)
class Solution {
public:
    int getSum(int a, int b)
    {
        int res=0;
        int carry=0;
        
        for(int i=0; i<=31; ++i)
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

//2022-05-18
class Solution {
public:
    int getSum(int a, int b)
    {
        int res=a;
        int carry=b;
        
        while(carry!=0)
        {
            int tmp=res&carry;
            res=res^carry;
            carry=(unsigned)tmp<<1;
            
            //cout<<res<<" "<<carry<<endl;
        }
        
        return res;
    }
};

//2022-10-07
//time  : O(32)
//space : O(1)
class Solution {
public:
    int getSum(int a, int b) 
    {    
        while(b != 0)
        {
            unsigned int carry=a&b;
            int sum=a^b;
            
            a=sum;
            b=carry<<1;
        }
        
        return a;
    }
};

//2022-10-07
//time  : O(32)
//space : O(1)
class Solution {
public:
    int getSum(int a, int b) 
    {
        int ans=0;
        
        int carry=0;
        int sum=0;
        unsigned int x=1;
        for(int i=0; i<32; ++i)
        {     
            int aBit = a & x;
            int bBit = b & x;
            
            sum = aBit ^ bBit ^ carry;
            carry = (aBit & bBit) | (aBit & carry) | (bBit & carry);            
            carry = (unsigned int)carry << 1;
            ans = ans | sum;
            
            x = x << 1;
        }
                
        
        return ans;
    }
};

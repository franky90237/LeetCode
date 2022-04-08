//time  : O(n*n)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        //string res_bit=convert_to_bit(n);
        
        uint32_t res=0;
        
        uint32_t multiplier=pow(2,31);
        while(n!=0)
        {
            res+=(n%2)*multiplier;
            n=n/2;
            multiplier/=2;
        }
        
        return res;
    }
    
    string convert_to_bit(uint32_t n)
    {
        string res="";
        
        int bit=0;
        while(bit<=31)
        {
            res+=(n%2)+'0';
            n=n/2;
            ++bit;
        }
        
        cout<<res;
        
        return res;
    }
};

//bit manipulation
//time  : O(n)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res=0;
        int bit=31;
        while(bit>=0)
        {
            res=(res<<1) | (n&1);
            n=n>>1;
            --bit;
        }
        
        return res;
    }
};

//time  : O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {        
        n = (n >> 16) | (n << 16);
        
        //ff00=0x 11111111 00000000, 00ff=0x 00000000 11111111
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        
        //f0=0x 1111 0000, 0f=0x 0000 1111
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        
        //c=0x 1100, 5=0x 0011
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        
        //a=0x 10 10, 5=0x 01 01
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
};

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

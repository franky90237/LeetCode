//2023-11-19
//time  : O(n*n)
//space : O(1)
class Solution {   
public:
    int maximumXorProduct(long long a, long long b, int n) 
    {
        /*
        
        (a - z) * (b + z)
        a*b + (a-b)*z - z*z
        
        */    
        long long ans = 0;
        long long modulo = 1e9+7;
        
        for(long long bit=n-1; bit>=0; --bit)
        {
            long long bitA = (a>>bit)&1;
            long long bitB = (b>>bit)&1;
            
            //cout<<bit<<" | "<<bitA<<" "<<bitB<<" : "<<endl;
            if(bitA != bitB)
            {               
                if(a > b)
                {
                    a ^= bitA<<bit;
                    b ^= bitA<<bit;
                }
                else  
                {
                    a ^= bitB<<bit;
                    b ^= bitB<<bit;
                }
            }
            else
            {
                a ^= (long long)(!bitA)<<bit;
                b ^= (long long)(!bitA)<<bit;                
            }
        }
        
        ans = ((a%modulo) * (b%modulo)) % modulo;
        return ans;
    }    
};

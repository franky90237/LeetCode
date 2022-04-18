//2022-04-18
//TLE
//time  : O(n^(1.5))
//space : O(1)
class Solution {
public:
    bool isUgly(int n) 
    {
        if(n<=0) return false;
        if(n==1) return true;
        
        for(int i=7; i<=n; ++i)
        {
            if(is_prime(i) && n%i==0) return false;
        }
        
        return true;
    }
    
    bool is_prime(int n)
    {
        for(int i=2; i<=n/i; ++i)
        {
            if(n%i==0) return false;
        }
        
        return true;
    }
};

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

//2022-04-18
//time  : O(n^{1.25})
//space : O(1)
class Solution {
public:
    bool isUgly(int n) 
    {
        if(n<=0) return false;
        if(n==1) return true;        
                
        for(int i=1; i<=n/i; ++i)
        {
            //cout<<i<<endl;
            if(n%i==0) 
            {
                int quotient=n/i;                
                if((i>5 && is_prime(i)) || (quotient>5 && is_prime(quotient)))
                {
                    return false;
                }                
            }
        }
        
        return true;
    }
    
    bool is_prime(int n)
    {
        if(n==1) return false;
        
        for(int i=2; i<=n/i; ++i)
        {
            if(n%i==0) return false;
        }
        
        return true;
    }
};

//2022-04-18
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    bool isUgly(int n) 
    {
        if(n<=0) return false;        
        
        while(n>1)
        {
            if(n%2==0) n/=2;
            else if(n%3==0) n/=3;
            else if(n%5==0) n/=5;
            else return false;
        }        
        
        return true;
    }    
};

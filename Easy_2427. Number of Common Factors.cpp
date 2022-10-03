//2022-10-03
//time  : O(gcd(a,b))
//space : O(1)
class Solution {
public:
    int commonFactors(int a, int b) 
    {
        int n=gcd(a,b);
        int cnt=1;
        for(int i=2; i<=n; ++i)
        {
            if(a%i == 0 && b%i == 0) ++cnt;
        }
        
        return cnt;
    }
    
    int gcd(int a, int b)
    {
        //gcd(12,4)=gcd(4,0)
        //gcd(4,12)=gcd(12,4)
        //gcd(12,5)=gcd(5,2)=gcd(2,1)=gcd(1,0)
        
        while(b != 0)
        {
            int tmp=a;
            a=b;
            b=tmp%b;
        }
        
        return a;
    }
};

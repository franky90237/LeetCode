//2022-04-18
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int countPrimes(int n) 
    {
        int cnt=0;
        for(int i=2; i<n; ++i)
        {
            bool isPrime=true;
            
            for(int j=2; j<i; ++j)
            {
                if(i%j==0)
                {
                    isPrime=false;
                    break;
                }
            }
            
            if(isPrime) ++cnt;
        }
        
        return cnt;
    }
};

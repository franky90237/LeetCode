//2022-04-20
//time  : O(log(3)(n))
//space : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n<=0) return false;
        
        while(n%3==0)
        {            
            n=n/3;
        }
        
        return n==1;
    }
};

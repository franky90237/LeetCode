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

//2022-04-20
//1162261467=3^19
//3^19 is biggiest power of three int the range of INT_MAX
//time  : O(1)
//space : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        return n > 0 && 1162261467 % n == 0;
    }
};

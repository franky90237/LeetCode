//2022-04-21
//time  : O(n)
//space : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int cnt=0;
        while(n>0)
        {
            cnt+=n%2;
            n=n>>1;
        }
        
        return cnt;
    }
};

//2022-04-21
//time  : O(k), k is the number of 1 in n 
//space : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int cnt=0;
        while(n>0)
        {
            ++cnt;
            n=n&(n-1);
        }
        
        return cnt;
    }
};

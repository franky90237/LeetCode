//2022-04-19
//TLE
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int nthUglyNumber(int n)
    {
        int cnt=0;
        int num=1;
        
        while(cnt<n)
        {
            if(isUgly(num))
            {
                ++cnt;
            }
            
            ++num;
        }
        
        return num-1;
    }
    
    bool isUgly(int n) 
    {     
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        
        return n==1;
     }   
};

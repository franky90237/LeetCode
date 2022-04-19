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

//2022-04-19
//time  : O(n)
//space : O(1)
class Solution {
public:
    int nthUglyNumber(int n) 
    {
        if(n==1) return n;
        
        int num[n];
        num[0]=1;
        int p2=0, p3=0, p5=0;
        
        int cnt=1;
        while(cnt<n)
        {
            num[cnt]=min(num[p2]*2,min(num[p3]*3,num[p5]*5));
            
            if(num[cnt]==num[p2]*2) ++p2;
            if(num[cnt]==num[p3]*3) ++p3;
            if(num[cnt]==num[p5]*5) ++p5;
            
            ++cnt;
        }
        
        return num[n-1];
    }
};

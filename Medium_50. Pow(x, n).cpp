//2023-08-17
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    double myPow(double x, long long n) 
    {
        if(x == 1 || n == 0) return 1;
        if(x == -1) return (n % 2 == 0) ? 1 : -1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        
        /*        
        1 1 1  1   1  = 31 = n
        0 1 2  3   4
        1 2 4  8   16
        2 4 16 256 65536
        */
                
        if(n < 0)
        {
            n = -n;
            x = 1/x;
        }
        
        double cur=x;
        double ans=1;        
        while(n != 0)
        {
            int bit=n&1;
            if(bit == 1)
            {
                ans *= cur;
            }
            
            //cout<<n<<" | "<<ans<<" "<<cur<<endl;
            cur *= cur;
            n >>= 1;        
        }
                
        return ans;
    }
};

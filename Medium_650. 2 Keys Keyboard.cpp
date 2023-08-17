//2023-08-18
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int minSteps(int n) 
    {        
        /*
        CPPP CPPP CPPPPPP
        a    b    c

        1*a*b*c*..=n

        21 =3*7
        3+7
        */
        if(n == 1) return 0;
        
        int ans=0;
        for(int i=2; i*i<=n; ++i)
        {
            int cnt=0;
            while(n % i == 0)
            {
                ++cnt;
                n /= i;
            }
            
            //cout<<i<<" "<<cnt<<endl;
            ans += i*cnt; 
        }
                
        if(n != 1) ans += n;
        return ans;
    }
};

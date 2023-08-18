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

//2023-08-18
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<int> dp;
    
public:
    int minSteps(int n) 
    {                
        if(n == 1) return 0;
        
        dp.resize(n+1, -1);
        return solve(1, n);
    }
    
    int solve(int cnt, int n)
    {
        if(cnt == n) return 0;
        if(cnt > n) return INT_MAX;
        if(dp[cnt] != -1) return dp[cnt];
        
        int ans=INT_MAX;
        int i=2;
        int cur=i*cnt;        
        while(cur <= n)
        {
            int res=solve(cur, n);
            if(res != INT_MAX) res += i; 
            ans=min(ans, res);
                        
            ++i;
            cur=i*cnt;
        }
        
        dp[cnt]=ans;
        return ans;
    }
};

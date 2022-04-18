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

//2022-04-18
//time  : O(n^(1.5))
//space : O(1)
class Solution {
public:
    int countPrimes(int n) 
    {
        int cnt=0;
        for(int i=2; i<n; ++i)
        {
            bool isPrime=true;
            
            for(int j=2; j<=sqrt(i); ++j)
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

//2022-04-18
//time  : O(?)
//space : O(n)
class Solution {
public:
    int countPrimes(int n) 
    {
        if(n==0 || n==1) return 0;
        
        vector<int> prime_set;
        int root=sqrt(n);
        for(int i=2; i<=root; ++i)
        {
            if(is_prime(i)) prime_set.push_back(i);
        }
        
        int num[n];
        for(int i=2; i<n; ++i)
        {
            for(auto& prime:prime_set)
            {
                if(i!=prime && i%prime==0) 
                {
                    num[i]=1;
                    break;
                }
                else num[i]=0;
            }
        }
        
        int cnt=0;
        for(int i=2; i<n; ++i)
        {
            if(num[i]!=1) 
            {
                //cout<<i<<endl;
                ++cnt;
            }
        }
        
        return cnt;
    }
    
    bool is_prime(int n)
    {
        for(int i=2; i*i<=n; ++i)
        {
            if(n%i==0) return false;
        }
        
        return true;
    }
};

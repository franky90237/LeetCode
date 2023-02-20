//2023-02-20
//time  : O(n*1024*10)
//space : O(n*1024)
class Solution 
{
private:
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    
public:
    int squareFreeSubsets(vector<int>& nums)
    {
        dp.resize(1000, vector<int>(1024, -1));
                
        vector<int> rest;                
        for(auto num: nums)
        {            
            if(num % 4 == 0 || num % 9 == 0 || num % 16 == 0 || num % 25 == 0)
            {
                continue;
            }
            
            rest.push_back(num);
            //cout<<num<<" ";
        }        
        
        return (solve(rest, 0, 0) -1 + mod) % mod;
    }
    
    long solve(vector<int>& rest, int cur, int bit_mask)
    {
        int n=rest.size();
        if(cur >= n)
        {
            return 1;
        }
        if(dp[cur][bit_mask] != -1)
        {
            return dp[cur][bit_mask];
        }
        
        long pick=0;
        long not_pick=0;        
        int new_bit_mask=bit_mask;
        
        if(check(rest[cur], new_bit_mask))
        {            
            pick=solve(rest, cur+1, new_bit_mask) % mod;
        }        
        not_pick=solve(rest, cur+1, bit_mask) % mod;
        
        //cout<<cur<<" : "<<pick<<" "<<not_pick<<endl;
        dp[cur][bit_mask]=(pick + not_pick) % mod;
        return dp[cur][bit_mask];
    }
    
    bool check(int num, int& bit_mask)
    {                        
        for(int i=0; i<primes.size(); ++i)
        {
            //cout<<num<<" "<<primes[i]<<endl;
            int p=primes[i];
            
            if(num < p)
            {
                break;
            }
            
            while(num % p == 0)
            {                
                if((bit_mask & (1 << i)) > 0)
                {                    
                    return false;
                }
                
                bit_mask |= (1 << i);
                
                num /= p;
            }
        }
        //cout<<endl;
        
        return true;
    }
};

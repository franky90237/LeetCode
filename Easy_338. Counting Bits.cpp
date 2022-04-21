//2022-04-21
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n==0) return {0};
        
        vector<int> res(n+1,0);
        res[0]=0;
        res[1]=1;
        
        int base=1;
        for(int i=2; i<=n; ++i)
        {
            if(65536%i==0)
            {
                res[i]=1;
                base=i;
            }
            else
            {
                int diff=i-base;
                res[i]=1+res[diff];
            }
        }
        
        return res;
    }
};

//2023-12-04
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) 
    {
        sort(coins.begin(), coins.end());
        
        int n=coins.size();
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            if(ans+1 < coins[i]) break;
            ans += coins[i];
        }

        return ans+1;
    }
};

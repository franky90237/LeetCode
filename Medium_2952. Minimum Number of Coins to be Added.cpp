//2023-12-03
//time  : O(nlog(n) + log(target))
//space : O(1)
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target)
    {
        int n=coins.size();
        sort(coins.begin(), coins.end());         
        
        int ans=0;
        int idx=0;
        int maxVal=1;       
        while(maxVal-1 < target)
        {
            if(idx < n && maxVal >= coins[idx])
            {
                maxVal += coins[idx];
                ++idx;
            }
            else
            {
                maxVal += maxVal;
                ++ans;
            }
        }
        
        return ans;
    }
};

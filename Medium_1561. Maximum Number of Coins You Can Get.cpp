//2022-12-28
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(), piles.end());
        
        int n=piles.size();
        int cnt=n/3;
        int sum=0;
        for(int i=n-2; cnt!=0; i-=2)
        {
            sum += piles[i];
            --cnt;
        }
        
        return sum;
    }
};

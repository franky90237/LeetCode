//2022-11-01
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        
        /*
        sum(t-ni)
        (t-n1)+(t-n2)+...+(t-nk)+(t-t)+(nk2-t)+(nk3-t)+...+(nx-t)
        preCnt*t-sum(n1 ~ nk) + sum(nk2 ~ nx)-postCnt*t
        */
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int prefixSum[n+1];
        prefixSum[0]=0;
        for(int i=1; i<=n; ++i)
        {
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        }
        
        long long ans=INT_MAX;
        for(int i=0; i<n; ++i)
        {
            long long left = (long long)(i-0)*nums[i] - (long long)prefixSum[i];
            long long right = (long long)(prefixSum[n]-prefixSum[i+1]) - (long long)(n-1-i)*nums[i];
            long long move = left+right;
            ans=min(ans, move);
        }
        
        return ans;
    }
};

//2023-09-03
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        int n=nums.size();
        unordered_map<int, long long> qCnt;
        qCnt[0]=1;
        int cnt=0;
        long long ans=0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] % modulo == k) ++cnt;
            
            int q=cnt%modulo;            
            int target=(q+modulo-k)%modulo;
            ans += qCnt[target];
            ++qCnt[q];
        }
        
        return ans;
    }
};

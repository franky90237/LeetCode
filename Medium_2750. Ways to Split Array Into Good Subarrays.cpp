class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> idx;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] == 1) idx.push_back(i);
        }
        
        n=idx.size();
        if(n == 0) return 0;
        
        int modulo=1e9+7;
        long long ans=1;
        for(int i=1; i<n; ++i)
        {
            ans = ans*(idx[i]-idx[i-1])%modulo;
        }
        
        return ans;
    }
};

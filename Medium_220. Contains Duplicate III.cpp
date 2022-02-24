class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n && j-i<=k; ++j)
            {
                if((long)abs((long)nums[i]-(long)nums[j])<=(long)t) return true;
            }
        }
        
        return false;
    }
};

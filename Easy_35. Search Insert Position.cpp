//2022-12-24
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int l=0;
        int r=nums.size()-1;
        if(target > nums[r]) return r+1;
        if(target < nums[0]) return 0;
        
        while(l < r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid] < target) l=mid+1;
            else r=mid;
        }
        
        return l;
    }
};

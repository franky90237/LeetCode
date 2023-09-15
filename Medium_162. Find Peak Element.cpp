//2023-09-16
//time  : O(log(n))
//spcae : O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size() == 1) return 0;
        
        int left=0;
        int right=nums.size()-1;
        int ans=0;
        while(left <= right)
        {
            int mid=left+(right-left)/2;
            if(mid+1 >= nums.size() || nums[mid] > nums[mid+1])
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return ans;
    }
};

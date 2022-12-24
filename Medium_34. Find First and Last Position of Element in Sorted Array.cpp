//2022-12-24
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {        
        if(nums.empty() || target > nums.back() || target < nums[0]) return {-1, -1};
        
        vector<int> ans(2, -1);
        
        int l=0;
        int r=nums.size()-1;
        while(l < r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<", "<<mid<<", "<<r<<endl;
            if(nums[mid] < target) l=mid+1;
            else if(nums[mid] > target) r=mid-1;
            else r=mid;
        }
        if(nums[l] == target) ans[0]=r;
        
        l=0;
        r=nums.size()-1;
        while(l < r)
        {
            int mid=r-(r-l)/2;
            //cout<<l<<", "<<mid<<", "<<r<<endl;
            if(nums[mid] < target) l=mid+1;
            else if(nums[mid] > target) r=mid-1;
            else l=mid;
        }
        if(nums[l] == target) ans[1]=l;
        
        return ans;
    }
};

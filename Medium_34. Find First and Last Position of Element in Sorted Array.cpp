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

//2023-09-14
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int i1=bsL(nums, target);
        int i2=bsR(nums, target);
        return {i1, i2};
    }
    
    int bsL(vector<int>& nums, int target)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=r+1;
        while(l <= r)
        {
            int m=l+(r-l)/2;
            if(nums[m] >= target)
            {
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        
        return (ans<nums.size() && nums[ans]==target) ? ans : -1;
    }
    

    int bsR(vector<int>& nums, int target)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=r+1;
        while(l <= r)
        {
            int m=l+(r-l)/2;
            if(nums[m] <= target)
            {
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        
        return (ans<nums.size() && nums[ans]==target) ? ans : -1;
    }
};

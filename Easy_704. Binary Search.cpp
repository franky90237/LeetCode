//2022-09-20
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int l=0;
        int r=nums.size()-1;
        
        while(l<r)
        {
            int mid=l+(r-l)/2;
                    
            if(target>nums[mid]) l=mid+1;
            else r=mid;
        }
        
        return nums[r]==target ? r : -1;
    }
};

//2022-09-20
//time  : O(log(n))
//space : O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        return solve(nums, target, 0, nums.size()-1);
    }
    
    int solve(vector<int>& nums, int target, int l, int r)
    {
        if(l>r) return -1;
        
        int mid=l+(r-l)/2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return solve(nums, target, mid+1, r);
        else return solve(nums, target, l, mid-1);
    }
};

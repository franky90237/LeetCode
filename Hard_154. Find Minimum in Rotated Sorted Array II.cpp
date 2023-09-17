//2023-09-17
//time  : O(n)
//space : O(1)
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        return solve(nums, 0, nums.size()-1);
    }
    
    int solve(vector<int>& nums, int left, int right)
    {
        int n=nums.size();
        if(left >= right) return nums[left];
        
        int mid=left+(right-left)/2;
        if(nums[mid] == nums[right])
        {
            int leftPart=solve(nums, left, mid-1);
            int rightPart=solve(nums, mid+1, right);
            return min(leftPart, rightPart);
        }
        else if(nums[mid] < nums[right])
        {
            return solve(nums, left, mid);       
        }
        else
        {
            return solve(nums, mid+1, right);
        }
    }
};

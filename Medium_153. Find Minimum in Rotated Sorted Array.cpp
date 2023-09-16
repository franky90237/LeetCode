//2022-05-24
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        while(left<right)
        {
            mid=(left+right)/2;
            
            if(nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        
        return nums[left];
    }
};

//2022-09-21
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]<=nums[r])
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return nums[l];
    }
};

//2023-09-16
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size();
        if(n == 1) return nums[0];
        
        int left=0;
        int right=n-1;        
        while(left < right)
        {
            int mid=left+(right-left)/2;
                        
            if(nums[mid] > nums[right])
            {                
                left=mid+1;
            }
            else
            {                
                right=mid;
            }
        }
        
        return nums[right];
    }
};

//2022-05-25
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;
        
        while(left<=right)
        {
            int mid=(left+right)/2;
            //printf("%d %d %d\n",nums[left],nums[mid],nums[right]);
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]<nums[right])
            {
                if(nums[mid]<target && target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
            else
            {
                if(nums[left]<=target && target<nums[mid]) right=mid-1;
                else left=mid+1;
            }
        }
        
        return -1;
    }
};

//2022-09-20
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int l=0;
        int r=nums.size()-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(target==nums[mid]) return mid;
            
            if(nums[l]<=nums[mid])
            {                
                if(nums[l]<=target && target<nums[mid]) r=mid-1;
                else l=mid+1;
            }
            else
            {
                if(nums[mid]<target && target<=nums[r]) l=mid+1;
                else r=mid-1;
            }
        }
        
        return -1;
    }
};

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
            
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        
        //cout<<nums[l]<<endl;              
        
        int left_part=binary_search(nums, 0, l-1, target);
        if(left_part!=-1) return left_part;
        
        int right_part=binary_search(nums, l, nums.size()-1, target);
        return right_part;        
    }
    
    int binary_search(vector<int>& nums, int l, int r, int target)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(target==nums[mid]) return mid;
            else if(target>nums[mid]) l=mid+1;
            else r=mid-1;
        }
        
        return -1;
    }
};

//2023-09-16
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left <= right)
        {
            int mid=left+(right-left)/2;
            
            if(target == nums[mid])
            {
                return mid;
            }
            
            if(nums[mid] < nums[right])
            {
                if(nums[mid] <= target && target <= nums[right]) left=mid+1;
                else right=mid-1;
            }
            else
            {
                if(nums[left] <= target && target <= nums[mid]) right=mid-1;
                else left=mid+1;
            }
        }
                
        return -1;
    }
};

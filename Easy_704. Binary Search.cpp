//2022-09-20
//time  : O(long(n))
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

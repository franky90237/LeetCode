//2022-09-01
//time  : O(n)
//sapce : O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n=nums.size();
        int left=0;
        int right=n-1;
        
        vector<int> ans(n,0);
        int i=n-1;
        
        while(left<=right)
        {
            if(abs(nums[left])>abs(nums[right]))
            {
                ans[i]=nums[left]*nums[left];
                ++left;
            }
            else
            {
                ans[i]=nums[right]*nums[right];
                --right;
            }
            
            --i;
        }
        
        return ans;
    }
};

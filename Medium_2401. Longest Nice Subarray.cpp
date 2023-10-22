//2023-10-22
//time  : O(n)
//space : O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int val=0;
        int ans=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            while((val & nums[right]) != 0)
            {
                val &= ~nums[left];
                ++left;
            }
            
            val |= nums[right];
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};

//2022-12-02
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
    {
        int n=nums.size();
        vector<int> dp(n, 0);
        //dp[0]= (left <= nums[0] && nums[0] <= right) ? 1 : 0;
        
        int ans=0;
        int pre_greater_right_idx=-1;
        int pre_bounded_idx=-1;
        for(int i=0; i<n; ++i)
        {
            if(left <= nums[i] && nums[i] <= right)
            {
                dp[i]=i-pre_greater_right_idx;
                pre_bounded_idx=i;
            }
            else if(nums[i] < left)
            {                
                dp[i] = pre_bounded_idx - pre_greater_right_idx;
                if(dp[i] < 0) dp[i]=0;
            }
            else
            {
                pre_greater_right_idx=i;
            }
            
            ans += dp[i];
        }
        
        return ans;
    }
};

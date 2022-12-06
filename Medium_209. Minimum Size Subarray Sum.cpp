//2022-12-06
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int ans=n+1;
        int sum=0;
        int left=0;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            while(left <= i && sum >= target)
            {
                ans=min(ans, i-left+1);
                sum -= nums[left];
                ++left;
            }
        }
        
        return ans==n+1 ? 0 : ans;
    }
};

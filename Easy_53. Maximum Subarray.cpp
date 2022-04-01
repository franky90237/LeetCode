//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int maximum=nums[0];
        int sum=nums[0];
        
        for(int i=1; i<n; ++i)
        {
            sum+=nums[i];
            if(sum<nums[i]) 
            {
                sum=nums[i];
            }
            
            maximum=max(maximum,sum);
        }
        
        return maximum;
    }
};

//2023-10-03
//time  : O(n)
//space : O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n=nums.size();
        int first=nums[0];
        int second=nums[0];
        long long maxDiff=0;
        long long ans=0;
        for(int i=1; i<n-1; ++i)
        {
            if(nums[i] > first)
            {
                first=nums[i];
                second=nums[i];
            }
            else if(nums[i] < second)
            {
                second=nums[i];
            }
            
            maxDiff=max(maxDiff, (long long)first-second);
            ans=max(ans, maxDiff*nums[i+1]);
        }
        
        return ans;
    }
};

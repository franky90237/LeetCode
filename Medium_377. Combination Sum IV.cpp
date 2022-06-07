//2022-06-08
//TLE
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        return solve(0,nums,target);
    }
    
    int solve(int now, vector<int>& nums, int target)
    {
        int n=nums.size();
        if(now>=n || target<0) return 0;
        if(target==0) return 1;
        
        int sum=0;
        for(int i=now; i<n; ++i)
        {
            sum+=solve(0,nums,target-nums[i]);
        }
        
        return sum;
    }
};

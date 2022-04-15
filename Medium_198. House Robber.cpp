//2022-04-15
//TLE
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        return solve(nums,0);
    }
    
    int solve(vector<int>& nums, int now)
    {     
        if(now>=nums.size()) return 0;
               
        return max(nums[now]+solve(nums,now+2), solve(nums,now+1));
    }
};

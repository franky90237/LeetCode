//2023-09-23
//time  : O(n)
//spcae : O(n)
class Solution 
{
private:
    vector<vector<long long>> dp;
    
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n=nums.size();
        dp.resize(n, vector<long long>(2, -1));
        return solve(nums, 0, true);
    }
    
    long long solve(vector<int>& nums, int cur, bool isPlus)
    {
        int n=nums.size();
        if(cur >= n) return 0;
        if(dp[cur][isPlus] != -1) return dp[cur][isPlus];
        
        int sign=isPlus ? 1 : -1;        
        long long pick=sign*nums[cur]+solve(nums, cur+1, !isPlus);
        long long notPick=solve(nums, cur+1, isPlus);
        
        dp[cur][isPlus]=max(pick, notPick);
        return dp[cur][isPlus];
    }
};

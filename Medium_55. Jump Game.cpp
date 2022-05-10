//2022-05-10
//dp recursive
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        bool dp[n];
        for(int i=0; i<n; ++i) dp[i]=true;
        return solve(nums,dp,0);
    }
    
    bool solve(vector<int>& nums, bool dp[], int now)
    {
        int n=nums.size();
        if(now>=n-1) return true;
        if(!dp[now]) return false;
        
        for(int i=1; i<=nums[now]; ++i)
        {
            bool isLast=solve(nums,dp,now+i);
            if(isLast) return true;
        }
        
        dp[now]=false;
        return false;
    }
};

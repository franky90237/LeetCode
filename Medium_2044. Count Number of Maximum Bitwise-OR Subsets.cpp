//2023-10-28
//time  : O(2^n)
//space : O(n)
class Solution 
{
private:
    int target=0;
    int ans=0;
    
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        for(int num: nums) target |= num;
        
        solve(nums, 0, 0);
        return ans;
    }
    
    void solve(vector<int>& nums, int cur, int idx)
    {
        int n=nums.size();
        if(idx >= n || cur > target) return;
        
        if((cur|nums[idx]) == target) ++ans;
        solve(nums, cur|nums[idx], idx+1);
        solve(nums, cur, idx+1);
    }
};

//2023-10-28
//time  : O(2^n)
//space : O(n)
class Solution 
{
private:
    int target=0;    
    
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        for(int num: nums) target |= num;
        
        return solve(nums, 0, 0);        
    }
    
    int solve(vector<int>& nums, int cur, int idx)
    {
        int n=nums.size();
        if(idx >= n) return cur==target;
                
        int pick=solve(nums, cur|nums[idx], idx+1);
        int notPick=solve(nums, cur, idx+1);
        return pick+notPick;
    }
};

//2023-10-28
//time  : O(n*100000)
//space : O(n*100000)
class Solution 
{
private:
    int target=0;
    vector<vector<int>> dp;
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        for(int num: nums) target |= num;
        
        dp.resize(nums.size(), vector<int>(target+1, -1));
        return solve(nums, 0, 0);        
    }
    
    int solve(vector<int>& nums, int cur, int idx)
    {
        int n=nums.size();
        if(idx >= n) return cur==target;
        if(dp[idx][cur] != -1) return dp[idx][cur];
                
        int pick=solve(nums, cur|nums[idx], idx+1);
        int notPick=solve(nums, cur, idx+1);
        
        dp[idx][cur]=pick+notPick;        
        return dp[idx][cur];
    }
};

//2023-10-29
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<long long>> dp;
    
public:
    long long minIncrementOperations(vector<int>& nums, int k) 
    {
        int n=nums.size();
        dp.resize(n, vector<long long>(3, -1));
        return solve(nums, k, 2, 0);
    }
    
    long long solve(vector<int>& nums, int k, int idx, int rest)
    {
        int n=nums.size();
        if(idx >= n) return 0;
        if(dp[idx][rest] != -1) return dp[idx][rest];
        
        if(rest > 0)
        {
            dp[idx][rest]=solve(nums, k, idx+1, rest-1);
            return dp[idx][rest];
        }
        
        for(int i=idx-2; i<=idx; ++i)
        {            
            if(nums[i] >= k) 
            {
                dp[idx][rest]=solve(nums, k, idx+1, rest);
                return dp[idx][rest];
            }
        }
        
        long long ans=LLONG_MAX;
        for(int i=idx-2; i<=idx; ++i)
        {
            if(nums[i] < k)
            {
                long long diff=(long long)k-nums[i];
                long long cost=solve(nums, k, idx+1, 2-(idx-i));
                //cout<<idx<<" | "<<diff<<" "<<cost<<endl;
                ans = min(ans, diff+cost);
            }            
        }
        
        dp[idx][rest]=ans;
        return ans;
    }
};

//2023-10-30
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<long long> dp;
    
public:
    long long minIncrementOperations(vector<int>& nums, int k) 
    {
        int n=nums.size();
        dp.resize(n, -1);
        return solve(nums, k, 0);
    }
    
    long long solve(vector<int>& nums, int k, int idx)
    {
        int n=nums.size();
        if(idx+2 >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        long long ans=LLONG_MAX;
        for(int i=idx; i<=idx+2; ++i)
        {
            long long cost=max(0, k-nums[i]);
            cost += solve(nums, k, i+1);
            ans=min(ans, cost);
        }
        
        dp[idx]=ans;
        return ans;
    }
};

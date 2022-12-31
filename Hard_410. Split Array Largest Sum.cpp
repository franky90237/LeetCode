//2022-12-31
//time  : O(nlog(sum(n)))
//space : O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int k)
    {        
        int l=nums[0];
        int r=nums[0];
        for(int i=1; i<nums.size(); ++i)
        {
            l=max(l, nums[i]);
            r += nums[i];
        }
        
        /*int ans=l;
        for(int i=l; i<=r; ++i)
        {
            if(check(nums, k, i))
            {
                ans=i;
                break;
            }
        }
        
        return ans;*/
        
        int ans=0;
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(check(nums, k, mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums, int k, int target)
    {
        int n=nums.size();        
        int sum=0;
        int cnt=1;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            if(sum > target)
            {
                sum=nums[i];
                ++cnt;
            }
        }
        
        return cnt <= k;
    }
};

//2022-12-31
//time  : O(n*n*k)
//space : O(n*k)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int splitArray(vector<int>& nums, int k)
    {        
        int n=nums.size();
        
        vector<int> prefix_sum(n+1);
        prefix_sum[0]=0;        
        for(int i=1; i<=n; ++i)
        {
            prefix_sum[i]=nums[i-1]+prefix_sum[i-1];
        }
        
        dp.resize(n, vector<int>(k+1, -1));
        return solve(nums, prefix_sum, 0, k);
    }
    
    int solve(vector<int>& nums, vector<int>& prefix_sum, int cur, int k)
    {
        int n=nums.size();
        if(k == 1) return prefix_sum[n]-prefix_sum[cur];
        if(dp[cur][k] != -1)
        {
            return dp[cur][k];
        }
        
        int sum=0;
        int ans=INT_MAX;
        for(int i=cur; i<=n-k; ++i)
        {
            sum += nums[i];
            int largestSum=max(sum, solve(nums, prefix_sum, i+1, k-1));
            ans=min(ans, largestSum);
        }
        
        dp[cur][k]=ans;
        return ans;
    }
};

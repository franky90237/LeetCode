//2023-04-11
//time  : O(nlog(max(nums)))
//space : O(n)
class Solution {
public:
    int minCapability(vector<int>& nums, int k)
    {
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto num: nums)
        {
            low=min(low, num);
            high=max(high, num);
        }
        
        int ans=low;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            
            if(check(nums, k, mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums, int k, int target)
    {
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0] <= target;
        
        for(int i=1; i<n; ++i)
        {
            int notPick = 0;
            int pick = dp[i-1];
            
            if(i-1 >= 0)
            {
                notPick=dp[i-1];
            }
            if(nums[i] <= target)
            {                
                if(i-2 >= 0) pick=1+dp[i-2];
                else pick=1;
            }
            
            dp[i] = max(notPick, pick);
            if(dp[i] >= k)
            {
                return true;
            }
        }
        
        return false;
    }
};

//2023-04-11
//time  : O(nlog(max(nums)))
//space : O(1)
class Solution {
public:
    int minCapability(vector<int>& nums, int k)
    {
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto num: nums)
        {
            low=min(low, num);
            high=max(high, num);
        }
        
        int ans=low;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            if(check(nums, k, mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums, int k, int target)
    {
        int n=nums.size();
        int pre1=0;
        int pre2=0;    
        
        for(int i=0; i<n; ++i)
        {
            int notPick = pre1;
            int pick = pre1;
                    
            if(nums[i] <= target)
            {                
                pick=1+pre2;                
            }
            
            int cur = max(notPick, pick);
            //cout<<i<<" : "<<pre2<<" "<<pre1<<" "<<cur<<endl;
            if(cur >= k)
            {
                return true;
            }
            
            pre2=pre1;
            pre1=cur;            
        }
        
        return false;
    }
};

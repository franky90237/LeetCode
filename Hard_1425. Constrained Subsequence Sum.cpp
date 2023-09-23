//2023-09-23
//time  : O(nlog(n))
//spcae : O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {        
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        
        multiset<int> preMax;
        preMax.insert(0);
        preMax.insert(dp[0]);
        
        int left=0;
        int ans=dp[0];
        for(int i=1; i<n; ++i)
        {
            while(i-left > k)
            {
                preMax.erase(preMax.find(dp[left]));
                ++left;
            }
            
            dp[i]=*(preMax.rbegin());            
            dp[i] += nums[i];
            
            preMax.insert(dp[i]);
            ans=max(ans, dp[i]);
        }
        
        return ans;       
    }    
};

//2023-10-12
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<int>> dp;
    int maxLen;
    
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        dp.resize(n, vector<int>(2, -1));
        
        maxLen=1;
        longentSubarryEndingAt(nums1, nums2, n-1, true);
        longentSubarryEndingAt(nums1, nums2, n-1, false);
                
        return maxLen;
    }
    
    int longentSubarryEndingAt(vector<int>& nums1, vector<int>& nums2, int cur, bool isFirst)
    {
        if(cur == 0) return 1;
        if(dp[cur][isFirst] != -1) return dp[cur][isFirst];
        
        int ans1 = longentSubarryEndingAt(nums1, nums2, cur-1, true); 
        int ans2 = longentSubarryEndingAt(nums1, nums2, cur-1, false);
        
        if(isFirst)
        {
            if(nums1[cur] >= nums1[cur-1]) ++ans1;
            else ans1=1;
            if(nums1[cur] >= nums2[cur-1] ) ++ans2;
            else ans2=1;
        }
        else
        {            
            if(nums2[cur] >= nums1[cur-1]) ++ans1;
            else ans1=1;
            if(nums2[cur] >= nums2[cur-1] ) ++ans2;
            else ans2=1;
        }        
        
        dp[cur][isFirst] = max(ans1, ans2);
        maxLen=max(maxLen, dp[cur][isFirst]);
        return dp[cur][isFirst];
    }
};

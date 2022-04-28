//2022-04-28
//TLE
//dfs
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        return dfs(nums,0,-1);
    }
    
    int dfs(vector<int>& nums, int now, int pre)
    {
        int n=nums.size();
        if(now==n) return 0;
        
        int max_len=0;
        for(int i=now; i<n; ++i)
        {
            int len=0;
            if(pre==-1 || nums[now]>nums[pre])
            {
                len=1+dfs(nums,i+1,i);
            }
            
            max_len=max(max_len,len);
        }
        
        return max_len;
    }
};

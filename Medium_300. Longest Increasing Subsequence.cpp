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
            if(pre==-1 || nums[i]>nums[pre])
            {
                //cout<<i<<" "<<pre<<endl;
                int len=1+dfs(nums,i+1,i);
                max_len=max(max_len,len);
                
            }
        }
        
        //cout<<now<<"-"<<nums[now]<<" "<<"*"<<pre<<" "<<max_len<<endl;
        return max_len;
    }
};

//2022-04-28
//dp with dfs
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return dfs(dp,nums,0,-1);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& nums, int now, int pre)
    {
        int n=nums.size();
        if(now==n) return 0;
        
        if(dp[now][pre+1]!=-1) return dp[now][pre+1];
        
        int max_len=0;
        for(int i=now; i<n; ++i)
        {
            if(pre==-1 || nums[i]>nums[pre])
            {
                //cout<<i<<" "<<pre<<endl;
                int len=1+dfs(dp,nums,i+1,i);
                max_len=max(max_len,len);
                
            }
        }
        
        //cout<<now<<"-"<<nums[now]<<" "<<"*"<<pre<<" "<<max_len<<endl;
        dp[now][pre+1]=max_len;
        return max_len;
    }
};

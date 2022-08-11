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

//2022-05-12
//dp iterative
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=1;
        
        int LIS=1;
        for(int last=1; last<n; ++last)
        {
            for(int i=0; i<last; ++i)
            {
                if(nums[last]>nums[i])
                {
                    dp[last]=max(dp[last],1+dp[i]);
                }
                
                LIS=max(LIS,dp[last]);
            }
        }
        
        //for(int i=0; i<n; ++i) cout<<dp[i]<<" ";
        
        return LIS;
    }
};

//2022-05-12
//binary search
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> lis;
        
        lis.push_back(nums[0]);
        for(int i=1; i<n; ++i)
        {
            if(nums[i]>lis.back())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int idx=binary_search(lis,nums[i]);
                lis[idx]=nums[i];
            }
        }
        
        //for(int i=0; i<lis.size(); ++i) cout<<lis[i]<<" ";
        
        return lis.size();
    }
    
    int binary_search(vector<int>& lis, int target)
    {
        int left=0;
        int right=lis.size()-1;
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            
            if(target>lis[mid]) left=mid+1;
            else right=mid;
        }
        
        return left;
    }
};

//2022-08-11
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int dp[nums.size()];
        for(auto& i:dp) i=-1;
        
        return dfs(nums,-1,0,dp);
    }
    
    int dfs(vector<int>& nums, int pre, int cur, int dp[])
    {
        int n=nums.size();
        if(cur>=n) return 0;
        if(dp[pre+1]!=-1) return dp[pre+1];
        
        //cout<<pre<<" "<<cur<<endl;
        int pick=0;
        if(pre==-1 || nums[pre]<nums[cur]) pick = 1 + dfs(nums,cur,cur+1,dp);
        int not_pick = dfs(nums,pre,cur+1,dp);
        
        dp[pre+1]=max(pick,not_pick);
        return dp[pre+1];
    }
};

//2022-08-11
//dp iterative
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        
        int dp[n];
        for(auto& i:dp) i=1;        
        
        int ans=0;
        for(int i=0; i<nums.size(); ++i)
        {
            for(int pre=0; pre<i; ++pre)
            {
                if(nums[pre]<nums[i]) dp[i]=max(dp[i],dp[pre]+1);
            }
            
            ans=max(ans,dp[i]);
        }        
        
        return ans;
    } 
};

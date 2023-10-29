//2022-04-15
//TLE
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        return solve(nums,0);
    }
    
    int solve(vector<int>& nums, int now)
    {     
        if(now>=nums.size()) return 0;
               
        return max(nums[now]+solve(nums,now+2), solve(nums,now+1));
    }
};

//2022-04-15
//dp recursive
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=0;
        
        return solve(dp,nums,0);
    }
    
    int solve(int dp[], vector<int>& nums, int now)
    {        
        if(now>=nums.size()) return 0;
        if(dp[now]!=0) return dp[now];
        
        dp[now]=max(nums[now]+solve(dp,nums,now+2), solve(dp,nums,now+1));
        
        return dp[now];
    }
};

//2022-04-15
//dp iterative
//time  : O(n)
//space : O(n)
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n+1];
        
        dp[n]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2; i>=0; --i)
        {
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        
        return dp[0];
    }
};

//2022-04-15
//dp iterative
//time  : O(n)
//space : O(1)
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        
        int money2=0;
        int money1=nums[n-1];
        for(int i=n-2; i>=0; --i)
        {
            int tmp=money1;
            money1=max(nums[i]+money2,money1);
            money2=tmp;
        }    
        
        return money1;
    }
};

//2022-12-15
//time  : O(n)
//spcae : O(n)
class Solution 
{
private:
    int dp[101];
    
public:
    int rob(vector<int>& nums) 
    {
        memset(dp, -1, sizeof(dp));
        return dfs(nums, 0);
    }
    
    int dfs(vector<int>& nums, int cur)
    {
        int n=nums.size();
        if(cur >= n) return 0;
        if(dp[cur] != -1) return dp[cur];
            
        int steal=nums[cur]+dfs(nums, cur+2);
        int not_steal=dfs(nums, cur+1);
        
        dp[cur]=max(steal, not_steal);
        return dp[cur];
    }
};

//2022-12-15
//time  : O(n)
//spcae : O(n)
class Solution 
{
private:
    int dp[102];
    
public:
    int rob(vector<int>& nums) 
    {        
        int n=nums.size();
        dp[n]=0;
        dp[n+1]=0;
        
        for(int i=n-1; i>=0; --i)
        {
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }
        
        return dp[0];
    }       
};

//2023-10-29
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<int> dp;
    
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        dp.resize(n, -1);
        return dfs(nums, n-1);
    }
    
    int dfs(vector<int>& nums, int idx)
    {
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int steal=dfs(nums, idx-2) + nums[idx];
        int notSteal=dfs(nums, idx-1);
        dp[idx]=max(steal, notSteal);
        return dp[idx];
    }
};

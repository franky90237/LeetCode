//2024-03-08
//time  : O(n*n*n)
//space : O(n*n)
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n=nums.size();
        dp.resize(n, vector<int>(n, -1));
        return f(nums, 0, n-1);
    }
    
    int f(vector<int>& nums, int i, int j)
    {
        if(j-i == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MIN;
        for(int k=i+1; k<j; ++k)
        {
            int sum = f(nums, i, k) + nums[i]*nums[k]*nums[j] + f(nums, k, j);
            res = max(res, sum);
        }
        
        return dp[i][j] = res;
    }
};

//2024-03-08
//time  : O(n*n*n)
//space : O(n*n)
class Solution {      
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        int n=nums.size();
         vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=n-3; i>=0; --i)
        {
            for(int j=i+2; j<n; ++j)
            {
                for(int k=i+1; k<j; ++k)
                {
                    int sum = dp[i][k] + nums[i]*nums[k]*nums[j] + dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        
        return dp[0][n-1];
    }
};

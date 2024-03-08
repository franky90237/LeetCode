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

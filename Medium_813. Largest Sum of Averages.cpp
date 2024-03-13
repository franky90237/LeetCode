//2024-03-13
//time  : O(n*k*n)
//space : O(n*k)
class Solution 
{
private:
    vector<int> preSum;
    vector<vector<double>> dp;
    
public:
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        
        preSum.resize(n+1, 0);
        for(int i=1; i<=n; ++i) preSum[i] = preSum[i-1] + nums[i-1];
        
        dp.resize(n+1, vector<double>(k+1, -1));
                
        f(nums, n, k);
        
        /*
        for(int i=0; i<=n; ++i)
        {
            for(int c=0; c<=k; ++c) cout<<dp[i][c]<<" "; cout<<endl;
        }
        */
        
        return dp[n][k];
    }
    
    double f(vector<int>& nums, int i, int k)
    {
        int n=nums.size();
        if(k == 1) return dp[i][k] = preSum[i] / (double)i;
        if(i == 0) return 0;        
        if(dp[i][k] != -1) return dp[i][k];
        
        dp[i][k] = 0;        
        for(int j=i; j>=1; --j)
        {                        
            double len = i-j+1;
            dp[i][k] = max(dp[i][k], f(nums, j-1, k-1) + (preSum[i]-preSum[j-1])/len);
            //if(i == n-1) cout<<j<<" : "<<(preSum[i]-preSum[j-1])/len<<endl;
        }
        
        return dp[i][k];
    }
};

//2024-03-13
//time  : O(n*k*n)
//space : O(n*k)
class Solution {    
public:
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        
        vector<int> preSum(n+1, 0);
        for(int i=1; i<=n; ++i) preSum[i] = preSum[i-1] + nums[i-1];
        
        vector<vector<double>> dp(n+1, vector<double>(k+1, 0));
        for(int i=1; i<=n; ++i) dp[i][1] = preSum[i] / (double)i;
        
        for(int c=2; c<=k; ++c)
        {
            for(int i=1; i<=n; ++i)
            {
                for(int j=i; j>=1; --j)
                {                        
                    double len = i-j+1;
                    dp[i][c] = max(dp[i][c], dp[j-1][c-1] + (preSum[i]-preSum[j-1])/len);
                }
            }
        }
        
        /*
        for(int i=0; i<=n; ++i)
        {
            for(int c=0; c<=k; ++c) cout<<dp[i][c]<<" "; cout<<endl;
        }
        */
                        
        return dp[n][k];
    }      
};

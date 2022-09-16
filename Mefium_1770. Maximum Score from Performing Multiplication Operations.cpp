//2022-09-16
//MLE
//time  : O(m*m*n)
//space : O(m*m*n)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        
        /*
        5,6,100,1
        
        [1,100]
        
        5*1+6*100
        
        1*1+100*100
        
        
        
        (l,r,k)
        
        dp[l][r][k] = max( dp[l-1][r][k-1] + nums[l-1]*mul[k-1], dp[l][r+1][k-1] + nums[r+1]*mul[k-1])
        */
        int m=nums.size();
        int n=multipliers.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>(n, -1) ) );
        
        return solve(nums, multipliers, 0, m-1, 0, dp);
    }
    
    int solve(vector<int>& nums, vector<int>& multipliers, int l, int r, int k, vector<vector<vector<int>>>& dp)
    {
        if(k >= multipliers.size()) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        
        int pick_left  = solve(nums, multipliers, l+1, r, k+1, dp) + nums[l]*multipliers[k];
        int pick_right = solve(nums, multipliers, l, r-1, k+1, dp) + nums[r]*multipliers[k];
        
        dp[l][r][k]=max(pick_left,pick_right);
        return dp[l][r][k];
    }
};

//2022-09-16
//TLE
//time  : O(m*m*n)
//space : O(m*m*n)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        
        /*
        XXXXXXXXXXXX
        0          1000
        (l,r,k)
        
        dp[l][r][k] = max( dp[l-1][r][k-1] + nums[l-1]*mul[k-1], dp[l][r+1][k-1] + nums[r+1]*mul[k-1])
        */
        
        int m=nums.size();
        int n=multipliers.size();
        unordered_map<string,int> dp;
                
        return solve(nums, multipliers, 0, m-1, 0, dp);
    }
    
    int solve(vector<int>& nums, vector<int>& multipliers, int l, int r, int k, unordered_map<string,int>& dp)
    {
        if(k >= multipliers.size()) return 0;
        
        string state= to_string(l) + "," + to_string(r) + "," + to_string(k);        
        if(dp.find(state) != dp.end()) return dp[state];
        
        int pick_left  = solve(nums, multipliers, l+1, r, k+1, dp) + nums[l]*multipliers[k];
        int pick_right = solve(nums, multipliers, l, r-1, k+1, dp) + nums[r]*multipliers[k];
        
        dp[state]=max(pick_left,pick_right);
        return dp[state];
    }
};

//2022-09-16
//if the dp[][] have many states equal to -2, it may TLE
//time  : O(m*m)
//space : O(m*m)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {        
        int m=multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m,-2) );
                
        return solve(nums, multipliers, 0, 0, dp);
    }
    
    int solve(vector<int>& nums, vector<int>& multipliers, int l, int k, vector<vector<int>>& dp)
    {
        if(k >= multipliers.size()) return 0;
        
        if(dp[l][k] != -2) return dp[l][k];
        
        int r=nums.size()-1-(k-l);
        int pick_left  = solve(nums, multipliers, l+1, k+1, dp) + nums[l]*multipliers[k];
        int pick_right = solve(nums, multipliers, l, k+1, dp) + nums[r]*multipliers[k];
        
        dp[l][k]=max(pick_left,pick_right);
        return dp[l][k];
    }
};

//2022-09-16
//dp iterative
//time  : O(m*m)
//space : O(m*m)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        
        /*
        dp[l][k] = max(dp[l+1][k+1] + nums[l]*,mul[k], dp[l][k+1] + nums[r]*mul[k])
        (r = n-1-(k-l) )
        */
                
        int n=nums.size();
        int m=multipliers.size();
        
        int dp[m+1][m+1];
        for(int i=0; i<=m; ++i) dp[i][m]=0;
        
        for(int k=m-1; k>=0; --k)
        {
            for(int l=k; l>=0; --l)
            {
                int r=n-1-(k-l);
                int pick_left  = dp[l+1][k+1] + nums[l]*multipliers[k];
                int pick_right = dp[l][k+1] + nums[r]*multipliers[k];
                
                dp[l][k]=max(pick_left,pick_right);
            }
        }
        
        return dp[0][0];
    }
};

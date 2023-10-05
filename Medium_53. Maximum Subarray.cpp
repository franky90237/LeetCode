//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int maximum=nums[0];
        int sum=nums[0];
        
        for(int i=1; i<n; ++i)
        {
            sum+=nums[i];
            if(sum<nums[i]) 
            {
                sum=nums[i];
            }
            
            maximum=max(maximum,sum);
        }
        
        return maximum;
    }
};

//2022-08-30
//time  : O(n)
//sapce : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        
        /*
          -2, 1,-3, 4,-1, 2, 1,-5, 4 
        
        s  0, 1, 0, 4, 3, 5, 6, 1, 5 
        a -2, 1, 1, 4, 4, 5, 6, 6, 6
        
        */
        int ans=INT_MIN;
        int sum=0;
        
        for(auto& num:nums)
        {
            sum+=num;
            ans=max(ans,sum);
            
            if(sum<0) sum=0;
        }
        
        return ans;
    }
};

//2023-10-05
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        for(int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];
            ans = max(ans, sum);
            
            if(sum < 0)
            {                
                sum = 0;                
            }                        
        }
        
        return ans;
    }
};

//2023-10-05
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();        
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1; i<n; ++i)
        {
            dp[i]=max(dp[i-1]+nums[i], nums[i]);
            ans=max(ans, dp[i]);
        }
        
        return ans;
    }
};

//2023-10-06
//time  : O(nlog(n))
//space : O(log(n))
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        return maxSubArray(nums, 0, nums.size()-1);
    }
    
    int maxSubArray(vector<int>& nums, int left, int right)
    {
        if(left > right) return INT_MIN;
        if(left == right) return nums[left];
        
        int mid=left+(right-left)/2;
        
        int sum=0;
        int maxLeftSum=INT_MIN;
        for(int i=mid; i>=left; --i)
        {
            sum += nums[i];
            maxLeftSum=max(maxLeftSum, sum);
        }
        
        sum=0;
        int maxRightSum=INT_MIN;
        for(int i=mid+1; i<=right; ++i)
        {            
            sum += nums[i];
            maxRightSum=max(maxRightSum, sum);
        }
        
        return max(maxLeftSum + maxRightSum, 
                   max(maxSubArray(nums, left, mid), maxSubArray(nums, mid+1, right)));
    }
};

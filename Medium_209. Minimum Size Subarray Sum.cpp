//2022-12-06
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int ans=n+1;
        int sum=0;
        int left=0;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            while(left <= i && sum >= target)
            {
                ans=min(ans, i-left+1);
                sum -= nums[left];
                ++left;
            }
        }
        
        return ans==n+1 ? 0 : ans;
    }
};

//2022-01-11
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int ans=n+1;
        
        while(r < n)
        {
            sum += nums[r];
            
            while(l <= r && sum >= target)
            {
                ans=min(ans, r-l+1);
                sum -= nums[l];
                ++l;
            }
            
            ++r;
        }
        
        return ans==n+1 ? 0 : ans;
    }
};

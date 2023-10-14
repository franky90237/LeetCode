//2022-01-14
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        map<int, int> prefix_sum;
        prefix_sum[0]=1;
        int sum=0;
        int ans=0;
        
        for(int i=0; i<nums.size(); ++i)
        {            
            sum += nums[i];
            int target=sum-goal; //sum-target=goal
            
            if(prefix_sum.find(target) != prefix_sum.end())
            {
                ans += prefix_sum[target];
            }
                                    
            ++prefix_sum[sum];
        }
        
        return ans;
    }
};

//2023-01-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return sum_less_than_and_equal(nums, goal) - sum_less_than_and_equal(nums, goal-1);
    }
    
    int sum_less_than_and_equal(vector<int>& nums, int k)
    {
        if(k < 0) return 0;
        
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        
        while(r < n)
        {
            sum += nums[r];
            
            while(sum > k)
            {
                sum -= nums[l];
                ++l;
            }
            
            cnt += r-l+1;
            ++r;
        }
        
        return cnt;
    }
};

//2023-10-14
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n=nums.size();
        unordered_map<int, int> preSum;
        preSum[0]=1;
        
        int sum=0;
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            int target=sum-goal;
            if(preSum.find(target) != preSum.end())
            {
                ans += preSum[target];
            }
            
            ++preSum[sum];
        }
        
        return ans;
    }
};

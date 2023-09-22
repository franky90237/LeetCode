//2023-09-23
//time  : O(n*sqrt(n))
//space : O(1)
class Solution {
public:
    long long maximumSum(vector<int>& nums) 
    {
        int n=nums.size();
        long long ans=0;
        for(int i=0; i<n; ++i)
        {
            long long sum=nums[i];
            for(int base=2; ; ++base)
            {
                int square=base*base;
                int idx=square*(i+1);
                if(idx > n) break;
                
                sum += nums[idx-1];
            }
            
            ans=max(ans, sum);
        }
        
        return ans;
    }
};

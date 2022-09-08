//2022-09-08
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n=nums.size();
        
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            int sum=0;
            for(int j=i; j<n; ++j)
            {
                sum+=nums[j];
                if(sum==k) ++ans;
            }
        }
        
        return ans;
    }
};

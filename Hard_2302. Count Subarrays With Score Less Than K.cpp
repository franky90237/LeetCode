//2023-10-16
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n=nums.size();
        vector<long long> prefixSum(n+1);
        prefixSum[0]=0;
        for(int i=1; i<=n; ++i)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
                
        long long ans=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            long long curSum=prefixSum[right+1]-prefixSum[left];
            int len=right-left+1;
            while(left <= right && curSum*len >= k)
            {
                ++left;
                curSum=prefixSum[right+1]-prefixSum[left];
                --len;
            }
            
            //cout<<right<<" | "<<left<<" "<<right<<endl;
            ans += len;
        }
        
        return ans;    
    }
};

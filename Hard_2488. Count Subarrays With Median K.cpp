//2022-12-03
//time  : O(n)
//space : O(n)
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k)
    {
        int middle;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] > k) nums[i]=1;
            else if(nums[i] < k) nums[i]=-1;
            else 
            {
                nums[i]=0;
                middle=i;
            }
        }
        
        unordered_map<int, int> prefix_sum;
        prefix_sum[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];            
            
            if(i >= middle)
            {
                int target1=sum;
                int target2=sum-1;
                if(prefix_sum.find(target1) != prefix_sum.end()) ans+=prefix_sum[target1];
                if(prefix_sum.find(target2) != prefix_sum.end()) ans+=prefix_sum[target2];
            }
            
            if(i < middle) ++prefix_sum[sum];
        }
        
        return ans;
    }
};

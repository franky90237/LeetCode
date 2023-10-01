//2023-10-01
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) 
    {
        int n=nums.size();
        long long total=accumulate(nums.begin(), nums.end(), 0LL);
        int cnt=target/total;
        target = target % total;
        if(target == 0)
        {
            return n*cnt;
        }
        
        unordered_map<long long, int> preSum;
        preSum[0]=-1;
        long long sum=0;
        int rest=INT_MAX;
        for(int i=0; i<2*n; ++i)
        {
            sum += nums[i%n];
            int diff=sum-target;
            if(preSum.find(diff) != preSum.end())
            {
                rest=min(rest, i-preSum[diff]);
            }
            
            preSum[sum]=i;
        }
        
        //cout<<cnt<<" "<<rest<<endl;
        return rest == INT_MAX ? -1 : rest + n*cnt;
    }
};

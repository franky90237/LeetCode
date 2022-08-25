//2022-08-25
//time  : O(nlogn + klogk)
//space : O(k)
class Solution {
public:
    long long kSum(vector<int>& nums, int k)
    {
        int n=nums.size();
        
        long long maxSum=0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i]>0) maxSum+=nums[i];
            else nums[i]=-nums[i];            
        }
        
        if(k==1) return maxSum; 
        sort(nums.begin(),nums.end());        
        //for(auto& num:nums) cout<<num<<" ";
        //cout<<endl;
               
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>> > minHeap;
        minHeap.push({nums[0],0});
        
        --k;
        while(k>1)
        {            
            long long sum=minHeap.top().first;
            int idx=minHeap.top().second;
            minHeap.pop();
            //cout<<sum<<endl;
            
            if(idx+1<n)
            {
                minHeap.push({sum+nums[idx+1],idx+1});
                minHeap.push({sum-nums[idx]+nums[idx+1],idx+1});
            }
            
            --k;
        }
                
        return maxSum-minHeap.top().first;
    }
};

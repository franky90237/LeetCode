//2023-01-12
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        long long sum=0;
        int ans=n+1;
        
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            
            if(sum >= k)
            {
                ans=min(ans, i+1);
            }
            
            while(!minHeap.empty() && sum-minHeap.top().first >= k)
            {
                int idx=minHeap.top().second;
                minHeap.pop();
                ans=min(ans, i-idx);
            }
                        
            minHeap.push({sum, i});
        }
        
        return (ans==n+1) ? -1 : ans;
    }    
};

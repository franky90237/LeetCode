//2022-12-29
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& num: nums)
        {
            minHeap.push(num);
        }
        
        while(k > 0)
        {
            int minVal=minHeap.top();
            minHeap.pop();
            minHeap.push(minVal+1);
            --k;            
        }
        
        int mod=1e9+7;
        int ans=1;
        while(!minHeap.empty())
        {
            long val=minHeap.top();
            minHeap.pop();
            ans = (ans * val) % mod;
        }
        
        return ans;
    }
};

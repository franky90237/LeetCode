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

//2023-01-12
//time  : O(n)
//space : O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        deque<pair<long long, int>> dq;
        long long sum=0;
        int ans=n+1;
        
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            
            if(sum >= k)
            {
                ans=min(ans, i+1);
            }
            
            while(!dq.empty() && sum-dq.front().first >= k)
            {
                int idx=dq.front().second;
                dq.pop_front();
                ans=min(ans, i-idx);
            }
            
            while(!dq.empty() && sum <= dq.back().first)
            {
                dq.pop_back();
            }
            
            //cout<<i<<" "<<ans<<" "<<dq.size()<<endl;
            dq.push_back({sum, i});
        }
        
        return (ans==n+1) ? -1 : ans;
    }    
};

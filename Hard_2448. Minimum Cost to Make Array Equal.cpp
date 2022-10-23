//2022-10-23
//time  : O(nlog(n))
//spcae : O(n)
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {                
        int n=nums.size();
        
        vector<int> idx(n);
        for(int i=0; i<n; ++i) idx[i]=i;        
        sort(idx.begin(), idx.end(), [&](int a, int b)
             {
                 return nums[a]<nums[b];
             });
        
        //for(int i=0; i<n; ++i) cout<<idx[i]<<" ";
        //cout<<endl;
        
        vector<long long> left(n);
        left[0]=0;
        long long costAccumulate=cost[idx[0]];
        for(int i=1; i<n; ++i)
        {            
            left[i] = left[i-1] + (nums[idx[i]] - nums[idx[i-1]]) * costAccumulate;
            costAccumulate += cost[idx[i]];
        }        
        
        vector<long long> right(n);
        right[n-1]=0;
        costAccumulate=cost[idx[n-1]];
        for(int i=n-2; i>=0; --i)
        {
            right[i] = right[i+1] + (nums[idx[i+1]] - nums[idx[i]]) * costAccumulate;
            costAccumulate += cost[idx[i]];
        }        
        
        long long ans=LLONG_MAX;
        for(int i=0; i<n; ++i)
        {
            ans=min(ans, left[i]+right[i]);
        }
        
        return ans;
    }   
};

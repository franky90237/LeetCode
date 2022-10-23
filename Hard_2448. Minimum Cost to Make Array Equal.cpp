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

//2022-10-23
//time  : O(nlog(1000000))
//spcae : O(1)
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost)
    {                
        int l=0;
        int r=1e6;
        while(l < r)
        {
            int mid=l+(r-l)/2;
            long long costMid=getCost(nums, cost, mid);
            long long costMidPlus1=getCost(nums, cost, mid+1);
            long long costMidMinus1=getCost(nums, cost, mid-1);
            
            if(costMid <= costMidMinus1 && costMid <= costMidPlus1) return costMid;
            if(costMid > costMidPlus1)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        return getCost(nums, cost, l);
    }
    
    long long getCost(vector<int>& nums, vector<int>& cost, int val)
    {
        long long ans=0;
        for(int i=0; i<nums.size(); ++i)
        {
            long long diff=abs(val-nums[i]);
            ans = ans + diff*cost[i];
        }
        
        return ans;
    }
};

/*

1 2 3 4 5

1 : 1+2+3+4=10
2 : 1+1+2+3=7
3 : 2+1+1+2=6
4 : 3+2+1+1=7
5 : 4+3+2+1=10


1 2 5 10

1 : 0+1+4+9=14
2 : 1+0+3+8=12
5 : 4+3+0+5=12
10: 9+8+5+0=22

*/

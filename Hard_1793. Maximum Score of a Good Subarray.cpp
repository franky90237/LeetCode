//2023-08-27
//time  : O(n)
//space : O(n)a
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0]=-1;
        for(int i=1; i<n; ++i)
        {
            int cur=i-1;
            while(cur >= 0 && nums[cur] >= nums[i])
            {
                cur=left[cur];
            }

            left[i]=cur;
        }
        
        right[n-1]=n;
        for(int i=n-2; i>=0; --i)
        {
            int cur=i+1;
            while(cur < n && nums[cur] >= nums[i])
            {
                cur=right[cur];
            }

            right[i]=cur;
        }
        
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            if(left[i]+1 <= k && k <= right[i]-1)
            {
                int area=nums[i]*(right[i]-left[i]-1);
                ans=max(ans, area);
            }
        }
        
        return ans;
    }
};

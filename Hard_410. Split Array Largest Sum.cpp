//2022-12-31
//time  : O(nlog(sum(n)))
//space : O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int k)
    {        
        int l=nums[0];
        int r=nums[0];
        for(int i=1; i<nums.size(); ++i)
        {
            l=max(l, nums[i]);
            r += nums[i];
        }
        
        /*int ans=l;
        for(int i=l; i<=r; ++i)
        {
            if(check(nums, k, i))
            {
                ans=i;
                break;
            }
        }
        
        return ans;*/
        
        int ans=0;
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(check(nums, k, mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums, int k, int target)
    {
        int n=nums.size();        
        int sum=0;
        int cnt=1;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            if(sum > target)
            {
                sum=nums[i];
                ++cnt;
            }
        }
        
        return cnt <= k;
    }
};

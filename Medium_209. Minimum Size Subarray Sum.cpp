//2022-12-06
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int ans=n+1;
        int sum=0;
        int left=0;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            while(left <= i && sum >= target)
            {
                ans=min(ans, i-left+1);
                sum -= nums[left];
                ++left;
            }
        }
        
        return ans==n+1 ? 0 : ans;
    }
};

//2022-01-11
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int ans=n+1;
        
        while(r < n)
        {
            sum += nums[r];
            
            while(l <= r && sum >= target)
            {
                ans=min(ans, r-l+1);
                sum -= nums[l];
                ++l;
            }
            
            ++r;
        }
        
        return ans==n+1 ? 0 : ans;
    }
};

//2022-01-12
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int l=0;
        int r=n;
        int sum=0;
        int ans=0;
        
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(check(nums, target, mid))
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
    
    bool check(vector<int>& nums, int target, int len) 
    {       
        if(len == 0) return false;
        
        int sum=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(i >= len)
            {
                sum -= nums[i-len];
            }
            
            sum += nums[i];
            if(i >= len-1 && sum >= target)
            {
                return true;
            }
        }
        
        return false;
    }
};

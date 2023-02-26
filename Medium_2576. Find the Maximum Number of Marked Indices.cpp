//2023-02-26
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int l=0;
        int r=nums.size()/2;
        int ans=0;
        
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            
            if(check(nums, mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        return ans*2;
    }
    
    bool check(vector<int>& nums, int cnt)
    {
        int n=nums.size();
        int l=0;
        int r=n-cnt;
        
        while(cnt > 0 && 2*nums[l] <= nums[r])
        {
            --cnt;
            ++l;
            ++r;
        }
        
        return cnt==0;
    }
};

//2023-02-26
//time  : O(nlog(n)
//space : O(1)
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        int l=0;
        int ans=0;
        for(int i=(n+1)/2; i<n; ++i)
        {
            if(nums[l]*2 <= nums[i])
            {
                ++l;
                ans += 2;
            }
        }
        
        return ans;
    }
};

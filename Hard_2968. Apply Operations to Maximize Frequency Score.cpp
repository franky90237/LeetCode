//2023-12-19
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        //for(int num : nums) cout<<num<<" "; cout<<endl;
        
        int ans=1;
        int left=1;
        int right=n;
        while(left <= right)
        {
            int mid=left+(right-left)/2;
            if(check(nums, k, mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& nums, long long k, int len)
    {
        //cout<<len<<" *** "<<endl;
        
        long long base=(len-1)/2;
        long long sum=0;
        for(int i=0; i<len; ++i)
        {
            sum += abs(nums[base]-nums[i]);
        }
        
        //cout<<0<<" "<<base<<" "<<len-1<<" | "<<sum<<endl;
        if(sum <= k) return true;
        
        int left=0;
        for(int right=len; right<nums.size(); ++right)
        {            
            sum -= nums[base]-nums[left];
            ++left;            
            ++base;
            
            long long diff=nums[base]-nums[base-1];
            long long lenL=base-left;
            long long lenR=right-base;
            sum = sum + diff*lenL - diff*lenR + (nums[right]-nums[base]);
            
            //cout<<left<<" "<<base<<" "<<right<<" | "<<sum<<endl;
            if(sum <= k) return true;
        }
        
        return false;
        
    }
};

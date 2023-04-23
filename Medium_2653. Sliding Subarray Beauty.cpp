//2023-04-23
//time  : O(n*range of nums)
//space : O(n)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x)
    {
        int n=nums.size();
        vector<int> ans;
        
        map<int, int> freq;
        for(int i=0; i<n; ++i)
        {
            if(i >= k && nums[i-k] < 0)
            {
                --freq[nums[i-k]];
            }
            
            if(nums[i] < 0) 
            {
                ++freq[nums[i]];
            }
            
            if(i >= k-1)
            {
                int xthMin = getXthMin(freq, x);
                ans.push_back(xthMin);
            }
        }
        
        return ans;
    }
    
    int getXthMin(map<int, int>& freq, int x)
    {               
        int sum=0;
        for(auto& it: freq)
        {
            int num=it.first;
            int cnt=it.second;
            
            sum+=cnt;
            if(sum >= x) return num;
        }
        
        return 0;
    }
};

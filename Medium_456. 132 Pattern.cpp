//2023-02-09
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<int> less(n, INT_MAX);        
        for(int i=1; i<n; ++i)
        {
            less[i]=min(less[i-1], nums[i-1]);
        }
        
        vector<int> val_k;
        val_k.push_back(nums[n-1]);
        for(int j=n-2; j>=1; --j)
        {
            if(nums[j] <= less[j])
            {
                continue;
            }
            
            //nums[i] < nums[k] 
            while(!val_k.empty() && val_k.back() <= less[j])
            {
                val_k.pop_back();
            }
            
            //nums[i] < nums[j] 
            if(!val_k.empty() && nums[j] > val_k.back())
            {
                return true;
            }                        
            
            val_k.push_back(nums[j]);
        }
        
        return false;
    }
};

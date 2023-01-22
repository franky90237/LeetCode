//2023-01-22
//time  : O(n)
//space : O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return less_and_equal(nums, k) - less_and_equal(nums, k-1);        
    }
    
    int less_and_equal(vector<int>& nums, int target)
    {
        if(target == 0) return 0;
        
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        unordered_map<int, int> table;
        
        while(r < n)
        {
            ++table[nums[r]];
            while(table.size() > target)
            {
                --table[nums[l]];
                if(table[nums[l]] == 0) table.erase(nums[l]);
                
                ++l;
            }
            
            ans += r-l+1;
            ++r;
        }
        
        return ans;
    }
};

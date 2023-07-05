//2023-07-05
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int n=nums.size();
        int ans=0;
        map<int, int> table;
        for(int left=0, right=0; right<n; ++right)
        {
            ++table[nums[right]];
            while((table.rbegin())->first - (table.begin())->first > limit)
            {
                --table[nums[left]];
                if(table[nums[left]] == 0) table.erase(nums[left]);
                ++left;
            }
                        
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};

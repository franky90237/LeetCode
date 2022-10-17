//2022-10-18
//time  : O(n)
//space : O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        unordered_set<int> table;
        for(auto& num: nums)
        {
            if(num < 0) table.insert(num);
        }
        
        int ans=-1;
        for(auto& num: nums)
        {
            if(num > 0 && table.find(-num) != table.end())
            {
                ans=max(ans, num);
            }
        }
        
        return ans;
    }
};

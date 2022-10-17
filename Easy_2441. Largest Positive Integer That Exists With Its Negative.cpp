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

//2022-10-18
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        if(nums.back() < 0) return -1;
                
        int l=0;
        int r=nums.size()-1;
        while(l < r && nums[l] < 0 && nums[r] > 0)
        {
            int sum=nums[l]+nums[r];
            if(sum == 0) return nums[r];
            
            if(sum > 0)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
        
        return -1;
    }
};

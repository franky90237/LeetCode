//time  : O(n*n)
//space : O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j!=i && j<n; ++j)
            {
                if(nums[i]==nums[j]) return true;
            }
        }
        
        return false;
    }
};

//time  : O(n)
//space : O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        int n=nums.size();
        
        for(int i=0; i<n; ++i)
        {
            if(s.count(nums[i])==1) return true;
            s.insert(nums[i]);
        }
        
        return false;
    }
};

//2022-09-01
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> table;
        
        for(auto& num:nums)
        {
            if(table.count(num)) return true;
            else table.insert(num);
        }
        
        return false;
    }
};

//hash map 
//time  : O(n)
//space : O(2n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            if(m.find(nums[i])!=m.end())
            {
                if(i-m[nums[i]]<=k) return true;
                m[nums[i]]=i;
            }
            else
            {
                m[nums[i]]=i;
            }
        }
        
        return false;
    }
};

//simplified hash map 
//time  : O(n)
//space : O(2n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            if(m.find(nums[i])!=m.end() && i-m[nums[i]]<=k) return true;
            
            m[nums[i]]=i;
        }
        
        return false;
    }
};

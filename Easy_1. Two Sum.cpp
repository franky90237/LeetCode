//time :  O(n*n)
//space : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        
        return {-1,-1};
    }
};

//time :  O(n)
//space : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        unordered_multimap<int,int> m;
        
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            m.insert(make_pair(nums[i],i));
        }
        
        for(auto i=m.begin(); i!=m.end();)
        {
            int dif=target-i->first;
            int i_index=i->second;
            i=m.erase(i);
            
            auto dif_find=m.find(dif);            
            if(dif_find!=m.end()) return {i_index,dif_find->second};
        }
        
        return {-1,-1};
    }
};

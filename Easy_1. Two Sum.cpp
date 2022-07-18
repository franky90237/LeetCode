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

//simplified hash map
//time :  O(n)
//space : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_multimap<int,int> m;
        
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            int dif=target-nums[i];
            if(m.find(dif)!=m.end()) return {m.find(dif)->second,i};
            
            m.insert(make_pair(nums[i],i));
        }
        
        return {-1,-1};
    }
};

//2022-07-19
//hasp mapa
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,vector<int>> table;
        
        for(int i=0; i<nums.size(); ++i)
        {
             table[nums[i]].push_back(i);
        }
        
        if(target%2==0)
        {
            int val=target/2;
            if(table.find(val)!=table.end() && table[val].size()>=2) return {table[val][0],table[val][1]}; 
        }
        
        for(int i=0; i<nums.size(); ++i)
        {
            int diff=target-nums[i];
            if(diff==nums[i]) continue;
            
            if(table.find(diff)!=table.end())
            {
                return {table[diff][0],i};
            }
        }
        
        return {-1,-1};
    }
};

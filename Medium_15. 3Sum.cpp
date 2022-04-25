//2022-04-25
//TLE
class Solution {
private:
    struct HashFunction
    {
        size_t operator()(const tuple<int,int,int>& t) const
        {
            size_t h0 = hash<int>()(get<0>(t));
            size_t h1 = hash<int>()(get<1>(t));
            size_t h2 = hash<int>()(get<2>(t));
            
            return h0 ^ h1 ^ h2;
        }
    };
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        
        unordered_map<int,vector<int>> m;
        for(int i=0; i<n; ++i)
        {
            if(m.find(nums[i])==m.end())
            {
                vector<int> s;
                m[nums[i]]=s;
            }
            
            m[nums[i]].push_back(i);
        }
        
        if(n>=3 && m.size()==1)
        {
            if(m.begin()->first==0) return {{0,0,0}};
            else return {};
        }
        
        unordered_set<tuple<int,int,int>,HashFunction> res_s;
        for(int i=0; i<n; ++i)
        {
            twoSum(nums,res_s,m,i,-nums[i]);
        }
        
        vector<vector<int>> res;
        for(auto& it:res_s) res.push_back({get<0>(it),get<1>(it),get<2>(it)});
        
        return res;
    }
    
    void twoSum(vector<int>& nums, unordered_set<tuple<int,int,int>, HashFunction>& res, unordered_map<int,vector<int>>& m, int now, int target)
    {
        int n=nums.size();
        
        for(int i=now+1; i<n; ++i)
        {
            if(i==now) continue;
            
            int value=target-nums[i];
            auto it=m.find(value);
            if(it!=m.end())
            {
                for(auto& index:it->second)
                {
                    if(index>i && index>now)
                    {
                       vector<int> tmp({nums[now],nums[i],nums[index]});
                        sort(tmp.begin(),tmp.end());
                        res.insert(make_tuple(tmp[0],tmp[1],tmp[2]));
                    }
                }
            }
        }
    }
};

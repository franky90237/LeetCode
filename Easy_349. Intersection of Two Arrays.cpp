//time. : O(n+m)
//space : O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> m;
        vector<int> res;
        
        for(auto& i:nums1)
        {
            if(m.find(i)==m.end()) m[i]=1;
        }
        
        for(auto& i:nums2)
        {
            if(m.find(i)!=m.end() && m[i]==1)
            {
                res.push_back(i);
                m[i]=2;
            }
        }
        
        return res;
    }
};

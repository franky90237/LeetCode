//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int,int> m;
        for(auto& i:nums1)
        {
            for(auto& j:nums2)
            {
                ++m[i+j];
            }
        }
        
        int cnt=0;
        for(auto& k:nums3)
        {
            for(auto& l:nums4)
            {
                if(m.find(-(k+l))!=m.end()) cnt+=m[-(k+l)];
            }
        }
        
        return cnt;
    }
};

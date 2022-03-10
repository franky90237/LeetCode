//time  : O(n) + O(m)
//space : O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        unordered_map<int,int> m;
        
        for(const auto& i:nums1) ++m[i];        
        for(const auto& i:nums2)
        {
            if(m.find(i)!=m.end() && m[i]!=0)
            {
                --m[i];
                res.push_back(i);
            }
        }
        
        return res;
    }
};

//time  : O(nlogn) + O(mlogm)
//space : O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> res;
        int n=nums1.size(), m=nums2.size();
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j]) ++i;
            else if(nums1[i]>nums2[j]) ++j;
            else
            {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        
        return res;
    }
};

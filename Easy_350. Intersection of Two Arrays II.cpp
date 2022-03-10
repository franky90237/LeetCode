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

//time  : O(nlogn) + O(mlogm) + O(mlogn)
//space : O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> res;
        int n=nums1.size(), m=nums2.size();
        for(int i=0; i<m; ++i)
        {
            int pos=binary_search(nums1,nums2[i]);
            //cout<<pos<<endl;
            if(nums1[pos]!=nums2[i]) continue;
            
            int cnt2=0, j=i;
            while(j<m && nums2[j]==nums2[i])
            {
                ++cnt2;
                ++j;
            }
            
            int cnt1=0;
            while(pos<n && nums1[pos]==nums2[i])
            {
                ++cnt1;
                ++pos;
            }
            
            cnt1=min(cnt1,cnt2);
            for(int k=0; k<cnt1; ++k) res.push_back(nums2[i]);
            
            i=j-1;
        }
        
        return res;
    }
    
    int binary_search(vector<int>& num, int target)
    {
        int l=0, h=num.size()-1;
        
        while(l<h)
        {
            int m=(l+h)/2;
            if(num[m]<target) l=m+1;
            else if(num[m]>target) h=m-1;
            else h=m;
        }
        
        return l;
    }
};

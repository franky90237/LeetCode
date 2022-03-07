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

//time. : O(n+m)
//space : O(min(n,m))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s;
        vector<int> res;
        
        int n=nums1.size(), m=nums2.size();
        vector<int> *n1, *n2;
        if(n>m)
        {
            n1=&nums2;
            n2=&nums1;
        }
        else
        {
            n1=&nums1;
            n2=&nums2;
        }
        
        for(int i=0; i<n1->size(); ++i)
        {
            if(s.count((*n1)[i])==0) s.insert((*n1)[i]);
        }
        
        for(int i=0; i<n2->size(); ++i)
        {
            if(s.count((*n2)[i])==1)
            {
                res.push_back((*n2)[i]);
                s.erase((*n2)[i]);
            }
        }
        
        return res;
    }
};

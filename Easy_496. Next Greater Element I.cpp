//2023-08-31
//time  : O(m+n)
//space : O(m+n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n2=nums2.size();
        
        vector<int> idx(10001);
        idx[nums2.back()]=n2-1;
        
        vector<int> right(n2);        
        right[n2-1]=n2;       
        
        for(int i=n2-2; i>=0; --i)
        {
            int nxt=i+1;
            while(nxt < n2 && nums2[i] > nums2[nxt])
            {
                nxt=right[nxt];
            }
            
            right[i]=nxt;
            idx[nums2[i]]=i;
        }
        
        int n1=nums1.size();
        vector<int> ans(n1, -1);
        for(int i=0; i<n1; ++i)
        {
            int num=nums1[i];
            int mappingIdx=idx[num];
            int greaterIdx=right[mappingIdx];
            if(greaterIdx != n2) ans[i]=nums2[greaterIdx];
        }
        
        return ans;
    }
};

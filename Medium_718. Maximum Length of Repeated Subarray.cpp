//2022-09-20
//TLE
//time  : O(m * n * min(m,n))
//space : O(n)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        
        unordered_map<int, vector<int>> table;
        for(int i=0; i<m; ++i)
        {
            table[nums2[i]].push_back(i);
        }
        
        int ans=0;
        for(int i=0; i<m; ++i)
        {
            for(auto& k : table[nums1[i]])
            {            
                int f=i;
                int s=k;
                while(f<m && s<n  && nums1[f]==nums2[s])
                {                    
                    ++f;
                    ++s;
                }
                
                ans=max(ans, f-i);
            }
        }
        
        return ans;
    }     
};

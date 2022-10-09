//2022-10-09
//time  : O(32*n)
//space : O(1)
class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        vector<int> ans;
        ans.push_back(pref[0]);
        
        for(int i=1; i<pref.size(); ++i)
        {
            int target=find(pref[i-1], pref[i]);
            ans.push_back(target);
        }
        
        return ans;
    }
    
    int find(int a, int b)
    {
        int res=0;
        unsigned int x=1;
        for(int i=0; i<32; ++i)
        {
            int aBit = a & x;
            int bBit = b & x;
            
            if(aBit != bBit)
            {
                res = res | x;
            }            
            
            x = x << 1;
        }
        
        return res;
    }
};

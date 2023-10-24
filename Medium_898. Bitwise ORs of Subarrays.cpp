//2023-10-24
//time  : O(32*n)
//space : O(32*n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int> ans;
        unordered_set<int> pre;
        pre.insert(0);
        for(int num: arr)
        {
            unordered_set<int> nxt;                        
            for(auto it: pre)
            {
                int res=it|num;
                nxt.insert(res);
                ans.insert(res);
            }
            
            pre=nxt;
            pre.insert(0);
        }
        
        return ans.size();
    }
};

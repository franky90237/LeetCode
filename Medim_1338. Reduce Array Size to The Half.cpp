//2022-08-18
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int,int> table;
        for(auto& val:arr) ++table[val];
        
        multiset<int> cnt;
        for(auto& i:table) cnt.insert(-i.second);        
        
        int ans=0;
        int size=arr.size();
        for(auto& i:cnt)
        {
            ++ans;
            size+=i;
            if(size <= arr.size()/2) break;
        }
        
        return ans;
    }
};

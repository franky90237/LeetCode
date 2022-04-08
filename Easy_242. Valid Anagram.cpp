//time  : O(n)
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false;
        
        int hash_map[26]={0};
        
        for(int i=0; i<s.size(); ++i)
        {
            ++hash_map[s[i]-'a'];
            --hash_map[t[i]-'a'];
        }
        
        for(auto i:hash_map) if(i!=0) return false;
        return true;
    }
};

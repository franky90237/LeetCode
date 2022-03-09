class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> sm,tm;
        
        for(int i=0; i<s.size(); ++i)
        {
            auto sfind=sm.find(s[i]);
            auto tfind=tm.find(t[i]);
            
            if(sfind!=sm.end() && sfind->second!=t[i]) return false;
            if(tfind!=tm.end() && tfind->second!=s[i]) return false;
            
            sm[s[i]]=t[i];
            tm[t[i]]=s[i];
        }
        
        return true;
    }
};

class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int> m;
        for(const auto& i:s)
        {
            if(m.find(i)==m.end()) m[i]=1;
            else ++m[i];
        }
        
        for(int i=0; i<s.size(); ++i)
        {
            if(m[s[i]]==1) return i;
        }
        
        return -1;
    }
};

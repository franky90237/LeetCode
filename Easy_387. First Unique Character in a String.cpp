//time  : O(n+n)
//space : O(n)
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

//time  : O(n+26)
//space : O(n)
class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int> m;
        for(int i=0; i<s.size(); ++i)
        {
            if(m.find(s[i])==m.end()) m[s[i]]=i;
            else m[s[i]]=INT_MAX;
        }
        
        int min_index=INT_MAX;
        for(const auto& i:m)
        {
            if(i.second!=INT_MAX) min_index=min(min_index,i.second);
        }
        
        return min_index==INT_MAX ? -1 : min_index;
    }
};

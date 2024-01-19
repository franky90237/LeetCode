//2024-01-19
//time  : O((m-n)*26)
//space : O(26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size()) return false;
        
        vector<int> s1Cnt(26, 0);
        for(char c : s1) ++s1Cnt[c-'a'];
        
        vector<int> s2Cnt(26, 0);
        for(int i=0; i<s1.size(); ++i)
        {
            ++s2Cnt[s2[i]-'a'];
        }
        if(match(s1Cnt, s2Cnt)) return true;
        
        
        int left=1;
        for(int i=s1.size(); i<s2.size(); ++i)
        {
            --s2Cnt[s2[left-1]-'a'];
            ++s2Cnt[s2[i]-'a'];            
            if(match(s1Cnt, s2Cnt)) return true;
            
            ++left;
        }
        
        return false;
    }
    
    bool match(vector<int>& a, vector<int>& b)
    {
        for(int i=0; i<a.size(); ++i)
        {
            if(a[i] != b[i]) return false;
        }
        
        return true;
    }
};

//2023-12-07
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool makeStringsEqual(string s, string target) 
    {
        int n=s.size();
        int diff0=0;
        int diff1=0;
        int same1=0;
        int same0=0;
        for(int i=0; i<n; ++i)
        {
            if(s[i] == '1' && target[i] == '1') ++same1;
            else if(s[i] == '1' && target[i] == '0') ++diff1;
            else if(s[i] == '0' && target[i] == '1') ++diff0;
            else ++same0;
        }

        if(same1 > 0 || same0 == n) return true;
        if(diff1 > 0 && diff0 > 0) return true;
        return false;
    }
};

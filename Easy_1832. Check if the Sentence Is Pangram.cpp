//2022-10-17
//time  : O(n)
//space : O(26)
class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        int table[26]={0};
        int cnt=0;
        for(auto& c: sentence)
        {
            if(table[c-'a'] == 0)
            {
                ++cnt;
                if(cnt == 26) return true;
                table[c-'a']=1;
            }                        
        }
        
        return false;
    }
};

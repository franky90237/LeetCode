//2024-04-08
//time  : O(n)
//space : O(1)
class Solution {
public:
    string getSmallestString(string s, int k) 
    {
        for(char& c : s)
        {                        
            int diff=min(c-'a', 'z'-c+1);
            
            if(k-diff < 0)
            {
                c-=k;
                break;
            }
            
            c='a';
            k-=diff;
        }
        
        return s;
    }
};

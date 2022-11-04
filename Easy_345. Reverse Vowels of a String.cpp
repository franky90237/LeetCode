//2022-11-04
//time  : O(n)
//space : O(1)
class Solution {
public:
    string reverseVowels(string s) 
    {
        unordered_set<char> vowel({'a','e','i','o','u','A','E','I','O','U'});
        int l=0;
        int r=s.size()-1;
        while(l < r)
        {
            while(l < r && !vowel.count(s[l]))
            {
                ++l;
            }

            while(l < r && !vowel.count(s[r]))
            {
                --r;
            }

            if(l >= r) break;

            swap(s[l], s[r]);
            ++l;
            --r;
        }        

        return s;        
    }
};

//2022-08-17
//time  : O(n*m), m is the average size of word length
//space : O(n)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        string table[26]=
        {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };        
        unordered_set<string> morse_code;
        
        for(auto& word:words)
        {
            string code="";
            
            for(auto& c:word)
            {
                code+=table[c-'a'];
            }
            
            //cout<<word<<" : "<<code<<endl;            
            morse_code.insert(code);
        }
        
        return morse_code.size();
        
    }
};

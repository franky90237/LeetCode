//2022-10-13
//time  : O((n-allLen) * allLen)
//space : O(wordLen)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        unordered_map<string, int> table;
        for(auto& word: words) ++table[word];
        
        vector<int> ans;
        
        int wordLen=words[0].size();
        int allLen=wordLen*words.size();
        int n=s.size();
        for(int i=0; i<=n-allLen; ++i)
        {
            if(match(s, words, table, i))
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
    bool match(string& s, vector<string>& words, unordered_map<string, int>& table, int start)
    {
        int wordLen=words[0].size();
        
        unordered_map<string, int> freq;
        for(int i=0; i<words.size(); ++i)
        {
            string word=s.substr(start + i*wordLen, wordLen);            
            
            if(table.find(word) == table.end()) return false;
            
            ++freq[word];
            if(freq[word] > table[word]) return false;
        }
        
        return true;
    }
};

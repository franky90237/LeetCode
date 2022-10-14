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

//2022-10-13
//time  : O((n-wordLen) * wordLEn)
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
        for(int i=0; i<wordLen; ++i)
        {
            check(s, words, table, ans, i);
            //cout<<endl;           
        }
        
        return ans;
    }
    
    void check(string& s, vector<string>& words, unordered_map<string, int>& table, vector<int>& ans, int left)
    {
        int n=s.size();
        int wordLen=words[0].size();
        int allLen=wordLen*words.size();
        
        unordered_map<string, int> freq;
        int right=left;
        while(right + wordLen <= n)
        {
            string word=s.substr(right, wordLen);
            //cout<<word<<endl;
            
            if(table.find(word) == table.end())
            {
                freq.clear();
                left=right+wordLen;
            }
            else
            {
                while(freq[word] == table[word])
                {
                    string to_be_removed=s.substr(left, wordLen);
                    --freq[to_be_removed];
                    if(freq[to_be_removed] == 0) freq.erase(to_be_removed);
                    left += wordLen;
                }
                
                ++freq[word];
                //cout<<left<<" "<<right<<endl;
                if(right - left + wordLen == allLen)
                {
                    ans.push_back(left);
                    --freq[s.substr(left, wordLen)];
                    left += wordLen;                    
                }
            }
            
            right += wordLen;
        }
    }
};

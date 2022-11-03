//2022-11-03
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> table;
        for(auto& word: words)
        {            
            ++table[word];                        
        }
                
        bool sameWordOddCnt=false;
        int ans=0;
        for(auto& it: table)
        {
            string word=it.first;
            int cnt=it.second;            
            if(word[0] == word[1])
            {
                if(cnt%2==1) sameWordOddCnt=true;
                
                cnt=cnt-cnt%2;
                ans += cnt*2;
            }
            else
            {
                string wordRev;
                wordRev.push_back(word[1]);
                wordRev.push_back(word[0]);
                if(!table.count(wordRev)) continue;
                
                cnt=min(cnt, table[wordRev]);                
                ans += cnt*4;
                
                table.erase(wordRev);
            }                       
        }
        
        if(sameWordOddCnt) ans += 2;
        return ans;
    }
};

//2022-11-03
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> table;
        int toBeMatched=0;
        int ans=0;
        for(auto& word: words)
        {
            if(word[0] == word[1])
            {
                if(table[word] > 0)
                {
                    ans+=4;
                    --table[word];
                    --toBeMatched;
                }
                else
                {
                    ++table[word];
                    ++toBeMatched;
                }
            }
            else
            {
                string wordRev;
                wordRev.push_back(word[1]);
                wordRev.push_back(word[0]);
                if(table[wordRev] > 0)                    
                {
                    ans+=4;
                    --table[wordRev];
                }
                else
                {
                    ++table[word];                    
                }
            }
        }
        
        if(toBeMatched > 0) ans += 2;
        return ans;
    }
};

//2022-11-03
//time  : O(n)
//space : O(26*26)
class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {        
        int ans=0;
        vector<vector<int>> table(26, vector<int>(26, 0));
        for(auto& word: words)
        {
            int r=word[0]-'a';
            int c=word[1]-'a';
            
            if(table[c][r] > 0)
            {
                ans+=4;
                --table[c][r];
            }
            else
            {
                ++table[r][c];
            }
        }
        
        for(int i=0; i<26; ++i)
        {
            if(table[i][i] > 0) 
            {
                ans+=2;
                break;
            }
        }
        
        return ans;
    }
};

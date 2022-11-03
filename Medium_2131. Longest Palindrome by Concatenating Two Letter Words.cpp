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

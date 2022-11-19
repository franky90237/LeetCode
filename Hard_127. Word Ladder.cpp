//2022--11-19
//time  : O(n*wordLen*26)
//sapce : O(wordLen)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> word(wordList.begin(), wordList.end());
        if(!word.count(endWord)) return 0;
        
        int n=beginWord.size();
        int len=1;
        queue<string> q;
        q.push(beginWord);        
        word.erase(beginWord);
        while(!q.empty())
        {
            int size=q.size();
            while(size > 0)
            {
                string cur=q.front();
                q.pop();
                if(cur == endWord) return len;
                
                for(int i=0; i<n; ++i)
                {
                    char tmp=cur[i];
                    for(char c='a'; c<='z'; ++c)
                    {
                        cur[i]=c;
                        if(!word.count(cur)) continue;
                        
                        q.push(cur);
                        word.erase(cur);
                        
                    }
                    cur[i]=tmp;
                }
                
                --size;
            }
            
            ++len;
        }
                                
        return 0;
    }    
};

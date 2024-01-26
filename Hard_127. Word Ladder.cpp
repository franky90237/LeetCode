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

//2024-01-26
//time  : O(n*n*m*26)
//space : O(m*n)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> table(wordList.begin(), wordList.end());
        if(table.count(endWord) == 0) return 0;
        
        unordered_set<string> vis;
        vis.insert(beginWord);
        
        queue<string> q;
        q.push(beginWord);
        
        int cnt=1;
        while(!q.empty())
        {            
            int size=q.size();
            for(; size > 0; --size)
            {
                string cur=q.front();
                q.pop();
                //cout<<cur<<endl;
                if(cur == endWord) return cnt;

                for(int i=0; i<cur.size(); ++i) //O(m*26*m)
                {
                    int original=cur[i];

                    for(char c='a'; c<='z'; ++c)
                    {
                        if(c == original) continue;

                        cur[i]=c;
                        if(vis.count(cur) == 0 && table.count(cur) != 0)
                        {                    
                            vis.insert(cur);
                            q.push(cur);
                        }                    
                    }

                    cur[i]=original;
                }                                
            }
            
            //cout<<endl;
            ++cnt;
        }
        
        return 0;
    }
};

//2024-01-26
//time  : O(n*n*m*26)
//space : O(m*n)
class Solution 
{
private:
    unordered_set<string> table;
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        for(auto& word : wordList) table.insert(word);
        if(table.count(endWord) == 0) return 0;
        
        unordered_set<string> visBegin;
        unordered_set<string> visEnd;
        
        visBegin.insert(beginWord);       
        visEnd.insert(endWord);
        
        queue<string> qBegin;  
        queue<string> qEnd;
        
        qBegin.push(beginWord);                
        qEnd.push(endWord);        
        
        int cnt=1;
        while(!qBegin.empty() && ! qEnd.empty())
        {
            if(qBegin.size() <= qEnd.size())
            {
                if(canFind(qBegin, visBegin, visEnd)) return cnt;
            }
            else
            {
                if(canFind(qEnd, visEnd, visBegin)) return cnt;                
            }
            
            //cout<<endl;
            ++cnt;
        }
        
        return 0;
    }
    
    bool canFind(queue<string>& q, unordered_set<string>& visBegin, unordered_set<string>& visEnd)
    {
        int size=q.size();
        for(; size > 0; --size)
        {
            string cur=q.front();
            q.pop();
            //cout<<cur<<endl;
            if(visEnd.count(cur) != 0) return true;
            
            for(int i=0; i<cur.size(); ++i) //O(m*26*m)
            {
                int original=cur[i];
                
                for(char c='a'; c<='z'; ++c)
                {
                    if(c == original) continue;

                    cur[i]=c;
                    if(visBegin.count(cur) == 0 && table.count(cur) != 0)
                    {
                        visBegin.insert(cur);
                        q.push(cur);
                    }                
                }
                
                cur[i]=original;
            }                                
        }
        
        return false;
    }
};

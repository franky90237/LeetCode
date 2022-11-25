//2022-11-25
//time  : O(len*n*26)
//space : O(n)
class Solution {
private:    
    vector<vector<string>> ans;
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> word(wordList.begin(), wordList.end());
        if(!word.count(endWord)) return ans;
        word.erase(beginWord);
                        
        unordered_map<string, int> node_to_len;
        node_to_len[beginWord]=1;
        int len=2;
        
        queue<string> q;
        q.push(beginWord);
        bool find=false;
        while(!q.empty() && !find)
        {
            int size=q.size();
            while(size > 0)
            {
                string cur=q.front();
                q.pop();
                //if(cur == endWord) break;
                
                for(int i=0; i<beginWord.size(); ++i)
                {
                    char tmp=cur[i];
                    for(char c='a'; c<='z'; ++c)
                    {
                        cur[i]=c;
                        if(!word.count(cur)) continue;
                        if(cur == endWord) find=true;
                        
                        node_to_len[cur]=len;                        
                        q.push(cur);
                        word.erase(cur);
                    }
                    cur[i]=tmp;
                }
                
                --size;
            }
            
            ++len;
        }        
        
        //cout<<len<<endl;
        //for(auto& it: node_to_len) cout<<"("<<it.first<<", "<<it.second<<") ";
        //cout<<endl;
        
        vector<string> cur;
        cur.push_back(endWord);
        dfs(endWord, node_to_len, len-1, cur);
        
        for(int i=0; i<ans.size(); ++i)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        
        return ans;
    }
    
    void dfs(string& end, unordered_map<string, int>& node_to_len, int len, vector<string>& cur)
    {
        //cout<<end<<" "<<len<<endl;    
        if(len == 1)
        {
            if(node_to_len.find(end) != node_to_len.end() && node_to_len[end] == 1)
            {            
                ans.push_back(cur);                
            }
            
            return;
        }
        
        for(int i=0; i<end.size(); ++i)
        {
            char tmp=end[i];
            
            for(char c='a'; c<='z'; ++c)
            {
                end[i]=c;
                if(node_to_len.find(end) == node_to_len.end() || node_to_len[end] != len-1) continue;
                
                cur.push_back(end);
                dfs(end, node_to_len, len-1, cur);
                cur.pop_back();
            }
            
            end[i]=tmp;
        }        
    }
};

//2022-06-01
//TLE
//use trie
class TrieNode
{
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode()
    {
        for(int i=0; i<26; ++i) children[i]=NULL;
        isWord=false;
    }
    
    void print(TrieNode* root)
    {
        string tmp="";
        dfs(root,tmp);
    }
        
    void dfs(TrieNode* root, string& tmp)
    {
        bool last=true;
        for(int i=0; i<26; ++i)
        {
            if((root->children)[i])
            {
                tmp.push_back(i+'a');
                dfs((root->children)[i],tmp);
                tmp.pop_back();
                
                last=false;
            }
        }
        
        if(last) cout<<tmp<<endl;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        TrieNode* root=buildTrie(wordDict);
        return search(root,root,s,0);
    }
    
    bool search(TrieNode* root, TrieNode* cur, string& s,int now)
    {
        if(now==s.size()) return cur->isWord;
        if(now>s.size()) return false;
        
        int idx=s[now]-'a';
        if(!(cur->children)[idx]) return false;
        cur=(cur->children)[idx];
        
        bool nextWord=false;
        if(cur->isWord) nextWord=search(root,root,s,now+1);
        if(nextWord) return true;
        
        return search(root,cur,s,now+1);
    }
    
    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode* root=new TrieNode();
        
        for(auto& word:words)
        {
            TrieNode* cur=root;
            
            for(auto& c:word)
            {
                if(!(cur->children)[c-'a']) (cur->children)[c-'a']=new TrieNode();
                cur=(cur->children)[c-'a'];
            }
            
            cur->isWord=true;
        }
        
        return root;
    }
};

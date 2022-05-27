//2022-05-27
//use trie data structure
class Trie 
{
private:
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
    };
    
    TrieNode* root;        
    
public:
    Trie()
    {
        root=new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* cur=root;
        
        for(auto& c:word)
        {
            if(!(cur->children)[c-'a'])
            {
                (cur->children)[c-'a']=new TrieNode();
            }
            
            cur=(cur->children)[c-'a'];
        }
        
        cur->isWord=true;
    }
    
    bool search(string word)
    {
        TrieNode* cur=root;
        return preorder(root,word,0);        
    }
    
    bool preorder(TrieNode* root, string& word, int now)
    {
        int n=word.size();
        
        if(!root) return false;
        if(now>=n) return root->isWord;
            
        if(word[now]=='.')
        {
            for(int i=0 ;i<26; ++i)
            {
                if((root->children)[i])
                {
                    bool isMatch=preorder((root->children)[i],word,now+1);
                    if(isMatch) return true;
                }
            }
        }
        else
        {
            if((root->children)[word[now]-'a'])
            {
                return preorder((root->children)[word[now]-'a'],word,now+1);
            }
        }
        
        return false;
    }
};


class WordDictionary
{
private:
    Trie trie;
    
public:
    WordDictionary()
    {
        
    }
    
    void addWord(string word)
    {
        trie.insert(word);
    }
    
    bool search(string word)
    {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

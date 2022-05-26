//2022-05-26
//use array to implement
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
        
        for(auto& c:word)
        {
            if(!(cur->children)[c-'a'])
            {
                return false;
            }
            
            cur=(cur->children)[c-'a'];
        }
        
        return cur->isWord;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* cur=root;
        
        for(auto& c:prefix)
        {
            if(!(cur->children)[c-'a'])
            {
                return false;
            }
            
            cur=(cur->children)[c-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

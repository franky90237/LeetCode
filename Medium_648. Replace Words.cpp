//2022-05-27
//use trie date structure
//time. : O(m+n), m is the total character of dictionary, n is the length of sentence
//space : O(m)
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
        
        ~TrieNode()
        {
            for(int i=0; i<26; ++i) delete children[i];
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
    
    void search(string& token, string& res)
    {
        TrieNode* cur=root;
        
        if(!(cur->children)[token[0]-'a'])
        {
            res+=token;
            return;
        }
        
        string tmp="";
        for(int i=0; i<token.size(); ++i)
        {
            if(!(cur->children)[token[i]-'a'] || cur->isWord) break;
            tmp.push_back(token[i]);
            
            cur=(cur->children)[token[i]-'a'];
        }
        
        if(cur->isWord) res+=tmp;
        else res+=token;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        Trie trie;
        
        for(auto& word:dictionary) trie.insert(word);
        
        int n=sentence.size();
        string res="";
        int start=0;
        while(start<n)
        {
            while(start<n && sentence[start]==' ') 
            {
                res.push_back(' ');
                ++start;
            }
            if(start>=n) break;
            
            string token="";
            while(start<n && sentence[start]!=' ') 
            {
                token.push_back(sentence[start]);
                ++start;
            }
            
            //cout<<token<<"-"<<res<<endl;
            trie.search(token,res);
        }
        
        return res;
    }
};

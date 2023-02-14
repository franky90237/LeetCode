//2023-02-14
//time  : O(n*n*s)
//space : O(n)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> ans;
        
        int n=words.size();
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(j == i || words[i].size() > words[j].size())
                {
                    continue;
                }
                
                int pos=words[j].find(words[i]);
                if(pos != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        
        return ans;
    }
};

//2023-02-14
//time  : O(n*s*s*s)
//space : O(n*s)
class TrieNode
{
public:
    vector<TrieNode*> next;
    int cnt;
    
    TrieNode()
    {        
        next.resize(26, NULL);
        cnt=0;
    }
};

class Trie
{
public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode;
    }
    
    void insert(string& s)
    {
        TrieNode* cur=root;
        
        for(auto c: s)
        {
            if(!cur->next[c-'a'])
            {
                TrieNode* node=new TrieNode;
                cur->next[c-'a']=node;
            }
            
            cur=cur->next[c-'a'];   
        }
        
        ++(cur->cnt);
    }
    
    bool find(TrieNode* cur, string& s, int i)
    {
        if(!cur)
        {
            return false;
        }
        
        if(i == s.size())
        {
            //cout<<s<<" "<<cur->cnt<<endl;
            return cur->cnt >= 2;
        }
        
        return find(cur->next[s[i]-'a'], s, i+1);
    }
    
    void print(TrieNode* cur)
    {
        if(!cur)
        {
            return;
        }
        
        for(int i=0; i<26; ++i)
        {
            if(!cur->next[i])
            {
                continue;
            }
            
            cout<<(char)(i+'a');
            print(cur->next[i]);
        }
        
        cout<<endl;
    }
};

class Solution 
{   
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        Trie trie;
        for(auto word: words)
        {            
            for(int l=0; l<word.size(); ++l)
            {
                string subword;
                for(int r=l; r<word.size(); ++r)
                {
                    subword = word.substr(l, r-l+1);
                    trie.insert(subword);
                }
            }
        }
        
        //trie.print(trie.root);
        
        vector<string> ans;
        for(auto word: words)
        {            
            if(trie.find(trie.root, word, 0))
            {
                ans.push_back(word);
            }            
        }
        
        return ans;
    }
};

//2023-02-14
//time  : O(n*s*s)
//space : O(n*s)
class TrieNode
{
public:
    vector<TrieNode*> next;
    int cnt;
    
    TrieNode()
    {        
        next.resize(26, NULL);
        cnt=0;
    }
};

class Trie
{
public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode;
    }
    
    void insert(string& s)
    {
        TrieNode* cur=root;
        
        for(auto c: s)
        {
            if(!cur->next[c-'a'])
            {
                TrieNode* node=new TrieNode;
                cur->next[c-'a']=node;
            }
            
            cur=cur->next[c-'a'];
            ++(cur->cnt);
        }                
    }
    
    bool find(string s)
    {
        TrieNode* cur=root;
        
        for(auto c: s)
        {
            if(!cur->next[c-'a'])
            {
                return false;
            }
            
            cur=cur->next[c-'a'];
        }
        
        return cur->cnt >= 2;
    }    
};

class Solution 
{   
public:
    vector<string> stringMatching(vector<string>& words) 
    {                
        Trie trie;        
        for(auto word: words)
        {            
            for(int l=0; l<word.size(); ++l)
            {
                string subword;                
                subword = word.substr(l);
                trie.insert(subword);                
            }
        }
        
        vector<string> ans;
        for(auto word: words)
        {
            if(trie.find(word))
            {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};

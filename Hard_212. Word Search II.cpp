//2022-05-30
//use trie data structure
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

class Trie 
{
private:
    TrieNode* root;
    
public:
    Trie()
    {
        root=new TrieNode();
    }
    
    TrieNode* getRoot()
    {
        return root;
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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        int m=board.size();
        int n=board[0].size();
        
        Trie trie;
        for(auto& word:words) trie.insert(word);
        
        TrieNode* cur=trie.getRoot();
        unordered_set<string> s;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                //printf("%d,%d \n",i,j);
                string tmp="";
                solve(i,j,board,words,tmp,s,cur);
            }
        }
        
        vector<string> res;
        for(auto& i:s) res.push_back(i);
        
        return res;
    }
    
    void solve(int r, int c, vector<vector<char>>& board, vector<string>& words, string& tmp, unordered_set<string>& s, TrieNode* cur)
    {
        int m=board.size();
        int n=board[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n) return;
        if(board[r][c]=='.') return;
        
        //printf("%d,%d \n",r,c);
        int idx=board[r][c]-'a';
        if(!(cur->children)[idx]) return;
        
        cur=(cur->children)[idx];
        tmp.push_back(board[r][c]);
        board[r][c]='.';
        
        if(cur->isWord) s.insert(tmp);
        
        int dir[5]={0,1,0,-1,0};
        for(int i=1; i<5; ++i)
        {
            int n_r=r+dir[i-1];
            int n_c=c+dir[i];
            
            solve(n_r,n_c,board,words,tmp,s,cur);
        }
        
        tmp.pop_back();
        board[r][c]=idx+'a';
    }
};

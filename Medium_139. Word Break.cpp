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

//2022-06-01
//dp recursive
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet;
        for(auto& word:wordDict) wordSet.insert(word);
        
        int n=s.size();        
        int dp[n+1];
        for(int i=0; i<n; ++i) dp[i]=-1;
        
        return search(dp,wordSet,s,0);
    }
    
    bool search(int dp[], unordered_set<string>& wordSet, string& s,int now)
    {
        if(now==s.size()) return true;        
        if(dp[now]!=-1) return dp[now];               
        
        for(int cut=now; cut<s.size(); ++cut)
        {
            string sub(s.begin()+now,s.begin()+cut+1);  
            //cout<<now<<","<<cut<<" "<<sub<<endl;
            if(wordSet.count(sub)!=0 && search(dp,wordSet,s,cut+1))
            {
                dp[cut+1]=true;
                return true;
            }            
        }
        
        dp[now]=false;
        return false;
    }
};

//2022-06-02
//dp iterative
//time : O(n*n)
//space : O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet;
        for(auto& word:wordDict) wordSet.insert(word);
        
        int n=s.size();
        bool dp[n+1];
        for(int i=1; i<=n; ++i) dp[i]=false;
        
        dp[0]=true;
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                //cout<<s.substr(j,i-j)<<endl;
                if(dp[j] && wordSet.count(s.substr(j,i-j)))
                {
                    //cout<<s.substr(j,i)<<endl;
                    dp[i]=true;
                    break;
                }
            }
            //cout<<endl;
        }
        
        //for(auto& i:dp) printf("%d \n",i);
        return dp[n];
    }
};

//2024-02-05
//time  : O(n*n)
//space : O(n + m*len)
class Solution 
{
private:
    unordered_set<string> table;
    vector<int> dp;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        for(string& word : wordDict) table.insert(word);
        
        int n=s.size();
        dp.resize(n, -1);
        
        return f(s, 0);
    }
    
    bool f(string& s, int cur)
    {
        int n=s.size();
        if(cur == n) return true;
        if(dp[cur] != -1) return dp[cur];
        
        string word;
        bool isFind=false;
        for(int right=cur; right<n; ++right)
        {
            word.push_back(s[right]);
            if(table.count(word) == 0) continue;
            
            isFind = f(s, right+1);
            if(isFind) break;
        }
        
        return dp[cur] = isFind;
    }
};

//2024-02-05
//time  : O(n*n)
//space : O(n + m*len)
class Solution 
{
private:
    unordered_set<string> table;
    vector<int> dp;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        for(string& word : wordDict) table.insert(word);
        
        int n=s.size();
        dp.resize(n+1);
        dp[n]=true;
        
        for(int i=n-1; i>=0; --i)
        {
            dp[i]=false;
            
            string word;
            for(int right=i; right<n; ++right)
            {
                word.push_back(s[right]);
                if(table.count(word) == 0) continue;
                
                dp[i] = dp[right+1];
                if(dp[i]) break;
            }
        }
        
        return dp[0];
    }    
};

//2024-02-06
//time  : O(n*n)
//space : O(n + m*len)
class TrieNode
{
public:
    bool isWord;
    vector<TrieNode*> child;
    
    TrieNode() : isWord(false)
    {
        child.resize(26, NULL);
    }
};

class Trie
{
private:
    TrieNode* root;
    
public:
    Trie()
    {
        root = new TrieNode;
    }
    
    void insert(string& s)
    {
        TrieNode* cur=root;
        for(char c : s)
        {
            if(!cur->child[c-'a'])
            {
                cur->child[c-'a'] = new TrieNode;
            }
            
            cur = cur->child[c-'a'];
        }
        
        cur->isWord=true;
    }
    
    bool search(TrieNode*& cur, char c)
    {
        cur = cur->child[c-'a'];
        if(!cur || !cur->isWord) return false;
        return true;
    }
    
    TrieNode* getRoot()
    {
        return root;
    }
};

class Solution 
{
private:
    unordered_set<string> table;
    vector<int> dp;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        Trie tr;
        
        for(string& word : wordDict) 
        {
            table.insert(word);
            tr.insert(word);
        }
        
        int n=s.size();
        dp.resize(n+1);
        dp[n]=true;
        
        for(int i=n-1; i>=0; --i)
        {
            dp[i]=false;
                       
            TrieNode* cur = tr.getRoot();
            for(int right=i; right<n; ++right)
            {
                bool isWord = tr.search(cur, s[right]);
                if(!cur) break;
                if(!isWord) continue;
                
                dp[i] = dp[right+1];
                if(dp[i]) break;
            }
        }
        
        return dp[0];
    }    
};

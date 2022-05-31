//2022-05-31
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        int n=words.size();
        
        vector<vector<int>> res;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i==j) continue;
                
                int start=0;
                int end=words[j].size()-1;
                while(start<words[i].size() && end>=0 && words[i][start]==words[j][end])
                {
                    ++start;
                    --end;
                }
                //printf("%d , %d \n",start,end);
                
                if(start>=words[i].size() && end<0)
                {
                    res.push_back({i,j});
                }
                else if(start<words[i].size() && end>=0 && words[i][start]!=words[j][end])
                {
                    continue;
                }
                else if(start<words[i].size())
                {
                    int k=words[i].size()-1;
                    while(start<k && words[i][start]==words[i][k])
                    {
                        ++start;
                        --k;
                    }
                    
                    if(start>=k) res.push_back({i,j});
                }
                else if(end>=0)
                {
                    int k=0;
                    while(k<end && words[j][k]==words[j][end])
                    {
                        ++k;
                        --end;
                    }
                    //printf("*** %d , %d \n",k,end);
                    if(k>=end) res.push_back({i,j});
                }
            }
        }
        
        return res;
    }
};

//2022-05-31
//use trie data structure
//time  : O(n*m)
//space : O(m)
class TrieNode
{
public:
    TrieNode* children[26];
    bool isWord;
    int index;
    
    TrieNode()
    {
        for(int i=0; i<26; ++i) children[i]=NULL;
        isWord=false;
        index=-1;
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
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        int n=words.size();
        
        vector<vector<int>> res;
        TrieNode* root=buildTrie(words,res);
        //root->print(root);
        
        for(int i=0; i<n; ++i)
        {
            if(words[i]=="") continue;
            
            TrieNode* cur=root;
            
            int start=0;
            int end=words[i].size()-1;
            
            while(start<=end)
            {
                int idx=words[i][start]-'a';
                if(!(cur->children)[idx]) break;

                //printf("%d , %d : %c\n",start,end);
                cur=(cur->children)[idx];
                ++start;
                if(cur->isWord)
                {
                    int l=start, r=end;
                    while(l<r)
                    {
                        //printf("%d , %d : %c\n",start,end);
                        if(words[i][l]!=words[i][r]) break;
                        ++l;
                        --r;
                    }
                    if(l>=r && i!=cur->index) res.push_back({i,cur->index});
                }
            }
            
            //printf("*%d , %d\n",start,end);
            if(start>end)
            {
                string tmp="";
                dfs_check(i,tmp,cur,res);
            }
        }
        
        return res;
    }
    
    void dfs_check(int idx, string& tmp, TrieNode* cur, vector<vector<int>>& res)
    {
        //cout<<tmp<<":"<<isPalindrome(tmp)<<":"<<cur->isWord<<":"<<cur->index<<endl;
        if(cur->isWord && cur->index!=idx && isPalindrome(tmp))
        {
            res.push_back({idx,cur->index});
        }
        
        for(int i=0; i<26; ++i)
        {
            if((cur->children)[i])
            {
                tmp.push_back(i+'a');
                dfs_check(idx,tmp,(cur->children)[i],res);
                tmp.pop_back();
            }
        }
    }
    
    TrieNode* buildTrie(vector<string>& words, vector<vector<int>>& res)
    {
        TrieNode* root=new TrieNode();
        
        for(int i=0; i<words.size(); ++i)
        {
            if(words[i]=="")
            {
                for(int j=0; j<words.size(); ++j)
                {
                    if(i!=j && isPalindrome(words[j])) 
                    {
                        res.push_back({i,j});
                        res.push_back({j,i});
                    }
                }
                
                continue;
            }
            
            TrieNode* cur=root;
            for(int j=words[i].size()-1; j>=0; --j)
            {
                char c=words[i][j];
                if(!(cur->children)[c-'a']) (cur->children)[c-'a']=new TrieNode();
                
                cur=(cur->children)[c-'a'];
            }
            
            cur->isWord=true;
            cur->index=i;
        }
        
        return root;
    }
    
    bool isPalindrome(string& word)
    {
        if(word=="") return false;
        
        int l=0;
        int r=word.size()-1;
        
        while(l<r)
        {
            if(word[l]!=word[r]) return false;
            ++l;
            --r;
        }
        
        return true;
    }
};

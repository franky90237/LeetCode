//2022-08-01
//time  : O(n*k), k is the ans size
//spce  : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans="";
        
        int min_size=INT_MAX;
        for(auto& str:strs) min_size=min(min_size,(int)str.size());
        
        int i=0;
        while(i<min_size)
        {
            int x;
            for(x=1; x<strs.size(); ++x)
            {
                if(strs[x][i]!=strs[x-1][i]) break;
            }
            
            if(x!=strs.size()) break;
            
            ans.push_back(strs[0][i]);
            ++i;
        }
        
        return ans;
    }
};

//2022-08-01
//trie
//time  : O(n*m), m is the size of max str
//spce  : O(n*m)
struct TrieNode
{
    bool is_word;
    unordered_map<char,TrieNode*> next;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        TrieNode* head=bulid_trie(strs);
        if(!head) return "";
        /*for(auto it=head; it->next.size()!=0; )
        {
            cout<<(it->next).begin()->first<<endl;
            it=(it->next).begin()->second;
        }*/
        
        string ans="";
        
        TrieNode* cur=head;
        //cout<<cur->next.size()<<endl;
        while(!cur->next.empty() && cur->next.size()==1 && !cur->is_word)
        {
            ans+=cur->next.begin()->first;
            cur=cur->next.begin()->second;            
        }
        
        return ans;
    }
    
    TrieNode* bulid_trie(vector<string>& strs)
    {
        TrieNode* head=new TrieNode;
        head->is_word=false;
        
        for(auto& str:strs)
        {
            if(str.empty()) return NULL;
            
            TrieNode* cur=head;
            for(auto& c:str)
            {
                if(cur->next.find(c) == cur->next.end())
                {
                    cur->next[c]=new TrieNode;
                    cur->next[c]->is_word=false;
                }
                
                cur=cur->next[c];
            }
            
            cur->is_word=true;
        }
        
        return head;
    }
};

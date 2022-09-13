//2022-09-13
//time  : O(n*m)
//space : O(n*m), m is the average size of each product
class trie_node
{
public:
    vector<trie_node*> next;
    bool isWord;
        
    trie_node()
    {
        next.resize(26,NULL);
        isWord=false;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        trie_node* root=build_trie(products);
        
        vector<vector<string>> ans;
        
        string substring="";        
        for(int i=0; i<searchWord.size(); ++i)
        {
            substring.push_back(searchWord[i]);
            
            vector<string> match;
            if(!search_trie(root,substring,match)) break;
            
            if(match.size()>3) 
            {
                sort(match.begin(),match.end());
                ans.push_back({match[0],match[1],match[2]});
            }
            else
            {
                ans.push_back(match);
            }            
            
            //cout<<match.size()<<" "<<ans.size()<<endl;
        }
        
        for(int i=ans.size(); i<searchWord.size(); ++i)
        {
            ans.push_back({});
        }
        
        return ans;
    }
    
    trie_node* build_trie(vector<string>& products)
    {
        trie_node* root=new trie_node();
        
        for(auto& product:products)
        {
            trie_node* cur=root;
            
            for(auto c:product)
            {
                int idx=c-'a';
                
                if(!cur->next[idx])
                {
                    trie_node* tmp=new trie_node();
                    cur->next[idx]=tmp;
                }
                
                cur=cur->next[idx];
            }
            
            cur->isWord=true;
        }
        
        return root;
    }
    
    bool search_trie(trie_node* root, string prefix, vector<string>& match)
    {        
        string tmp="";        
        for(auto& c:prefix)
        {
            tmp.push_back(c);
            int idx=c-'a';
            
            if(!root->next[idx]) return false;
            //if(root->isWord) match.push_back(tmp);
            
            root=root->next[idx];
        }
                
        dfs(root,tmp,match);
        
        return true;
    }
    
    void dfs(trie_node* root, string& tmp, vector<string>& match)
    {
        if(!root) return;
        if(root->isWord) match.push_back(tmp);
        
        for(int i=0; i<26; ++i)
        {
            if(root->next[i])
            {
                tmp.push_back(i+'a');
                dfs(root->next[i],tmp,match);
                tmp.pop_back();
            }
        }
    }
};

//2022-09-13
//time  : O(nlog(n)*m), m is the average len of each product
//space : O(1)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(),products.end());
        
        vector<vector<string>> ans;
            
        int l=0;
        int r=products.size()-1;
        int cur=0;
        while(l<=r && cur<searchWord.size())
        {
            while(l<=r)
            {
                if(cur<products[l].size() && products[l][cur]==searchWord[cur]) break;
                ++l;
            }
            
            while(l<=r)
            {
                if(cur<products[r].size() && products[r][cur]==searchWord[cur]) break;
                --r;
            }
            
            vector<string> match;
            
            for(int i=l; i<=r && i<l+3; ++i)
            {                
                match.push_back(products[i]);
            }
            
            ans.push_back(match);
            
            ++cur;
        }
        
        //cout<<cur<<endl;
        while(cur<searchWord.size())
        {
            ans.push_back({});
            ++cur;
        }
        
        return ans;
    }
};

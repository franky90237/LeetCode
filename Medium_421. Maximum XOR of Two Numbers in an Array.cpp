//2022-05-27
//use trie
//time  : O(n*k), k is the maximum bit length of num
//space : O(n*k)
class Solution {
private:
    class Trie 
    {
    private:
        class TrieNode
        {
        public:
            TrieNode* children[2];            

            TrieNode()
            {
                for(int i=0; i<2; ++i) children[i]=NULL;
            }
        };

        TrieNode* root;        

    public:
        Trie()
        {
            root=new TrieNode();
        }

        void insert(int num, int bit)
        {
            TrieNode* cur=root;
            
            for(int i=bit; i>=0; --i)
            {
                int tmp=(num>>i) & 1;
                if(!(cur->children)[tmp])
                {
                    (cur->children)[tmp]=new TrieNode();
                }
                
                cur=(cur->children)[tmp];
            }
        }

        int search(int num, int bit)
        {
            TrieNode* cur=root;
            
            int res=0;            
            int i;
            for(i=bit; i>=0; --i)
            {
                int tmp=(num>>i) & 1;
                if((cur->children)[!tmp])
                {
                    res=(res<<1) | 1;
                    cur=(cur->children)[!tmp];
                }
                else if((cur->children)[tmp])
                {
                    res=(res<<1);
                    cur=(cur->children)[tmp];
                }
                else
                {
                    break;
                }
            }
                        
            if(i>0) res=res<<i;
            
            return res;
        }
        
        void print()
        {
            string tmp="";
            dfs(root,tmp);
        }
        
        void dfs(TrieNode* root, string& tmp)
        {
            if(!(root->children)[0] && !(root->children)[1])
            {
                cout<<tmp<<endl;
                return;
            }
            
            for(int i=0; i<2; ++i)
            {
                if((root->children)[i])
                {
                    tmp.push_back(i+'0');
                    tmp.push_back(' ');
                    
                    dfs((root->children)[i],tmp);
                    
                    tmp.pop_back();
                    tmp.pop_back();
                }
            }
        }
    };
    
public:
    int findMaximumXOR(vector<int>& nums)
    {
        if(nums.size()==1) return 0;
        
        int max_num=0;
        for(auto& num:nums) max_num=max(max_num,num);
                
        Trie trie;
        int bit=(max_num==0) ? 1 : log2(max_num);
        for(auto& num:nums) trie.insert(num,bit);
        //cout<<bit<<endl;
        //trie.print();
        
        int max_xor=0;
        int max_diff=0;
        for(auto& num:nums) 
        {
            max_xor=max(max_xor,trie.search(num,bit));
        }
        
        return max_xor;
    }
};

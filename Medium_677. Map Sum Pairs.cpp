//2022-05-26
class MapSum 
{
private:
    class TrieNode
    {
    public:
        TrieNode* children[26];
        int val;
        
        TrieNode()
        {
            for(int i=0; i<26; ++i) children[i]=NULL;
            val=0;
        }
    };
    
    TrieNode* root;
    
public:
    MapSum() 
    {
        root=new TrieNode();
    }
    
    void insert(string key, int val)
    {
        TrieNode* cur=root;
        
        for(auto& c:key)
        {
            if(!(cur->children)[c-'a'])
            {
                (cur->children)[c-'a']=new TrieNode();
            }
            
            cur=(cur->children)[c-'a'];
        }
        
        cur->val=val;        
    }
    
    int sum(string prefix)
    {
        TrieNode* cur=root;
        
        int sum=0;
        for(auto& c:prefix)
        {
            if(!(cur->children)[c-'a'])
            {
                return sum;
            }
            
            cur=(cur->children)[c-'a'];
        }
        
        return MapSum_traverse_sum(cur);        
    }
    
    int MapSum_traverse_sum(TrieNode* root)
    {
        if(!root) return 0;
        
        int sum=0;        
        sum=sum+root->val;
        for(int i=0 ;i<26 ;++i)
        {            
            sum+=MapSum_traverse_sum((root->children)[i]);
        }
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

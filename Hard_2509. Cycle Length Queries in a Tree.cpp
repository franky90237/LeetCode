//2022-12-19
//time  : O(mn)
//space : O(m)
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) 
    {
        unordered_map<int, int> node_level;
        
        int m=queries.size();
        vector<int> ans(m);
        for(int i=0; i<m; ++i)
        {
            int a=queries[i][0];
            int b=queries[i][1];            
            int len=calculate_len(a, b, node_level);                        
            ans[i] = len;
        }
        
        return ans;
    }
    
    int calculate_len(int a, int b, unordered_map<int, int>& node_level)
    {        
        if(a > b) swap(a, b);
        
        int level_a=0;
        unordered_set<int> parent;    
        while(a > 0)
        {
            parent.insert(a);
            a /= 2;
            ++level_a;
        }
                
        int ancestor=-1;
        int level_b=0;
        int level_ancestor=0;
        while(b > 0)
        {
            if(ancestor == -1 && parent.count(b))
            {                
                ancestor=b;
                if(node_level.find(ancestor) != node_level.end())
                {
                    level_b += node_level[ancestor];
                    level_ancestor=node_level[ancestor];
                    break;
                }
            }            
            
            if(ancestor != -1)
            {
                ++level_ancestor;
            }
            
            b /= 2;
            ++level_b;
        }
        
        node_level[a]=level_a;
        node_level[b]=level_b;
        node_level[ancestor]=level_ancestor;
        return 1 + level_a - level_ancestor + level_b - level_ancestor;
    }
};

//2022-12-20
//time  : O(mn)
//space : O(m)
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) 
    {                
        int m=queries.size();
        vector<int> ans(m);        
        for(int i=0; i<m; ++i)
        {
            int a=queries[i][0];
            int b=queries[i][1];            
            
            int len_a=0;
            int len_b=0;
            while(a != b)
            {
                if(a > b)
                {
                    a /= 2;
                    ++len_a;
                }
                else
                {
                    b /= 2;
                    ++len_b;
                }
            }
            
            ans[i] = 1 + len_a + len_b;
        }
        
        return ans;
    }    
};

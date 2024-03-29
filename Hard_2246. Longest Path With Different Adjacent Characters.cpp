//2024-03-29
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<int>> g;
    int res = 0;
    
public:
    int longestPath(vector<int>& parent, string s) 
    {
        /*
        0 : {[0,1] [1,2]}
        
        */
        buildGraph(parent, s);
        
        dfs(s, 0);
        return res;
    }
    
    void buildGraph(vector<int>& parent, string& s)
    {
        int n = parent.size();
        g.resize(n);
        
        for(int i=1; i<n; ++i)
        {
            g[parent[i]].push_back(i);
        }                
    }
    
    int dfs(string& s, int cur)
    {
        int first=0;
        int second=0;
        for(auto next : g[cur])
        {                                      
            int len = dfs(s, next);
            
            if(s[next] == s[cur]) continue;
            
            if(len >= first)
            {
                second = first;
                first = len;
            }
            else if(len > second)
            {
                second = len;
            }                        
        }
        
        //cout<<cur<<" | "<<first<<" "<<second<<endl;
        res = max(res, first + second + 1);
        return max(first, second) + 1;
    }
};

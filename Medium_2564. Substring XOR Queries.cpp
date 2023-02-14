//2023-02-14
//time  : O(n*32)
//space : O(n*32)
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries)
    {
        int n=s.size();
        
        unordered_map<int, vector<int>> table;
        for(int i=0; i<n; ++i)
        {
            //cout<<i<<endl;
            
            if(s[i] == '0')
            {
                if(table.find(0) == table.end())
                {
                    table[0]={i, i};
                }
                
                continue;
            }
            
            int val=0;
            for(int j=i; j<i+31 && j<n; ++j)
            {
                val = val*2 + (s[j]-'0');
                if(table.find(val) == table.end())
                {
                    table[val]={i, j};
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto q: queries)
        {
            int first=q[0];
            int second=q[1];
            int val=first^second;
            
            if(table.find(val) == table.end())
            {
                ans.push_back({-1, -1});
            }
            else
            {
                ans.push_back(table[val]);
            }
        }
        
        return ans;
    }
};

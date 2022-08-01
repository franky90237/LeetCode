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

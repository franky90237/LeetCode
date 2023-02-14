//2023-02-14
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> ans;
        
        int n=words.size();
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(j == i || words[i].size() > words[j].size())
                {
                    continue;
                }
                
                int pos=words[j].find(words[i]);
                if(pos != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        
        return ans;
    }
};

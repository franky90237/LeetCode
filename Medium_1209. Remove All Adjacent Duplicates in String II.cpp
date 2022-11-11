//2022-11-11
//time  : O(n)
//space : O(n)
class Solution {
public:
    string removeDuplicates(string s, int k)
    {        
        int n=s.size();
        vector<pair<char, int>> stack;        
        for(int i=0; i<n; ++i)
        {
            int cnt=1;
            if(!stack.empty() && s[i] == stack.back().first)
            {
                cnt=stack.back().second + 1;
                stack.pop_back();
            }
            
            if(cnt != k)
            {
                stack.push_back({s[i], cnt});
            }            
        }

        int idx=0;
        for(int i=0; i<stack.size(); ++i)
        {
            char c=stack[i].first;
            int cnt=stack[i].second;
            for(int k=0; k<cnt; ++k)
            {
                s[idx]=c;
                ++idx;
            }
        }

        return s.substr(0, idx);
    }
};

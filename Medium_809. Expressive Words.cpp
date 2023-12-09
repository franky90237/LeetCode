//2023-12-09
//time  : O(n + m*len)
//space : O(n)
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) 
    {
        int n=words.size();
        vector<pair<char, int>> base;
        for(int i=0; i<n; ++i)
        {
            int right=i+1;
            while(right < n && s[right] == s[i])
            {
                ++right;
            }

            base.push_back({s[i], right-i+1});
            i=right-1;
        }

        int ans=0;
        for(string& word : words)
        {
            int cur=0;
            for(int i=0; i<n; ++i)
            {
                if(word[i] != base[cur].first) break;

                int right=i+1;
                while(right < n && s[right] == s[i])
                {
                    ++right;
                }
                
                int len=right-i+1;
                if((len != base[cur].second && base[cur].second < 3) || len > base[cur].second) break;
                ++cur;
                i=right-1;
            }

            if(cur >= base.size()) 
            {
                cout<<word<<endl;
                ++ans;
            }
        }

        return ans;
    }
};

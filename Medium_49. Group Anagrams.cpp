//hash of hash
//time  : O(n*mlogm), n=strs.size() and m=strs[].size()
//space : O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<int,unordered_map<string,vector<string>>> m;
        for(const auto& i:strs)
        {
            string s=i;
            sort(s.begin(),s.end());
            
            int sum=0;
            for(const auto& j:i) sum+=j;
            if(m.find(sum)!=m.end())
            {
                if(m[sum].find(s)!=m[sum].end()) m[sum][s].push_back(i);
                else m[sum][s].push_back(i);                
            }
            else m[sum][s].push_back(i);
        }
        
        vector<vector<string>> res;
        for(const auto& i:m)
        {
            for(const auto& j:i.second)
            {
                res.push_back(j.second);
            }
        }
        
        return res;
    }
};

//hash map with sorted each strs[i] as a key 
//time  : O(n*mlogm), n=strs.size() and m=strs[].size()
//space : O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> m;
        
        for(const auto& i:strs)
        {
            string s=i;
            sort(s.begin(),s.end());                        
            m[s].push_back(i);
        }
        
        vector<vector<string>> res;
        for(const auto& i:m)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};

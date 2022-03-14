//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int cur_len=0;
        int max_len=0;
        vector<char> sub;
        
        for(auto& i:s)
        {
            auto it=find(sub.begin(),sub.end(),i);
            if(it!=sub.end()) 
            {
                sub.erase(sub.begin(),it+1);
                max_len=max(max_len,cur_len);
            }
            
            sub.push_back(i);
            cur_len=sub.size();
        }
        
        //for(auto& i:sub) cout<<i;
        
        return max(max_len,cur_len);
    }
};

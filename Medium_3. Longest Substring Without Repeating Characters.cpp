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

//time  : O(n)
//space : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> m;
        
        int cur_len=0;
        int max_len=0;
        int start=0;
        for(int i=0; i<s.size(); ++i)
        {
            if(m.find(s[i])!=m.end() && m[s[i]]>=start)
            {
                cur_len=i-m[s[i]];
                start=m[s[i]];
            }
            else ++cur_len;
            //cout<<cur_len<<" ";
            
            m[s[i]]=i;
            max_len=max(max_len,cur_len);
        }
        
        return max_len;
    }
};

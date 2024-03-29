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

//2022-08-01
//time  : O(n)
//space : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        /*
        abcabcbb
        abba
        */
        
        unordered_map<char,int> table;
        
        int len=0;
        int start=0;
        for(int i=0; i<s.size(); ++i)
        {
            if(table.find(s[i])!=table.end())
            {
                //abba
                start=max(start,table[s[i]]+1);                
            }
            
            table[s[i]]=i;            
            len=max(len,i-start+1);
        }
        
        return len;
    }
};

//2023-02-26
//time  : O(n)
//space : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {        
        unordered_map<char, int> table;
        
        int l=0;
        int ans=0;
        for(int i=0; i<s.size(); ++i)
        {                        
            if(table.find(s[i]) != table.end() && table[s[i]] >= l)
            {
                l=table[s[i]]+1;
            }
            else
            {
                ans=max(ans, i-l+1);
            }
                        
            table[s[i]]=i;
        }
                
        return ans;
    }
};

//2023-05-09
//time  : O(n)
//psace : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {        
        set<char> table;
        int n=s.size();
        int ans=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            while(table.count(s[right]))
            {
                table.erase(s[left]);
                ++left;
            }
            
            table.insert(s[right]);
            ans=max(ans, right-left+1);
        }
        
        return ans;
    }
};

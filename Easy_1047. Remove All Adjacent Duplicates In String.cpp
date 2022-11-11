//2022-11-11
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    string removeDuplicates(string s) 
    {
        int n=s.size();
        string ans;
        for(int i=0; i<n; ++i)
        {
            if(!ans.empty() && s[i] == ans.back())
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

//2022-11-11
//time  : O(n)
//spcae : O(1)
class Solution {
public:
    string removeDuplicates(string s) 
    {
        int n=s.size();
        int top=-1;
        int cur=0;
        while(cur < n)
        {
            if(top == -1 || s[top] != s[cur])
            {
                ++top;
                s[top]=s[cur];
            }
            else
            {
                --top;
            }

            ++cur;    
        }

        return s.substr(0, top+1);
    }
};

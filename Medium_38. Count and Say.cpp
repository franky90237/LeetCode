//2022-04-29
class Solution {
public:
    string countAndSay(int n)
    {
        string pre="1";
        string cur="";
        
        for(int i=2; i<=n; ++i)
        {
            say(cur,pre);
            //cout<<cur<<endl;
            //swap(cur,pre);
            pre=cur;
            cur="";
        }
        
        return pre;
    }
    
    void say(string& cur, string& pre)
    {
        int n=pre.size();
        
        int cnt=1;
        for(int i=0; i<n; ++i)
        {
            if(i+1<n && pre[i]==pre[i+1])
            {
                ++cnt;
            }
            else
            {
                cur.push_back(cnt+'0');
                cur.push_back(pre[i]);
                cnt=1;
            }
        }
    }
};

//2022-10-18
class Solution {
public:
    string countAndSay(int n) 
    {
        if(n == 1) return "1";
        
        string num=countAndSay(n-1);
        string res;
        for(int i=0; i<num.size(); ++i)
        {
            int right=i;
            while(right < num.size() && num[i] == num[right])
            {
                ++right;
            }
            
            int cnt=right-i;
            res = res + to_string(cnt);
            res.push_back(num[i]);
            
            i=right-1;
        }
        
        return res;
    }
};

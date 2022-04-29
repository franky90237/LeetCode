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

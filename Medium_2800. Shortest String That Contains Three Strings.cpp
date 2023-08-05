//2023-08-05
//time  : O(n*n)
//spcae : O(n)
class Solution {
public:
    string minimumString(string a, string b, string c)
    {
        /*
        string s="bca";
        build(s, b);
        cout<<s<<endl;
        return s;
        */
        vector<string> ans(6);
        ans[0]=build(a, b, c);
        ans[1]=build(a, c, b);
        ans[2]=build(b, a, c);
        ans[3]=build(b, c, a);
        ans[4]=build(c, a, b);
        ans[5]=build(c, b, a);
        
        string res=ans[0];
        for(int i=1; i<ans.size(); ++i)
        {
            //cout<<ans[i]<<endl;
            if(ans[i].size() < res.size())
            {
                res=ans[i];
            }
            else if(ans[i].size() == res.size() && ans[i] < res)
            {
                res=ans[i];
            }
        }
        
        return res;
    }
    
    string build(string& a, string& b, string& c)
    {
        string ans=a;
        build(ans, b);
        build(ans, c);
        return ans;
    }
    
    void build(string& a, string& b)
    {
        int aSize=a.size();
        int bSize=b.size();
        
        if(aSize >= bSize && a.find(b) != string::npos) return;
        
        int len=min(aSize, bSize);
        while(len > 0)
        {
            if(a.substr(aSize-len) == b.substr(0, len)) break;
            --len;
        }

        a += b.substr(len);                
    }
};

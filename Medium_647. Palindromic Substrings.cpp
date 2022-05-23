//2022-05-23
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n=s.size();
        
        int res=n;
        for(int cnt=2; cnt<=n; ++cnt)
        {
            for(int start=0; start+cnt-1<n; ++start)
            {
                //cout<<s.substr(start,cnt)<<" "<<start+cnt-1<<endl;
                res+=is_palindromic(s,start,start+cnt-1);
            }
        }
        
        return res;
    }
    
    bool is_palindromic(string& s, int start, int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end]) return false;
            
            ++start;
            --end;
        }
        
        return true;
    }
};

//2022-05-23
//dp
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n=s.size();
        
        vector<vector<int>> substring(n,vector<int>(n,-1));
        
        int res=n;
        for(int cnt=2; cnt<=n; ++cnt)
        {
            for(int start=0; start+cnt-1<n; ++start)
            {
                int end=start+cnt-1;
                //cout<<s.substr(start,cnt)<<" "<<start+cnt-1<<endl;
                
                if(substring[start][end]==-1)
                {
                    //cout<<s.substr(start,cnt)<<endl;
                    bool flag=is_palindromic(substring,s,start,end);
                    substring[start][end]=flag;
                }
                
                res+=substring[start][end];
                
            }
        }
        
        return res;
    }
    
    bool is_palindromic(vector<vector<int>>& substring, string& s, int start, int end)
    {
        while(start<end)
        {
            if(substring[start][end]!=-1) return substring[start][end];
            if(s[start]!=s[end]) return false;
            
            ++start;
            --end;
        }
        
        return true;
    }
};

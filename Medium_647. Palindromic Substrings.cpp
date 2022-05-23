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

//2022-05-23
//inner to outer
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n=s.size();
        
        int res=0;
        for(int i=0; i<n; ++i)
        {
            int odd=is_palindromic(s,i,i);
            int even=is_palindromic(s,i,i+1);
            //printf("%d, %d \n",odd,even);
            
            res=res+odd+even;
        }
        
        return res;
    }
    
    int is_palindromic(string& s, int left, int right)
    {
        int cnt=0;
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            ++cnt;
            //printf("%c %c %d\n",s[left],s[right],cnt);
            
            --left;
            ++right;
        }
        
        return cnt;
    }
};

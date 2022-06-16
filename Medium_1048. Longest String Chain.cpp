//2022-06-16
//TLE
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int n=words.size();
        
        int len=1;
        for(int i=0; i<n; ++i)
        {
            len=max(len,solve(i,words));
            //cout<<i<<" "<<len<<endl;
        }
        
        return len;
    }
    
    int solve(int pre, vector<string>& words)
    {
        int n=words.size();
        //if(pre==n) return 1;
        
        int len=1;
        for(int i=0; i<n; ++i)
        {
            if(pre!=i && check_predecessor(pre,i,words))
            {
                len=max(len,1+solve(i,words));
            }
        }
        
        return len;
    }
    
    bool check_predecessor(int pre, int now, vector<string>& words)
    {
        if(words[now].size()!=words[pre].size()+1) return false;
        
        for(int exclude=0; exclude<words[now].size(); ++exclude)
        {
            int j=0;
            for(int i=0; i<words[now].size(); ++i)
            {
                if(i==exclude) continue;
                if(words[now][i]!=words[pre][j]) break;
                ++j;
            }
            
            if(j==words[pre].size()) return true;
        }
        
        return false;
    }
};

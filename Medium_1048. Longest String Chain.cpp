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

//2022-06-16
//dp recursive
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int n=words.size();
        
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=-1;
        
        int len=1;
        for(int i=0; i<n; ++i)
        {
            len=max(len,solve(i,words,dp));
            //cout<<i<<" "<<len<<endl;
        }
        
        return len;
    }
    
    int solve(int pre, vector<string>& words, int dp[])
    {
        int n=words.size();        
        if(dp[pre]!=-1) return dp[pre];
        
        int len=1;
        for(int i=0; i<n; ++i)
        {
            if(pre!=i && check_predecessor(pre,i,words))
            {
                len=max(len,1+solve(i,words,dp));
            }
        }
        
        dp[pre]=len;
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

//2022-06-17
//dp iterative
//time  : O(n*m*m)
//space : O(n*m)
class Solution 
{
private:
    struct Mycomparator
    {
        bool operator()(string& a, string& b) 
        {
            return a.size()<b.size();
        }
    } comparator;
    
public:
    int longestStrChain(vector<string>& words)
    {
        //O(nlog(n))
        sort(words.begin(),words.end(),comparator);
        
        unordered_map<string,int> dp;
        int res=1;
        for(auto& word:words)
        {
            for(int i=0; i<word.size(); ++i)
            {
                string pre=word.substr(0,i) + word.substr(i+1);
                int len=(dp.find(pre)==dp.end()) ? 1 : 1+dp[pre];
                dp[word]=max(dp[word],len);                
            }
            
            res=max(res,dp[word]);
        }
        
        return res;
    }
};

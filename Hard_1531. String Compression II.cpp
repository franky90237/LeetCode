//2022-10-15
//time  : O(2^(n-k))
//space : O(n)
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) 
    {
        int n=s.size();
        vector<int> valid(n, true);        
        
        return solve(s, k, valid, 0);
    }
    
    int solve(string& s, int k, vector<int>& valid, int cur)
    {
        int n=s.size();
        if(k == 0) return runLength(s, valid);
        if(n-cur < k) return INT_MAX;        
        
        int keep=solve(s, k, valid, cur+1);
        
        valid[cur]=false;
        int remove=solve(s, k-1, valid, cur+1);
        valid[cur]=true;
        
        //cout<<cur<<", "<<k<<" : "<<keep<<" | "<<remove<<endl;        
        return min(keep, remove);
    }
    
    int runLength(string& s, vector<int>& valid)
    {        
        int totalLen=0;
        int left=0;
        while(left < s.size())
        {
            if(!valid[left])
            {
                ++left;
                continue;
            }
            
            int len=0;
            int right=left;
            while(right < s.size() && (s[right] == s[left] || !valid[right]))
            {
                if(valid[right]) ++len;
                ++right;                
            }                             
            
            ++totalLen;
            if(len != 1)
            {
                totalLen += to_string(len).size();
            }
            
            left=right;
        }
        
        return totalLen;
    }
};

//2022-10-16
//dp
//time  : O(26*n*n*k)
//space : O(26*n*n*k)
int dp[27][101][101][101];
class Solution 
{ 
public:
    int getLengthOfOptimalCompression(string s, int k) 
    {
        //vector<vector<vector<vector<int>>>> dp(27, vector<vector<vector<int>>>(101, vector<vector<int>>(s.size()+1, vector<int>(s.size()+1, -1) ) ) );
        memset(dp, -1, sizeof(dp));
        return solve(s, '{', 0, 0, k);
    }
    
    int solve(string& s, char preChar, int cnt, int cur, int k)
    {        
        int n=s.size();        
        if(cur >= n) return numberOfDigits(cnt);
        if(dp[preChar-'a'][cnt][cur][k] != -1) return dp[preChar-'a'][cnt][cur][k];
        
        //cout<<cur<<" "<<preChar<<" "<<cnt<<endl;
        int res=INT_MAX;
        if(k > 0) res=min(res, solve(s, preChar, cnt, cur+1, k-1));
        
        if(s[cur] == preChar)
        {
            res=min(res, solve(s, preChar, cnt+1, cur+1, k));
        }
        else
        {
            res=min(res, numberOfDigits(cnt) + 1 + solve(s, s[cur], 1, cur+1, k));
        }
        
        dp[preChar-'a'][cnt][cur][k]=res;
        return res;
    }
    
    int runLength(string& s, char preChar, int cnt, int cur)
    {
        int n=s.size();
        if(cur >= n) return numberOfDigits(cnt);
        
        //cout<<cur<<" "<<preChar<<" "<<cnt<<endl;        
        if(s[cur] == preChar)
        {
            return runLength(s, preChar, cnt+1, cur+1);
        }
        else
        {
            return numberOfDigits(cnt) + 1 + runLength(s, s[cur], 1, cur+1);
        }
    }
    
    int numberOfDigits(int num)
    {        
        if(num <= 1) return 0;
        else if(num <= 9) return 1;
        else if(num <= 99) return 2;
        else return 3;
    }
};

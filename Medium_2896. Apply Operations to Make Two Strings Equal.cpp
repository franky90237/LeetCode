//2023-10-09
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    vector<vector<vector<int>>> dp;
    
public:
    int minOperations(string s1, string s2, int x) 
    {
        int cnt=0;
        for(int i=0; i<s1.size(); ++i)
        {
            if(s1[i] != s2[i]) ++cnt;
        }
        
        if(cnt%2 == 1) return -1;
        if(cnt == 0) return 0;
        
        dp.resize(s1.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(s1, s2, x, 0, false, false);
    }
    
    int solve(string& s1, string& s2, int x, int cur, bool flipNext, bool flipAny)
    {
        //cout<<cur<<" "<<flipNext<<" "<<flipAny<<endl;
        int n=s1.size();
        if(cur >= n) return 0;
        if(dp[cur][flipNext][flipAny] != -1) return dp[cur][flipNext][flipAny];
        
        char s1_cur=s1[cur];
        if(flipNext) s1_cur = flip(s1[cur]);
        
        int ans=INT_MAX;
        if(s1_cur == s2[cur])
        {
            ans = solve(s1, s2, x, cur+1, false, flipAny);
        }
        else
        {
            int doNext = 1 + solve(s1, s2, x, cur+1, true, flipAny);
            
            int flipAnyCost = flipAny ? 0 : x;        
            int doAny = flipAnyCost + solve(s1, s2, x, cur+1, false, !flipAny);
            
            //cout<<cur<<" : "<<doNext<<" "<<doAny<<endl;
            ans = min(doNext, doAny);
        }
            
        dp[cur][flipNext][flipAny]=ans;
        return ans;
    }
    
    char flip(char c)
    {
        if(c == '0') return '1';
        return '0';
    }
};

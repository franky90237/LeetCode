//2022-10-20
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int ans=INT_MAX;
        int n=s.size();
        for(int zeros=n; zeros>=0; --zeros)
        {
            int flips=calculate(s, zeros);
            if(flips == 0) return 0;
            //cout<<zeros<<" "<<flips<<endl;
            ans=min(ans, flips);
        }
        
        return ans;
    }
    
    int calculate(string& s, int zeros)
    {
        int flips=0;
        int i=0;
        while(i < zeros)
        {
            if(s[i] != '0') ++flips;
            ++i;
        }
        
        while(i< s.size())
        {
            if(s[i] != '1') ++flips;
            ++i;
        }
        
        return flips;
    }
};

//2022-10-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        const int n=s.size();
        int diffZeros[n];
        diffZeros[0]=(s[0] != '0') ? 1 : 0;
        for(int i=1; i<n; ++i)
        {
            diffZeros[i]=diffZeros[i-1];
            if(s[i] != '0') ++diffZeros[i];
            //cout<<diffZeros[i]<<" ";
        }
        
        //cout<<endl;
        
        int diffOnes[n];
        diffOnes[n-1]=(s[n-1] != '1') ? 1 : 0;        
        for(int i=n-2; i>=0; --i)
        {
            diffOnes[i]=diffOnes[i+1];
            if(s[i] != '1') ++diffOnes[i];
            //cout<<diffOnes[i]<<" ";
        }
        
        int ans=INT_MAX;        
        for(int i=-1; i<n; ++i)
        {
            //int flips=calculate(s, zeros);
            int diff0=(i == -1) ? 0 : diffZeros[i];
            int diff1=(i+1 == n) ? 0 : diffOnes[i+1];            
            int flips=diff0+diff1;            
            if(flips == 0) return 0;
            //cout<<i<<" "<<diff0<<" "<<diff1<<endl;
            ans=min(ans, flips);
        }
        
        return ans;
    }    
};

//2022-10-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int oneCnt=0;
        int flipCnt=0;
        for(auto& c: s)
        {
            if(c == '1')
            {
                ++oneCnt;
            }
            else
            {
                int flip_c_to_1_cnt = flipCnt+1;
                int flip_all_1_to_0_cnt=oneCnt;
                flipCnt=min(flip_c_to_1_cnt, flip_all_1_to_0_cnt);
            }
        }
        
        return flipCnt;
    }    
};

//2023-12-04
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minFlipsMonoIncr(string s)
    {
        int n=s.size();

        vector<int> prefix(n+1, 0);        
        for(int i=1; i<=n; ++i)
        {
            prefix[i]=prefix[i-1];
            if(s[i-1] == '1') ++prefix[i];                       
        }

        vector<int> suffix(n+1, 0);        
        for(int i=n-1; i>=0; --i)
        {
            suffix[i]=suffix[i+1];
            if(s[i] == '0') ++suffix[i];
        }
        
        //for(int i: prefix) cout<<i<<" "; cout<<endl;
        //for(int i: suffix) cout<<i<<" "; cout<<endl;

        int ans=n;
        for(int cut=0; cut<=n; ++cut)
        {
            ans=min(ans, prefix[cut]+suffix[cut]);
        }

        return ans;
    }
};

//203-12-04
//time  : O(2*n)
//spcae : O(2*n)
class Solution
{
private:
    vector<vector<int>> dp;

public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.size();
        dp.resize(2, vector<int>(n, -1));
        int longestIncreasingSubsequenceSize=solve(s, 0, 0);        
        return n-longestIncreasingSubsequenceSize;
    }

    int solve(string&s , int preVal, int curIdx)
    {
        int n=s.size();        
        if(curIdx >= n) return 0;        
        if(dp[preVal][curIdx] != -1) return dp[preVal][curIdx];

        int ans1 = 0;        
        if((s[curIdx]-'0') >= preVal)
        {
            ans1 = 1 + solve(s, s[curIdx]-'0', curIdx+1);
        }

        int ans2 = solve(s, preVal, curIdx+1);
        //cout<<curIdx<<" "<<preVal<<" : "<<ans1<<" "<<ans2<<endl;
        return dp[preVal][curIdx] = max(ans1, ans2);
    }
};

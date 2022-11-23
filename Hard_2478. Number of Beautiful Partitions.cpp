//2022-11-23
//time  : O(n*k)
//space : O(n*k)
class Solution {
private:
    int mod=1e9+7;
    
public:
    int beautifulPartitions(string s, int k, int minLength) 
    {
        if(!isPrime(s[0])) return 0;
        
        int n=s.size();
        vector<bool> begin(n, false);
        for(int i=0; i<n; ++i)
        {
            if((i!=0 && isPrime(s[i-1])) || !isPrime(s[i])) continue;
            begin[i]=true;            
        }
        
        vector<vector<int>> dp(s.size(), vector<int>(k+1, 0));
        vector<vector<int>> postSum(s.size()+1, vector<int>(k+1, 0));
        for(int i=n-1; i>=0; --i)
        {
            dp[i][1]= ((n-i) >= minLength) && (i==0 || !isPrime(s[i-1])) && isPrime(s[i]) && !isPrime(s[n-1]);
            postSum[i][1] = postSum[i+1][1] + dp[i][1];
        }
        
        //for(int i=n-1; i>=0; --i)
        for(int x=2; x<=k; ++x)
        {
            //for(int x=2; x<=k; ++x)
            for(int i=n-1; i>=0; --i)
            {
                postSum[i][x] += postSum[i+1][x];
                if(!begin[i]) continue;
                
                int next=(i+minLength < n) ? i+minLength : n;
                dp[i][x] = (postSum[next][x-1]) % mod;                
                postSum[i][x] = (postSum[i][x] + dp[i][x]) % mod;
            }
        }
        
        /*for(int i=0; i<n; ++i) cout<<s[i]<<" ";
        cout<<endl<<"---------------------------"<<endl;
        
        for(int x=k; x>=0; --x)
        {
            for(int i=0; i<n; ++i) cout<<dp[i][x]<<" ";
            cout<<endl;
        }
        
        cout<<endl;
        for(int x=k; x>=0; --x)
        {
            for(int i=0; i<n; ++i) cout<<postSum[i][x]<<" ";
            cout<<endl;
        }*/
        
        return dp[0][k];        
    }
    
    bool isPrime(char c)
    {
        int num=c-'0';
        return num == 2 || num == 3 || num == 5 || num == 7;
    }
};

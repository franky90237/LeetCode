//2023-09-11
//time  : O(n*10*10*2*2)
//space : O(n*10*2*2)
class Solution 
{
private:
    int modulo=1e9+7;
    vector<vector<vector<vector<int>>>> dp;
    
public:
    int countSteppingNumbers(string low, string high) 
    {        
        decrease(low);
        //cout<<low<<" "<<high<<endl;
        
        dp.resize(high.size(), vector<vector<vector<int>>>(10, vector<vector<int>>(2, vector<int>(2, -1))));
        long res1 = solve(high, (high[0]-'0'+1)%10, 0, false, true);
        
        //dp.clear();
        dp.assign(low.size(), vector<vector<vector<int>>>(10, vector<vector<int>>(2, vector<int>(2, -1))));
        /*for(int i=0; i<low.size(); ++i) 
        {                        
            cout<<dp[i][0][0]<<" "; cout<<dp[i][0][1]<<" "; cout<<dp[i][1][0]<<" "; cout<<dp[i][1][1]<<" "; cout<<endl;
        }*/
        long res2 = solve(low, (low[0]-'0'+1)%10, 0, false, true);        
        //cout<<res1<<" "<<res2<<endl;
        return (res1+modulo-res2)%modulo;
    }
    
    void decrease(string& s)
    {
        if(s.size() == 1)
        {
            if(s[0] != '0') --s[0];
            return;
        }
        
        for(int i=s.size()-1; i>=0; --i)
        {
            if(s[i] != '0')
            {
                --s[i];                
                break;
            }
            
            s[i]='9';
        }
        
        if(s[0] == '0')
        {
            s.erase(0, 1);
        }
    }
    
    long solve(string& num, int preDigit, int cur, bool isSmall, bool isLeadingZero)
    {
        //cout<<cur<<" : "<<preDigit<<endl;
        int n=num.size();       
        if(cur == n) return 1;
        if(dp[cur][preDigit][isSmall][isLeadingZero] != -1) return dp[cur][preDigit][isSmall][isLeadingZero];
                
        int end = isSmall ? 9 : num[cur]-'0';
        //cout<<cur<<" : "<<isSmall<<" "<<isLeadingZero<<" | "<<end<<endl;
        long res=0;
        for(int digit=0; digit<=end; ++digit)
        {
            if(isLeadingZero || (abs(preDigit-digit) == 1))
            {
                //cout<<digit<<endl;
                bool newIsSmall = true;
                if(!isSmall && digit == end) newIsSmall = false;
                bool newIsLeadingZero = false;
                if(isLeadingZero && digit == 0) newIsLeadingZero=true;
                
                int cnt = solve(num, digit, cur+1, newIsSmall, newIsLeadingZero);
                //cout<<"******"<<cur<<" "<<digit<<" "<<cnt<<endl;
                res = (res + cnt) % modulo;
            }
        }
        
        //cout<<cur<<" : "<<isSmall<<" "<<isLeadingZero<<" | "<<end<<", "<<res<<endl<<endl;
        //cout<<cur<<" "<<res<<endl;
        dp[cur][preDigit][isSmall][isLeadingZero]=res;
        return res;
    }
};

//2023-09-14
//time  : O(n*10*10)
//spcae : O(n*10)
class Solution 
{
private:
    int modulo=1e9+7;
    vector<vector<int>> dp;
    
public:
    int countSteppingNumbers(string low, string high) 
    {
        //dp[len][num] : starting at num with length len
        //dp[i][j] = dp[i-1][x] where abs(j-x) is 1
        dp.resize(high.size()+1, vector<int>(10, 0));      
        //dp[1][0]=0;
        for(int digit=0; digit<=9; ++digit) dp[1][digit]=1;        
        for(int len=2; len<=high.size(); ++len)
        {
            for(int curDigit=0; curDigit<=9; ++curDigit)
            {
                for(int preDigit=0; preDigit<=9; ++preDigit)
                {
                    if(abs(curDigit-preDigit) == 1) dp[len][curDigit] = (dp[len][curDigit] + dp[len-1][preDigit]) % modulo;
                }
                
                //cout<<dp[len][curDigit]<<" ";
            }
            
            //cout<<endl;
        }
        
        //cout<<query(high)<<" "<< query(low)<<endl;
        int ans = query(high) - query(low) + isSteppingNumber(low);
        ans = (ans + modulo) % modulo;
        
        return ans;
    }
    
    int query(string& num)
    {
        int maxLen=num.size();
        reverse(num.begin(), num.end());
        //cout<<num<<" : ";
        int res=0;
        
        //len is smaller than num
        for(int len=1; len<maxLen; ++len)
        {
            for(int digit=1; digit<=9; ++digit)
            {
                res = (res + dp[len][digit]) % modulo;
            }
        }
        //cout<<res<<" ";
        
        //len is equal to num, but highest digit is less than num
        for(int digit=1; digit<num[maxLen-1]-'0'; ++digit)
        {
            res = (res + dp[maxLen][digit]) % modulo;
        }
        //cout<<res<<" ";
        
        //len is equal to num, and higher digit is equal to num
        for(int len=maxLen-1; len>=1; --len)
        {
            for(int curDigit=0; curDigit<num[len-1]-'0'; ++curDigit)
            {
                int preDigit=num[len]-'0';
                if(abs(curDigit-preDigit) == 1) res = (res + dp[len][curDigit]) % modulo;
            }
            
            if(abs(num[len]-num[len-1]) != 1) break;
        }
        
        //cout<<res<<" "<<endl;
        return res + isSteppingNumber(num);
    }
    
    bool isSteppingNumber(string& num)
    {
        for(int i=1; i<num.size(); ++i)
        {
            if(abs(num[i]-num[i-1]) != 1) return false;
        }
        
        return true;
    }
};

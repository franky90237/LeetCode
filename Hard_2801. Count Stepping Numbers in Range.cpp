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

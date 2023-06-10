//2023-06-10
//time  : O(#digits*max_sum*2*2*10)
//space : O(#digits*max_sum*2*2)
class Solution 
{
private:
    //vector<vector<vector<vector<int>>>> dp;
    int dp[23][401][2][2];
    int modulo=1e9+7;
    string n1;
    string n2;
    //int digitMin;
    //int digitMax;
    
public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int zeros=num2.size()-num1.size();
        n1=string(zeros, '0') + num1;
        n2=num2;
        
        //cout<<n1<<" "<<n2<<endl;
        //digitMin=min_sum;
        //digitMax=max_sum;
        
        //dp.resize(vector<vector<vector<int>>>(vector<vector<int>>(vector<int>(-1))));
        memset(dp, -1, sizeof(dp));
        //cout<<sizeof(dp)<<endl;
        bool lowest  = true;
        bool highest = true;
        //if(n1[0] == n2[0]) highest=true;
        return solve(0, 0, lowest, highest, min_sum, max_sum);
    }
    
    int solve(int cur, int sum, bool lowest, bool highest, int min_sum, int max_sum)
    {
        int n=n2.size();
        if(sum > max_sum) return 0;
        if(cur >= n) 
        {
            if(min_sum <= sum && sum <= max_sum) return 1;
            else return 0;
        }
        if(dp[cur][sum][lowest][highest] != -1) return dp[cur][sum][lowest][highest];
        
        long cnt=0;
        int low=n1[cur]-'0';
        int high=n2[cur]-'0';
        
        if(lowest && highest) {low=n1[cur]-'0'; high=n2[cur]-'0';}
        else if(lowest && !highest) {low=n1[cur]-'0'; high=9;} //125 555
        else if(!lowest && highest) {low=0; high=n2[cur]-'0';}
        else {low=0; high=9;}
        
        bool nextLowest=false;
        bool nextHighest=false;
        for(int i=low; i<=high; ++i)
        {
            //cout<<cur<<" : "<<i<<endl;
            if(lowest && i == n1[cur]-'0') nextLowest=true;
            else nextLowest=false;
            
            if(highest && i == n2[cur]-'0') nextHighest=true;
            else nextHighest=false;
            
            cnt = (cnt + solve(cur+1, sum+i, nextLowest, nextHighest, min_sum, max_sum)) % modulo;
        }
        
        dp[cur][sum][lowest][highest]=cnt;
        return cnt;
    }
};

//2022-05-25
//time  : O(n+m), m is the maximum count of tasks
//space : O(m)
class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        unordered_map<int,int> record;
        int maxCnt=1;
        for(auto& i:tasks)
        {
            ++record[i];
            maxCnt=max(maxCnt,record[i]);
        }
        
        if(maxCnt==1) return -1;
        if(maxCnt<=3)
        {
            for(auto& i:record) if(i.second==1) return -1;
            return record.size();
        }
        
        int dp[maxCnt+1];
        dp[1]=INT_MAX-1;
        dp[2]=1;
        dp[3]=1;
        for(int i=4; i<=maxCnt; ++i)
        {
            dp[i]=1+min(dp[i-2],dp[i-3]);
        }
        
        int sum=0;
        for(auto& i:record)
        {
            int cnt=i.second;
            if(dp[cnt]>=INT_MAX-1) return -1;
            sum+=dp[cnt];
        }
        
        return sum;
    }
};

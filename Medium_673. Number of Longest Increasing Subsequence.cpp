//2024-02-09
//time  : O(n*n)
//sapce : O(n)
struct item
{
    int len=0;
    int cnt=0;
    
    item() = default;
    item(int _len, int _cnt) : len(_len), cnt(_cnt) { }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<item> dp(n);
        dp[0] = item(1, 1);
        
        int maxLen = 1;
        for(int i=1; i<n; ++i)
        {        
            int curLen = 0;
            int curCnt = 1;
            for(int k=0; k<i; ++k)
            {
                if(nums[k] < nums[i]) 
                {
                    if(curLen < dp[k].len)
                    {
                        curLen = dp[k].len;
                        curCnt = dp[k].cnt;
                    }
                    else if(curLen == dp[k].len)
                    {
                        curCnt += dp[k].cnt;
                    }
                }            
            }
            
            dp[i] = item(curLen+1, curCnt);
            maxLen = max(maxLen, dp[i].len);
        }
        
        int res=0;
        for(int i=0; i<n; ++i)
        {
            //cout<<dp[i].len<<" "<<dp[i].cnt<<" | "<<endl;
            if(dp[i].len == maxLen) res += dp[i].cnt;
        }
        
        return res;
    }
};

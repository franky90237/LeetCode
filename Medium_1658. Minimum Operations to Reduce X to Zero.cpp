//2022-12-10
//time  : O(n)
//space : O(n)
/*
Initially, I think this is a dp problem, like dp[i][j][sum], but it is too large for both time ans space.
Alternatively, I change my mind to left part array and right part array.
And I realize it's like prefixSum or postfixSum
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        
        unordered_map<int, int> prefixSum;
        prefixSum[0]=0;
        int sum=0;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            if(!prefixSum.count(sum)) prefixSum[sum]=i+1;            
        }
        
        int ans=n+1;        
        if(prefixSum.count(x)) 
        {
            ans=prefixSum[x];
            if(ans == 1) return ans;
        }
        
        sum=0;
        for(int i=n-1; i>=0; --i)
        {
            sum += nums[i];
            int target=x-sum;
            if(prefixSum.count(target))
            {
                ans=min(ans, n-i+prefixSum[target]);
            }
        }
        
        return (ans == n+1) ? -1 : ans;
    }
};

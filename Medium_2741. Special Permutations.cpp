//2023-06-19
//time  : O(n*n*n*2^n)
//space : O(n*2^n)
class Solution 
{
private:
    int maximum;
    int modulo=1e9+7;
    vector<vector<long>> dp;
    
public:
    int specialPerm(vector<int>& nums)
    {
        int n=nums.size();
        maximum=pow(2, n)-1;
        dp.resize(n, vector<long>(maximum+1, -1));
        
        long ans=0;
        for(int i=0; i<n; ++i)
        {
            ans = (ans + solve(nums, i, 1<<i))%modulo;
            //cout<<ans<<endl;
            //cout<<endl;
        }
        
        return ans;
    }
    
    long solve(vector<int>& nums, int cur, int state)
    {
        int n=nums.size();
        if(state >= maximum) return 1;
        if(dp[cur][state] != -1) return dp[cur][state];
        
        int backup=state;
        //state |= 1<<cur;
        //cout<<cur<<" "<<state<<endl;
        long cnt=0;
        for(int i=0; i<n; ++i)
        {
            if(i == cur || used(state, i) || !valid(nums, cur, i)) continue;
            cnt = (cnt + solve(nums, i, state | (1<<i)))%modulo;
        }
        
        state=backup;
        
        dp[cur][state]=cnt;
        return cnt;
    }
    
    bool used(int state, int bit)
    {
        return (state & 1<<bit) > 0;
    }
    
    bool valid(vector<int>& nums, int a, int b)
    {
        return (nums[a] % nums[b] == 0) || (nums[b] % nums[a] == 0);
    }
};

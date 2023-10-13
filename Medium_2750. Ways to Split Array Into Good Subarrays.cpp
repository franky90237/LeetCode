//2023-10-12
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> idx;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] == 1) idx.push_back(i);
        }
        
        n=idx.size();
        if(n == 0) return 0;
        
        int modulo=1e9+7;
        long long ans=1;
        for(int i=1; i<n; ++i)
        {
            ans = ans*(idx[i]-idx[i-1])%modulo;
        }
        
        return ans;
    }
};

//2023-10-13
//top-down dp
//time  : O(n*n)
//space : O(n)
class Solution 
{
private:
    int modulo=1e9+7;
    int lastOne=-1;
    vector<int> rightOne;
    vector<int> suffixOne;
    vector<int> dp;
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        /*

        [0,1,0,0,1,0,0,1,0,0]

        [0,1]   [0,0,1,0,0,1,0,0]
        [0,1]   [0,0,1]   [0,0,1,0,0]
                [0,0,1,0] [0,1,0,0]

        [0,1,0] [0,1,0,0,1,0,0]

        */
        
        int n=nums.size();
        
        rightOne.resize(n);
        rightOne[n-1] = nums[n-1] == 1 ? n-1 : n;
        
        suffixOne.resize(n, 0);
        suffixOne[n-1] = nums[n-1] == 1;
        
        for(int i=n-2; i>=0; --i)
        {
            suffixOne[i] = suffixOne[i+1];
            if(nums[i] == 1) ++suffixOne[i];
            
            if(nums[i] == 1) rightOne[i]=i;
            else rightOne[i]=rightOne[i+1];                        
        }               
        
        //for(auto i: rightOne) cout<<i<<" "; cout<<endl;
        //for(auto i: suffixOne) cout<<i<<" "; cout<<endl;
        
        dp.resize(n, -1);
        return solve(nums, 0);
    }
    
    int solve(vector<int>& nums, int cur)
    {        
        int n=nums.size();    
        if(suffixOne[cur] <= 1) return suffixOne[cur];        
        if(dp[cur] != -1) return dp[cur];
        
        int nextOne=rightOne[cur];                
        int res=0;
        for(int i=nextOne+1; i<n; ++i)
        {            
            res = (res + solve(nums, i))%modulo;
            if(nums[i] == 1) break;
        }
        
        //cout<<cur<<" "<<res<<endl;
        dp[cur]=res;
        return res;
    }
};

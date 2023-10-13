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

//2023-10-13
//bottom-up dp
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    int modulo=1e9+7;    
    vector<int> rightOne;    
    vector<int> dp;
    vector<long long> suffixSum;
    
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
        rightOne[n-1] = (nums[n-1] == 1) ? n-1 : n;
        
        for(int i=n-2; i>=0; --i)
        {
            if(nums[i] == 1) rightOne[i]=i;
            else rightOne[i]=rightOne[i+1];                        
        }                
        
        suffixSum.resize(n+1);
        suffixSum[n]=0;
        suffixSum[n-1] = (nums[n-1] == 1) ? 1 : 0;
        
        dp.resize(n);
        dp[n-1] = (nums[n-1] == 1) ? 1 : 0;
        
        int cur=n-2;
        for(; cur>=0; --cur)
        {            
            dp[cur]=dp[cur+1];
            if(nums[cur] == 1) 
            {
                if(dp[cur] == 1) break;
                ++dp[cur];
            }
            
            suffixSum[cur] = dp[cur] + suffixSum[cur+1];
        }
        
        //if(cur == -1) return dp[0];
                
        for(; cur>=0; --cur)
        {
            int firstOne = rightOne[cur];
            int secondOne = firstOne == n ? n : rightOne[firstOne+1];
            
            long long res=0;            
            res = (res + suffixSum[firstOne+1]-suffixSum[secondOne+1])%modulo;
                        
            dp[cur]=res;
            suffixSum[cur] = res+suffixSum[cur+1];
        }
        
        //for(auto i: rightOne) cout<<i<<" "; cout<<endl;
        //for(auto i: dp) cout<<i<<" "; cout<<endl;
        //for(auto i: suffixSum) cout<<i<<" "; cout<<endl;
        
        return dp[0];
    }
};

//2023-10-13
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        int modulo=1e9+7;
        int n=nums.size();
        
        vector<int> firstOne(n+1, n);
        vector<int> secondOne(n+1, n);
        for(int i=n-1; i>=0; --i)
        {
            if(nums[i] == 1)
            {
                firstOne[i]=i;
                secondOne[i]=firstOne[i+1];
            }
            else
            {
                firstOne[i]=firstOne[i+1];
                secondOne[i]=secondOne[i+1];
            }
        }
        
        vector<int> ans(n, 0);
        vector<long long> suffixSum(n+2, 0);
        
        int cur=n-1;
        while(cur>=0 && nums[cur] != 1)
        {            
            --cur;           
        }
        
        for(; cur>=0; --cur)
        {
            int nextOne=firstOne[cur];
            int nextNextOne=secondOne[cur];
            //cout<<cur<<" | "<<nextOne<<" "<<nextNextOne<<endl;
            if(nextNextOne == n)
            {
                ans[cur]=1;
                suffixSum[cur] = ans[cur] + suffixSum[cur+1];
                continue;
            }
            
            ans[cur] = (suffixSum[nextOne+1]-suffixSum[nextNextOne+1]+modulo) % modulo;
            suffixSum[cur] = ans[cur] + suffixSum[cur+1];
        }
        
        //for(auto i: suffixSum) cout<<i<<" "; cout<<endl;
        //for(auto i: ans) cout<<i<<" "; cout<<endl;
        
        return ans[0];
    }
};

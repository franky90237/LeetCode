//2022-04-28
//TLE
//dfs
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        return dfs(nums,0,-1);
    }
    
    int dfs(vector<int>& nums, int now, int pre)
    {
        int n=nums.size();
        if(now==n) return 0;
        
        int max_len=0;
        for(int i=now; i<n; ++i)
        {
            if(pre==-1 || nums[i]>nums[pre])
            {
                //cout<<i<<" "<<pre<<endl;
                int len=1+dfs(nums,i+1,i);
                max_len=max(max_len,len);
                
            }
        }
        
        //cout<<now<<"-"<<nums[now]<<" "<<"*"<<pre<<" "<<max_len<<endl;
        return max_len;
    }
};

//2022-04-28
//dp with dfs
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return dfs(dp,nums,0,-1);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& nums, int now, int pre)
    {
        int n=nums.size();
        if(now==n) return 0;
        
        if(dp[now][pre+1]!=-1) return dp[now][pre+1];
        
        int max_len=0;
        for(int i=now; i<n; ++i)
        {
            if(pre==-1 || nums[i]>nums[pre])
            {
                //cout<<i<<" "<<pre<<endl;
                int len=1+dfs(dp,nums,i+1,i);
                max_len=max(max_len,len);
                
            }
        }
        
        //cout<<now<<"-"<<nums[now]<<" "<<"*"<<pre<<" "<<max_len<<endl;
        dp[now][pre+1]=max_len;
        return max_len;
    }
};

//2022-05-12
//dp iterative
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=1;
        
        int LIS=1;
        for(int last=1; last<n; ++last)
        {
            for(int i=0; i<last; ++i)
            {
                if(nums[last]>nums[i])
                {
                    dp[last]=max(dp[last],1+dp[i]);
                }
                
                LIS=max(LIS,dp[last]);
            }
        }
        
        //for(int i=0; i<n; ++i) cout<<dp[i]<<" ";
        
        return LIS;
    }
};

//2022-05-12
//binary search
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> lis;
        
        lis.push_back(nums[0]);
        for(int i=1; i<n; ++i)
        {
            if(nums[i]>lis.back())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int idx=binary_search(lis,nums[i]);
                lis[idx]=nums[i];
            }
        }
        
        //for(int i=0; i<lis.size(); ++i) cout<<lis[i]<<" ";
        
        return lis.size();
    }
    
    int binary_search(vector<int>& lis, int target)
    {
        int left=0;
        int right=lis.size()-1;
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            
            if(target>lis[mid]) left=mid+1;
            else right=mid;
        }
        
        return left;
    }
};

//2022-08-11
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int dp[nums.size()];
        for(auto& i:dp) i=-1;
        
        return dfs(nums,-1,0,dp);
    }
    
    int dfs(vector<int>& nums, int pre, int cur, int dp[])
    {
        int n=nums.size();
        if(cur>=n) return 0;
        if(dp[pre+1]!=-1) return dp[pre+1];
        
        //cout<<pre<<" "<<cur<<endl;
        int pick=0;
        if(pre==-1 || nums[pre]<nums[cur]) pick = 1 + dfs(nums,cur,cur+1,dp);
        int not_pick = dfs(nums,pre,cur+1,dp);
        
        dp[pre+1]=max(pick,not_pick);
        return dp[pre+1];
    }
};

//2022-08-11
//dp iterative
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        
        int dp[n];
        for(auto& i:dp) i=1;        
        
        int ans=0;
        for(int i=0; i<nums.size(); ++i)
        {
            for(int pre=0; pre<i; ++pre)
            {
                if(nums[pre]<nums[i]) dp[i]=max(dp[i],dp[pre]+1);
            }
            
            ans=max(ans,dp[i]);
        }        
        
        return ans;
    } 
};

//2022-08-14
//binary_search
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        /*
        [3,5,6,2,5,4,19,5,6,7,12]
                 ^
        3,5,6
        2,5,6
        */
        
        int n=nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        
        for(int i=1; i<n; ++i)
        {
            int num=nums[i];
            
            if(num==lis.back()) continue;
            if(num>lis.back()) lis.push_back(num);
            
            int idx=binary_search(lis,num);
            lis[idx]=num;
        }
        
        return lis.size();
    }
    
    int binary_search(vector<int>& lis, int key)
    {
        /*
        [5,6], 1
        (0,0,1) => 5>1
        (0,0,0)
        
        [1,3,6], 2
        (0,1,2) => 3>2
        (0,0,1) => 1<2
        (1,1,1)
        
        [2,3,6], 1
        (0,1,2) => 3>1
        (0,0,1) => 2>1
        (0,0,0)
        */
        
        int low=0;
        int high=lis.size()-1;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            if(lis[mid]>=key) high=mid;
            else low=mid+1;
        }
        
        return low;
    }
};

//2023-11-14
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n, 1);
        int ans=1;
        for(int i=1; i<n; ++i)
        {
            for(int k=0; k<i; ++k)
            {
                if(nums[k] < nums[i])
                {
                    dp[i]=max(dp[i], 1+dp[k]);
                }
            }
            
            ans=max(ans, dp[i]);
        }
        
        return ans;
    }
};

//2024-02-08
//time  : O(nlog(n))
//space : O(n)
class SegmentTree
{
private:
    vector<int> nodes;
    int size;
    
public:
    SegmentTree() = default;
    
    SegmentTree(int n)
    {
        size=n;
        nodes.resize(5*n, 0);
    }
    
    int query(int left, int right)
    {
        if(left > right) return 0;
        return query(left, right, 0, size-1, 0);
    }
    
    int query(int tL, int tR, int sL, int sR, int cur)
    {
        /*
            tL tR sL sR
            sL sR tL tR
        */
        //cout<<tL<<" "<<tR<<" | "<<sL<<" "<<sR<<" | "<<cur<<endl;
        if(tL > sR || tR < sL) return INT_MIN;                
        if(tL <= sL && sR <= tR) return nodes[cur];
        
        int mid=(sL+sR)/2;
        int left=query(tL, tR, sL, mid, 2*cur+1);
        int right=query(tL, tR, mid+1, sR, 2*cur+2);
        return max(left, right);
    }
    
    void update(int target, int val)
    {
        update(target, val, 0, size-1, 0);
    }
    
    void update(int target, int val, int sL, int sR, int cur)
    {
        //cout<<target<< | "<<sL<<" "<<sR<<" | "<<cur<<endl;
        if(sL == sR) 
        {            
            nodes[cur] = val;
            return;
        }    
        
        int mid = (sL+sR)/2;
        if(target <= mid) update(target, val, sL, mid, 2*cur+1);
        else update(target, val, mid+1, sR, 2*cur+2);        
        nodes[cur] = max(nodes[2*cur+1], nodes[2*cur+2]);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<int> copyNums = nums;        
        sort(copyNums.begin(), copyNums.end());
        
        unordered_multimap<int, int> table;
        for(int i=0; i<n; ++i) table.insert({copyNums[i], i});
        
        SegmentTree st(n);        
        
        int res=1;
        for(int i=0; i<n; ++i)
        {
            auto it = table.find(nums[i]);
            int idx=it->second;
            table.erase(it);
            
            int len=st.query(0, idx-1) + 1;
            st.update(idx, len);            
            
            //cout<<nums[i]<<" | "<<len<<" "<<idx<<"\n\n";
            res = max(res, len);
        }
        
        return res;
    }
};

/*
2021/12/02
dfs (without memorization)
bfs (Time Limit Exceeded)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        //bfs will be Time Limit Exceeded.
        //return bfs_findTargetSumWays(nums,target);
        
        //return dfs_findTargetSumWays(nums,target,0,0);
    }
    
    int bfs_findTargetSumWays(vector<int>& nums, int target)
    {
        int expressions=0;
        int step=1;
        queue<int> q;
        
        q.push(nums[0]);
        while(step<nums.size())
        {
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                int sum=q.front();
                q.pop();
                
                q.push(sum+nums[step]);
                q.push(sum-nums[step]);
            }
            
            ++step;
        }
        //print_queue(q);
        while(!q.empty())
        {
            int sum=q.front();
            q.pop();
            
            if(sum==target) ++expressions;
            if(sum-2*nums[0]==target) ++expressions;
        }
        
        return expressions;        
    }
    
    int dfs_findTargetSumWays(vector<int>& nums, int target, int sum, int step)
    {
        if(step==nums.size())
        {
            if(sum==target) return 1;
            return 0;
        }
                
        return dfs_findTargetSumWays(nums,target,sum+nums[step],step+1)+\
            dfs_findTargetSumWays(nums,target,sum-nums[step],step+1);
        
    }
    
    void print_queue(queue<int> q)
    {
        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
};

/*
2021/12/03
dfs with memorization
*/
class Solution {
private:
    int **visited;    
    int nums_sum;
    
public:        
    int findTargetSumWays(vector<int>& nums, int target) 
    {        
        nums_sum=0;
        for(int i=0;i<nums.size();++i) nums_sum+=nums[i];
            
        int row_size=nums.size()+1;
        int col_size=2*nums_sum+1;
        
        visited=new int*[row_size];
        for(int i=0;i<row_size;++i)
        {
            visited[i]=new int[col_size];
            memset(visited[i],0,sizeof(int)*col_size);
        }
                
        return dfs_memorization(nums,target,0,0);
    }   
    
    int dfs_memorization(vector<int>& nums, int target, int sum, int step)
    {
        if(step==nums.size())
        {
            if(sum==target) return 1;
            return 0;
        }
        
        if(visited[step][sum+nums_sum])
        {
            //cout<<step<<" "<<sum+nums_sum<<endl;
            return visited[step][sum+nums_sum];
        }
               
        visited[step][sum+nums_sum]=\
            dfs_memorization(nums,target,sum+nums[step],step+1)+dfs_memorization(nums,target,sum-nums[step],step+1);
        return visited[step][sum+nums_sum];
    }    
};

/*
2021/12/05
bottom up dp
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int size=nums.size()+1;
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(target>sum || target<-sum) return 0;
        
        int dp[size][2*sum+1];
        memset(dp,0,sizeof(int)*size*(2*sum+1));        
        
        dp[0][0+sum]=1;
        for(int i=1;i<size;++i)
        {
            for(int j=-sum;j<=sum;++j)
            {
                if(j-nums[i-1]>=-sum) dp[i][j+sum]+=dp[i-1][j+sum-nums[i-1]];
                if(j+nums[i-1]<=sum) dp[i][j+sum]+=dp[i-1][j+sum+nums[i-1]];
            }
        }
        
        //print(size,2*sum+1,(int *)dp);
        return dp[size-1][target+sum];
    }
    
    void print(int r, int c, int *dp)
    {
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                cout<<*((dp+i*c)+j)<<"  ";
            }
            cout<<endl;
        }
    }
};

//2023-11-03
//time  : O(n*sum)
//space : O(n*sum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(target)) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(2*sum+1, 0));
        dp[0][0+sum]=1;
        
        for(int i=0; i<n; ++i)
        {
            //cout<<i<<endl;
            for(int s=-sum; s<=sum; ++s)
            {
                //cout<<s<<" ";
                if(abs(s-nums[i]) <= sum) dp[i+1][s+sum]+=dp[i][s-nums[i]+sum];
                if(abs(s+nums[i]) <= sum) dp[i+1][s+sum]+=dp[i][s+nums[i]+sum];
            }
            //cout<<endl;
        }
        
        return dp[n][target+sum];
    }
};

//2023-11-03
//time  : O(n*sum)
//space : O(sum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(target)) return 0;
        
        vector<vector<int>> dp(2, vector<int>(2*sum+1, 0));
        dp[0%2][0+sum]=1;
        
        for(int i=0; i<n; ++i)
        {
            //cout<<i<<endl;
            for(int s=-sum; s<=sum; ++s)
            {                
                dp[(i+1)%2][s+sum]=0;
                if(abs(s-nums[i]) <= sum) dp[(i+1)%2][s+sum]+=dp[i%2][s-nums[i]+sum];
                if(abs(s+nums[i]) <= sum) dp[(i+1)%2][s+sum]+=dp[i%2][s+nums[i]+sum];
            }
            
            /*
            for(int k=0; k<2; ++k) 
            {
                for(int s=0; s<=2*sum; ++s) cout<<dp[k][s]<<" ";
                cout<<endl;
            }
            */
            
            //cout<<endl;
        }
        
        return dp[(n)%2][target+sum];
    }
};

//2023-11-03
//time  : O(n*sum)
//space : O(n*sum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        /*
        
        sum(pos) - sum(neg) = target
        sum(pos) = target + sum(neg)
        2*sum(pos) = target + sum(neg) + sum(pos)
        2*sum(pos) = target + sum(nums)
        sum(pos) = (target + sum(nums))/2
        
        */
        int original=target;
        int sum=accumulate(nums.begin(), nums.end(), 0);
        target += sum;
        if(target % 2 == 1 || sum < abs(original)) return 0;
        target /= 2;
        
        /*
        
        subset sum equals to target        
        dp[i][s] = dp[i-1][s] + dp[i-1][s-nums[i]]
        
        */
        
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0]=1;
        
        for(int i=0; i<n; ++i)
        {
            for(int s=0; s<=sum; ++s)
            {                
                dp[i+1][s] += dp[i][s];
                if(s-nums[i] >= 0) dp[i+1][s] += + dp[i][s-nums[i]];
                
                //cout<<dp[i][s]<<" ";
            }            
            //cout<<endl;
        }                
        
        return dp[n][target];
    }
};

//2024-02-14
//time  : O(n * target)
//space : O(n * (target+sum(nums)))
class Solution 
{
private:
    vector<unordered_map<int, int>> dp;
    
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n=nums.size();
        dp.resize(n);
        return f(nums, target, 0);
    }
    
    int f(vector<int>& nums, int target, int i)
    {
        //cout<<i<<" "<<target<<endl;
        int n=nums.size();
        if(i == n) return (target == 0);
        if(dp[i].find(target) != dp[i].end()) return dp[i][target];
        
        return dp[i][target] = f(nums, target-nums[i], i+1) + f(nums, target+nums[i], i+1);
    }
};

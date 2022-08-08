//2022-08-08
//time  : O(2^n)
//space : O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int all_sum=accumulate(nums.begin(),nums.end(),0);
        if(all_sum%2==1) return false;
        
        return solve(nums,0,0,all_sum);
    }
    
    bool solve(vector<int>& nums, int cur, int cur_sum, int all_sum)
    {
        int n=nums.size();
        
        if(cur_sum*2==all_sum) 
        {
            //cout<<cur<<" "<<cur_sum<<endl;
            return true;
        }
        if(cur>=n || cur_sum*2>all_sum) return false;
        /*if(cur_sum*2==all_sum) 
        {
            cout<<cur<<" "<<cur_sum<<endl;
            return true;
        }*/      
        
        for(int i=cur; i<n; ++i)
        {
            bool is_find=solve(nums,i+1,cur_sum+nums[i],all_sum);
            if(is_find) 
            {
                //cout<<cur<<" "<<cur_sum<<endl;
                return true;
            }
        }
        
        return false;
    }
};

//2022-08-08
//dp recursive
//time  : O(n*m), m is the sum of the nums
//space : O(n*m), m is the sum of the nums
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    bool canPartition(vector<int>& nums)
    {
        int all_sum=accumulate(nums.begin(),nums.end(),0);
        if(all_sum%2==1) return false;
        
        dp.resize(nums.size(),vector<int>(all_sum+1,-1));
        return solve(nums,0,0,all_sum);
    }
    
    bool solve(vector<int>& nums, int cur, int cur_sum, int all_sum)
    {
        int n=nums.size();
        
        if(cur_sum*2==all_sum) 
        {
            //cout<<cur<<" "<<cur_sum<<endl;
            return true;
        }
        if(cur>=n || cur_sum*2>all_sum) return false;
        if(dp[cur][cur_sum]!=-1) return dp[cur][cur_sum];
        
        bool is_find=false;
        for(int i=cur; i<n; ++i)
        {
            is_find=solve(nums,i+1,cur_sum+nums[i],all_sum);
            if(is_find) 
            {
                //cout<<cur<<" "<<cur_sum<<endl;
                break;
            }
        }
        
        dp[cur][cur_sum]=is_find;
        return dp[cur][cur_sum];
    }
};

//2022-08-08
//clear, dp recursive
//time  : O(n*m), m is the sum of the nums/2
//space : O(n*m), m is the sum of the nums/2
class Solution 
{
private:
    vector<vector<int>> dp;
    
public:
    bool canPartition(vector<int>& nums)
    {
        int all_sum=accumulate(nums.begin(),nums.end(),0);
        if(all_sum%2==1) return false;
        
        dp.resize(nums.size(),vector<int>(all_sum+1,-1));
        return solve(nums,0,all_sum/2);
    }
    
    bool solve(vector<int>& nums, int cur, int sum)
    {
        int n=nums.size();
        
        if(sum==0) return true;
        if(cur>=n || sum<0) return false;
        if(dp[cur][sum]!=-1) return dp[cur][sum];
                
        dp[cur][sum] = solve(nums,cur+1,sum-nums[cur]) || 
                       solve(nums,cur+1,sum);
        return dp[cur][sum];
    }
};

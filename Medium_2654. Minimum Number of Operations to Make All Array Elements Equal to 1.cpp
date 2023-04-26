//2023-04-24
//time  : O(3^n)
//space : O(n)
class Solution 
{    
public:
    int minOperations(vector<int>& nums)
    {
        int n=nums.size();        
            
        int cnt=0;
        bool hasOne=false;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] != 1)
            {
                ++cnt;
            }
            else
            {
                hasOne=true;
            }                
        }
        
        if(hasOne)
        {
            return cnt;
        }
        
        //dp.resize(n, -1);
        int ans=solve(nums, 0);
        return ans == INT_MAX ? -1 : ans;
    }
    
    int solve(vector<int>& nums, int cur)
    {
        int n=nums.size();
        if(cur == n-1) return INT_MAX;        
        
        int gcd=__gcd(nums[cur], nums[cur+1]);
        if(gcd == 1)
        {
            int rest=0;
            for(auto num: nums)
            {
                if(num != 1) ++rest;
            }

            return rest;
        }
        
        int notChange=solve(nums, cur+1);
        int changeFirst=INT_MAX;
        int changeSecond=INT_MAX;        
        
        if(nums[cur] != gcd)
        {
            int tmp=nums[cur];
            nums[cur]=gcd;
            int cnt=solve(nums, cur+1);
            if(cnt != INT_MAX) changeFirst=cnt+1;
            nums[cur]=tmp;
        }
                
        if(nums[cur+1] != gcd)
        {
            int tmp=nums[cur+1];
            nums[cur+1]=gcd;
            int cnt=solve(nums, cur+1);
            if(cnt != INT_MAX) changeSecond=cnt+1;
            nums[cur+1]=tmp;
        }
               
        return min(notChange, min(changeFirst, changeSecond));
    }
};

//2023-04-26
//time  : O(n*n)
//sapce : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        bool hasOne=false;
        int cnt=0;
        for(auto& num: nums)
        {
            if(num == 1)
            {
                ++cnt;
                hasOne=true;
            }            
        }
        
        if(hasOne)
        {
            return n-cnt;
        }
                
        int ans=INT_MAX;
        for(int left=0; left<n; ++left)
        {                        
            int gcd=nums[left];            
            for(int right=left+1; right<n; ++right)
            {
                gcd=__gcd(gcd, nums[right]);                
                if(gcd == 1)
                {
                    int subArrayLen=right-left+1;
                    ans=min(ans, subArrayLen-1+n-1);
                    break;
                }
            }
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};

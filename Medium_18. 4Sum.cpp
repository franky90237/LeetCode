//2022-10-02
//time  : O(n*n*n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n=nums.size();
        if(n < 4) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int first=0;
        while(first <= n-4)
        {
            int second=first+1;            
            while(second <= n-3)
            {
                two_sum(nums, ans, first, second, target-nums[first]);
                
                ++second;
                while(second <= n-3 && nums[second] == nums[second-1]) ++second;
            }
            
            ++first;
            while(first <= n-4 && nums[first]==nums[first-1]) ++first;
        }
        
        return ans;
    }
    
    void two_sum(vector<int>& nums, vector<vector<int>>& ans, int first, int second, int target)
    {
        int l=second+1;
        int r=nums.size()-1;
        long diff=(long)target-nums[second];

        while(l < r)
        {
            int sum=nums[l]+nums[r];
            if(sum == diff)
            {            
                ans.push_back({nums[first], nums[second], nums[l], nums[r]});

                --r;
                while(l < r && nums[r] == nums[r+1]) --r;

                ++l;
                while(l < r && nums[l] == nums[l-1]) ++l;

            }
            else if(sum > diff)
            {
                --r;                    
            }
            else
            {
                ++l;                    
            }    
        }        
    }
};

//2023-07-26
//time  : O(n*n*n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        int c=0;
        int d=n-1;
        for(int c=0; c<n-1; ++c)
        {
            if(c > 0 && nums[c] == nums[c-1]) continue;
            
            for(int d=c+1; d<n; ++d)
            {
                if(d > c+1 && nums[d] == nums[d-1]) continue;
                twoSum(nums, (long long)target-nums[c]-nums[d], c, d, ans);
            }
        }
        
        return ans;
    }
    
    void twoSum(vector<int>& nums, long long target, int c, int d, vector<vector<int>>& ans)
    {
        int n=nums.size();
        int a=d+1;
        int b=n-1;
        while(a < b)
        {
            long long sum=nums[a]+nums[b];
            if(sum == target) 
            {
                ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                
                ++a;
                while(a < b && nums[a] == nums[a-1]) ++a;
                
                --b;
                while(a < b && nums[b] == nums[b+1]) --b;
            }
            else if(sum > target)
            {
                --b;
            }
            else
            {
                ++a;
            }
        }
    }
};

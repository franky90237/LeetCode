//2022-08-12
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int i=0;
        while(i<n && nums[i]<=0) ++i;
        
        if(i>=n || nums[i]!=1) return 1;
        
        ++i;
        while(i<n)
        {
            //cout<<nums[i]<<endl;
            if(nums[i]-nums[i-1]>1) return nums[i-1]+1;
            ++i;
        }
        
        return nums.back()+1;
    }
};

//2022-08-12
//time  : O(n)
//space : O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {        
        int n=nums.size();
        unordered_set<int> table;
        
        int small=-1;
        for(auto& num:nums)
        {
            if(num>0)
            {
                small=num;
                table.insert(num);
            }
        }
        
        if(small==-1) return 1;
        
        for(int i=1; i<=INT_MAX; ++i)
        {
            if(!table.count(i)) return i;
        }
        
        return INT_MAX+1;
    }
};

//2022-08-12
//time  : O(n)
//space : O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {        
        int n=nums.size();
        
        for(int i=0; i<n;)
        {            
            if(nums[i]>0 && nums[i]<=n && nums[i]!=i+1 && nums[i]!=nums[nums[i]-1])
            {
                int correct_idx=nums[i]-1;
                swap(nums[i],nums[correct_idx]);
            }
            else
            {
                ++i;
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            if(nums[i]!=i+1) return i+1;
        }
        
        return n+1;
    }
};

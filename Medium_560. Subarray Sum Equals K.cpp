//2022-09-08
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n=nums.size();
        
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            int sum=0;
            for(int j=i; j<n; ++j)
            {
                sum+=nums[j];
                if(sum==k) ++ans;
            }
        }
        
        return ans;
    }
};

//2022-09-08
//time  : O(n)
//space : O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        /*
        1,1,1
        1,2,3

        4,5,-9,8,-8,2

        1,1,-1,1,1 (1,1) (1,-1,1) (1,-1,1,1) (1,1)

        1, 1,-1, 1, 1
        1, 2, 1, 2, 3

             1,1,1
        s: 0 1 2 3
        a: 0 0 1 
        h: (0,1) (1,1) (2,1)
        */        
        int n=nums.size();
        
        unordered_map<int,int> table;
        table[0]=1;
        
        int ans=0;
        int sum=0;
        for(int i=0; i<n; ++i)
        {
            sum+=nums[i];
            int target=sum-k;
            if(table.find(target)!=table.end())
            {
                ans+=table[target];
            }
            
            ++table[sum];
        }
        
        return ans;
    }
};

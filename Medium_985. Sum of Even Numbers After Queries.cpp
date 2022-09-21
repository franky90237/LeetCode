//2022-09-21
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        /*
        [1,2,3,4] [[1,0],[-3,1],[-4,0],[2,3]]

        even : 2,4
        odd  : 1,3
        sum  : 4+2 = 6

        1. [1,0] -> [2,2,3,4]

        even : 2,4,2
        odd  : 3
        sum  : 6+2 = 8
        ans  : 8,

        2. [-3,1] -> [2,-1,3,4]

        even : 2,4
        odd  : 3,-1
        sum  : 8-2=6
        ans  : 8,6

        3. [-4,0] -> [-2,-1,3,4]

        even : 4,-2
        odd  : 3,-1
        sum  : 6-2-2=2
        ans  : 8,6,2

        4. [2,3] -> [-2,-1,3,6]

        even : -2,6
        odd  : 3,-1
        sum  : 2-4+6=4
        ans  : 8,6,2,4
        */
        
        int sum=0;
        unordered_map<int, int> table;
        for(auto& num : nums)
        {
            if(num%2==0)
            {
                ++table[num];
                sum+=num;
            }
        }
        
        vector<int> ans;
        for(auto& query : queries)
        {
            int val=query[0];
            int idx=query[1];
            
            if(val == 0) 
            {
                ans.push_back(sum);
                continue;
            }
            
            if(nums[idx]%2==0)
            {
                --table[nums[idx]];
                sum-=nums[idx];
            }
            
            int new_val=nums[idx]+val;
            nums[idx]=new_val;            
            if(new_val%2==0)
            {
                ++table[new_val];
                sum+=new_val;
            }
            
            ans.push_back(sum);
        }        
        
        return ans;
    }
};

//2022-09-21
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        /*
        [1,2,3,4] [[1,0],[-3,1],[-4,0],[2,3]]       
        sum : 4+2=6

        1. [1,0]
        [1,2,3,4] -> [2,2,3,4]  
        sum : 6+2=8
        ans : 8

        2. [-3,1] 
        [2,2,3,4] -> [2,-1,3,4]
        sum : 8-6=6
        ans : 8,6

        3. [-4,0] 
        [2,-1,3,4] -> [-2,-1,3,4]
        sum : 6-2-2=2
        ans : 8,6,2

        4. [2,3] 
        [-2,-1,3,4] -> [-2,-1,3,6]     
        sum : 2-4+6=4
        ans : 8,6,2,4
        */
        
        int sum=0;        
        for(auto& num : nums)
        {
            if(num%2==0) sum+=num;            
        }
        
        vector<int> ans;
        for(auto& query : queries)
        {
            int val=query[0];
            int idx=query[1];
            
            if(val == 0) 
            {
                ans.push_back(sum);
                continue;
            }
            
            if(nums[idx]%2==0) sum-=nums[idx];
            nums[idx]=nums[idx]+val;
            if(nums[idx]%2==0) sum+=nums[idx];
            
            ans.push_back(sum);
        }        
        
        return ans;
    }
};

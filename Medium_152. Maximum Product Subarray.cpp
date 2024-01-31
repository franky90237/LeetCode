//2022-05-24
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n=nums.size();
        
        int leftProduct=1;
        int rightProduct=1;
        int res=nums[0];
        
        for(int i=0; i<n; ++i)
        {
            if(leftProduct==0) leftProduct=1;
            if(rightProduct==0) rightProduct=1;
            
            leftProduct*=nums[i];
            rightProduct*=nums[n-1-i];
            //printf("%d %d \n",leftProduct,rightProduct);
            
            res=max(res,max(leftProduct,rightProduct));
        }
        
        return res;
    }
};

//2023-10-16
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size();        
               
        set<int> prefix;
        int ans=nums[0];
        int cur=1;
        for(int i=0; i<n; ++i)
        {
            cur *= nums[i];
            if(cur < 0 && !prefix.empty())
            {                
                ans = max(ans, cur / *(prefix.rbegin()));
            }
            else
            {
                ans = max(ans, cur);
            }
            
            if(cur < 0)
            {
                prefix.insert(cur);
            } 
            else if(cur == 0)
            {
                cur=1;
                prefix.clear();
            }
        }
        
        return ans;
    }
};

//2023-10-16
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size();        
               
        int maxNegative=INT_MIN;
        int ans=nums[0];
        int cur=1;
        for(int i=0; i<n; ++i)
        {
            cur *= nums[i];
            if(cur < 0 && maxNegative != INT_MIN)
            {                
                ans = max(ans, cur / maxNegative);
            }
            else
            {
                ans = max(ans, cur);
            }
            
            if(cur < 0)
            {
                maxNegative=max(maxNegative, cur);
            } 
            else if(cur == 0)
            {
                cur=1;
                maxNegative=INT_MIN;
            }
        }
        
        return ans;
    }
};

//2024-01-31
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        return max(maxProductFromLeft(nums), maxProductFromRight(nums));
    }
    
    int maxProductFromLeft(vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int product = 1;
        int cur = 1;
        for(int i = 0; i < n; ++i)
        {            
            product *= nums[i];
            cur *= nums[i];
            ans=max(ans, max(product, cur));
            
            if(nums[i] < 0)
            {
                cur = 1;
            }
            else if(nums[i] == 0)
            {
                product = 1;
                cur = 1;
            }
        }
        
        return ans;
    }
    
    int maxProductFromRight(vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int product = 1;
        int cur = 1;
        for(int i = n-1; i >= 0; --i)
        {            
            product *= nums[i];
            cur *= nums[i];
            ans=max(ans, max(product, cur));
            
            if(nums[i] < 0)
            {
                cur = 1;
            }
            else if(nums[i] == 0)
            {
                product = 1;
                cur = 1;
            }
        }
        
        return ans;
    }    
};

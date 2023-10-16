//2022-05-23
//no division operator
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<int> res(n);
        res[0]=1;        
        for(int i=1; i<n; ++i)
        {
            res[i]=res[i-1]*nums[i-1];
        }
        
        int tmp=1;
        for(int i=n-2; i>=0; --i)
        {
            res[i]=res[i]*nums[i+1]*tmp;
            tmp=nums[i+1]*tmp;
        }
        
        return res;
    }
};

//2022-05-23
//clear one-pass no division operator
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<int> res(n,1);
        int pre=1;
        int post=1;
        for(int i=0; i<n; ++i)
        {
            //printf("%d, %d - %d, %d \n",pre,post, res[i], res[n-1-i]);
            res[i]=res[i]*pre;
            pre=pre*nums[i];
            
            res[n-1-i]=res[n-1-i]*post;
            post=post*nums[n-1-i];
        }
        
        return res;
    }
};

//2022-09-02
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        /*
        1,2,3,4
        
        1,2,6,24
        
        a0 = 1
        a1 = n1*a0 = n1
        a2 = n2*a1 = n2*n1
        a3 = n3*a2 = n3*n2*n1
        
        0 :      n1 * n2 * n3
        1 : n0 *      n2 * n3
        2 : n0 * n1 *      n3
        3 : n0 * n1 * n2
        */
        
        int n=nums.size();
        
        vector<int> prefix_product(n,1);        
        for(int i=1; i<n; ++i)
        {
            prefix_product[i]=prefix_product[i-1]*nums[i-1];
        }
        
        int suffix_prduct=nums[n-1];
        for(int i=n-2; i>=0; --i)
        {
            prefix_product[i] *= suffix_prduct;
            suffix_prduct *= nums[i];
        }
        
        return prefix_product;
    }
};

//2023-10-16
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n, 1);
        int pre=1;
        int suf=1;
        for(int i=0; i<n; ++i)
        {
            ans[i] = pre * ans[i];
            ans[n-i-1] = suf * ans[n-i-1];
            pre = pre * nums[i];
            suf = suf * nums[n-i-1];
        }
        
        return ans;
    }
};

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

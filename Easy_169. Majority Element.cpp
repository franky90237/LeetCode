//2022-05-18
//offset each other
//reference : https://www.zhihu.com/question/49973163/answer/235921864
//time  : O(n)
//space : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int res=nums[0];
        int cnt=1;
        
        for(int i=1; i<n; ++i)
        {
            if(res==nums[i])
            {
                ++cnt;
            }
            else
            {
                if(cnt==0)
                {
                    res=nums[i];
                    cnt=1;
                }
                else
                {
                    --cnt;
                }
            }
        }
        
        return res;
    }
};

//2022-09-01
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        /*
          1,1,1,2,2,2,2
            ^
        c 1 2 3 1 2 3 4 
        p 1     2
        
        */
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int cnt=1;
        int pre=nums[0];
        for(int i=1; i<n; ++i)
        {
            if(cnt>n/2) break;
            
            if(pre==nums[i])
            {
                ++cnt;
            }
            else
            {
                cnt=1;
                pre=nums[i];
            }
        }
        
        return pre;
    }
};

//2022-09-01
//clear
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {        
        sort(nums.begin(),nums.end());        
        int n=nums.size();        
        return nums[n/2];
    }
};

//2022-09-01
//Boyer–Moore majority vote algorithm
//time  : O(n)
//space : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {        
        int n=nums.size();
        
        int ans=nums[0];
        int cnt=1;
        
        for(int i=0; i<n; ++i)
        {
            if(ans==nums[i]) ++cnt;
            else --cnt;
            
            if(cnt==0)
            {
                ans=nums[i];
                cnt=1;
            }
        }
        
        return ans;
    }
};

//2023-07-17
//time  : O(n)
//space : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=nums[0];
        int cnt=1;
        int left=0;
        for(int i=1; i<n; ++i)
        {
            if(ans == nums[i]) ++cnt;
            
            int len=i-left+1;
            if(cnt <= len/2)
            {
                ans=nums[i];
                cnt=1;
                left=i;
            }
        }
        
        return ans;
    }
};

//2022-05-25
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();
        
        int res=0;
        for(int left=0; left<n; ++left)
        {
            for(int right=left+1; right<n; ++right)
            {
                int water=min(height[left],height[right])*(right-left);
                res=max(res,water);
            }
        }
        
        return res;
    }
};

//2022-05-25
//greedy
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();
        
        int left=0;
        int right=n-1;
        int res=0;
        
        while(left<right)
        {
            int width=right-left;
            
            if(height[left]<height[right])
            {
                res=max(res,height[left]*width);
                ++left;
            }
            else
            {
                res=max(res,height[right]*width);
                --right;
            }
        }
        
        return res;
    }
};

//2022-05-25
//TLE
//time. : O(n*n)
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

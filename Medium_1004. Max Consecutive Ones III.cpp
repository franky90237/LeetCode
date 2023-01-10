//2022-01-10
//time  : O(n)
//space : O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(k >= n) return n;
        
        int l=0;
        int r=0;
        int ans=0;
        while(r < n)
        {
            if(nums[r] == 0)
            {
                nums[r]=2;
                --k;
            }
            
            while(k < 0)
            {
                if(nums[l] == 2)
                {
                    nums[l]=0;
                    ++k;
                }
                
                ++l;
            }            
            
            ans=max(ans, r-l+1);
            
            ++r;
        }
        
        return ans;
    }
};

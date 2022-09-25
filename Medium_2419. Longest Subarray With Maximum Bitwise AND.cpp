//2022-09-25
//time  : O(n)
//space : O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {        
        int biggest=*max_element(nums.begin(), nums.end());
                  
        int ans=1;
        int len=0;
        for(auto& num : nums)
        {
            if(num==biggest)
            {
                ++len;
                ans=max(ans, len);
            }
            else
            {
                len=0;
            }
        }
                
        return ans;
    }
};

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

//2023-10-27
//time  : O(n)
//space : O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        int maxNum=nums[0];
        int maxLen=1;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] < maxNum) continue;
            
            int cur=i;
            while(cur < n && nums[cur] == nums[i])
            {                
                ++cur;
            }
            
            if(nums[i] == maxNum)
            {
                maxLen=max(maxLen, cur-i);
            }
            else
            {
                maxNum=nums[i];
                maxLen=cur-i;
            }                        
            
            i=cur-1;
        }
        
        return maxLen;
    }
};

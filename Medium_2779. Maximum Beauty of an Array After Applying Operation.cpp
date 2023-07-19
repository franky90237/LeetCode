//2023-07-19
//time  : O(nlogn)
//space : O(1)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int ans=1;
        int cnt=1;
        int left=0;
        int preEnd=nums[0]+k;
        for(int i=1; i<n; ++i)
        {
            int curBegin=nums[i]-k;
            int curEnd=nums[i]+k;

            while(left < i && curBegin > preEnd)
            {
                --cnt;
                ++left;
                preEnd=nums[left]+k;       
            }
            
            ++cnt;
            ans=max(ans, cnt);
        }
        
        return ans;
    }
};

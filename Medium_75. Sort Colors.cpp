//2022-05-03
//time  : O(n)
//space : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int cnt[3]={0};
        for(auto& num:nums) ++cnt[num];
        
        int idx=0;
        for(int i=0; i<3; ++i)
        {
            while(cnt[i]!=0) 
            {                
                nums[idx]=i;
                ++idx;
                
                --cnt[i];
            }
        }
    }
};

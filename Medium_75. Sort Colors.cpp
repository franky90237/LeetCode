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

//2022-05-04
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int zero=0;
        int i=0;
        int two=nums.size()-1;
        
        while(i<=two)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[zero]);
                ++i;
                ++zero;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[two]);
                --two;
            }
            else
            {
                ++i;
            }
        }
    }
};

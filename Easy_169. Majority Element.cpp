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

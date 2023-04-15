//2023-04-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minDeletion(vector<int>& nums)
    {
        int n=nums.size();
        
        set<int> used;
        bool extra=0;
        int ans=0;
        
        for(int i=0; i<n-1; ++i)
        {
            int shiftedIdx=i+extra;
            if(shiftedIdx % 2 == 1 || nums[i] != nums[i+1])
            {
                continue;
            }
            
            ++ans;            
            extra = ! extra;
        }
                
        if((n-ans) % 2 == 1) ++ans;
        return ans;
    }
};

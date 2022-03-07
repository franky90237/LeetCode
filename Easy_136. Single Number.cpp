//time. : O(n)
//space : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int res=0;
        
        for(auto& i:nums)
        {
            res=res^i;
        }
        
        return res;
    }
};

//2022-04-28
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=2) return false;
        
        int small=INT_MAX;
        int big=INT_MAX;
        for(auto& num:nums)
        {
            if(num<=small) small=num;
            else if(num<=big) big=num;
            else return true;
        }
        
        return false;
    }
};

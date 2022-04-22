//2022-04-22
//time  : O(n)
//space : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=(1+n)*n/2;
        
        int missing_sum=0;
        for(auto& i:nums) missing_sum+=i;
        
        return sum-missing_sum;
    }
};

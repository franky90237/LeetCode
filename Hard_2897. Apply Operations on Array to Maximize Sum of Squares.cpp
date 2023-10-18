//2023-10-18
//time  : O(32*n)
//space : O(32)
class Solution {
public:
    int maxSum(vector<int>& nums, int k) 
    {
        int m=nums.size();
        vector<int> bits(32, 0);
        for(int num: nums)
        {
            for(int i=0; i<32; ++i)
            {
                if((num&(1<<i)) != 0)
                {
                    ++bits[i];
                }
            }
        }
        
        int modulo=1e9+7;
        long long ans=0;
        while(k > 0)
        {
            long long num=0;
            for(int i=0; i<32; ++i)
            {
                if(bits[i] > 0)
                {
                    num |= 1<<i;
                    --bits[i];
                }
            }
            if(num == 0) break;
            
            long long square = (num * num) % modulo;
            ans = (ans + square) % modulo;
            
            --k;
        }
        
        return ans;
    }
};

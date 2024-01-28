//2024-01-28
//time  : O(n*30)
//space : O(1)
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int ans = 0;
        int base=0;
        for(int bit=29; bit>=0; --bit)
        {
            base |= (1<<bit);
            int res = (1<<30) - 1;
            int cnt = 0;
            
            for(int num : nums)
            {
                res &= num & base;
                if(res > 0)
                {
                    ++cnt;
                }
                else
                {
                    res = (1<<30) - 1;
                }
            }
            
            if(cnt > k)
            {
                ans |= (1<<bit);
                base &= ~(1<<bit);
            }
        }
        
        return ans;
    }    
};

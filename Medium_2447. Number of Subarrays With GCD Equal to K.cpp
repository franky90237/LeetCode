//2022-10-24
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {        
        int n=nums.size();
        int ans=0;        
        for(int i=0; i<n; ++i)
        {
            int GCD=nums[i];            
            for(int j=i; j<n && nums[j]%k==0; ++j)
            {
                GCD=gcd(GCD, nums[j]);
                if(GCD == k) ++ans;                
            }            
        }
        
        return ans;
    }    
};

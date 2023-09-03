//2023-09-03
//time  : O(n)
//space : O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {        
        int n=nums.size();
        unordered_map<int, int> preSum;
        preSum[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            sum = ((sum+nums[i])%k+k)%k;
            ans += preSum[sum];
            ++preSum[sum];
            //cout<<i<<" "<<sum<<" | "<<ans<<endl;
        }
        
        return ans;
    }
};
/*

-1%5=-1

Input: nums = [4,5,0,-2,-3,1], k = 5

i=0, (0,1) sum=(0+4)%5=4 -> ans=0
i=1, (0,1) (4,1) sum=(4+5)%5=4 -> ans=0+1=1 | [5]
i=2, (0,1) (4,2) sum=(4+0)%5=4 -> ans=1+2=3 | [5] [5,0] [0]
i=3, (0,1) (4,3) sum=(4-2)%5=2 -> ans=3 | [5] [5,0] [0]
i=4, (0,1) (4,3) (2,1) sum=(2-3)%5=4 -> ans=3+3=6 | [5] [5,0] [0] [5,0,-2,-3] [0,-2,-3] [-2, -3]
i=5, (0,1) (4,4) (2,1) sum=(4+1)%5=0 -> ans=6+1=7 | [5] [5,0] [0] [5,0,-2,-3] [0,-2,-3] [-2, -3] [4,5,0,-2,-3,1]

*/

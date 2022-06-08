//2022-06-08
//TLE
class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size()==1) return nums[0];
        
        return solve(0,true,nums);
    }
    
    int solve(int now, bool first, vector<int>& nums)
    {
        int n=nums.size();
        if(now>=n) return 0;
        
        int maxMoney=0;
        for(int i=now; i<n; ++i)
        {
            if(now==0 && i!=now) first=false;
            if(i==n-1 && first) continue;
            maxMoney=max(maxMoney,nums[i]+solve(i+2,first,nums));
            //cout<<i<<":"<<money<<endl;
        }
        
        return maxMoney;
    }
};

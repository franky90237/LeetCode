//2023-09-03
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int, int> preCnt;
        preCnt[0]=1;
        int cnt=0;
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] % 2 == 1) ++cnt;
            int target=cnt-k;
            if(preCnt.find(target) != preCnt.end()) ans += preCnt[target];
            ++preCnt[cnt];
        }
        
        return ans;
    }
};

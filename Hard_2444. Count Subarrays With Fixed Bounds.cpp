//2022-10-16
//TLE
//dp
class Solution 
{
private:    
    map<tuple<int, int, int>, long long> dp;
    
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        /*unordered_map<int, int> table;
        for(auto& num: nums)
        {
            ++table[num];
        }*/
        
        long long ans=0;
        for(int i=0; i<nums.size(); ++i)
        {
            /*if(table.find(minK) == table.end() || table.find(maxK) == table.end()) break;
            --table[nums[i]];
            if(table[nums[i]] == 0) table.erase(nums[i]);*/
            
            int cnt=solve(nums, minK, maxK, nums[i], nums[i], i);            
            ans += cnt;            
            //cout<<i<<" "<<cnt<<endl;
        }
        
        return ans;
    }
    
    long long solve(vector<int>& nums, int minK, int maxK, int minCur, int maxCur, int cur)
    {
        int n=nums.size();
        if(cur >= n) return 0;
        if(minCur < minK && maxCur > maxK) return 0;
        if(dp.find({cur, minCur, maxCur}) != dp.end()) 
        {
            //cout<<dp[{cur, minCur, maxCur}]<<endl;
            return dp[{cur, minCur, maxCur}];
        }
        
        int res=0;
        if(minCur == minK && maxCur == maxK) ++res;
        if(cur+1 < n) res += solve(nums, minK, maxK, min(minCur, nums[cur+1]), max(maxCur, nums[cur+1]), cur+1);
        
        dp[{cur, minCur, maxCur}]=res;
        return res;
    }
};

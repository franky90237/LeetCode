//2023-09-03
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        int n=nums.size();
        unordered_map<int, long long> qCnt;
        qCnt[0]=1;
        int cnt=0;
        long long ans=0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] % modulo == k) ++cnt;
            
            int q=cnt%modulo;            
            int target=(q+modulo-k)%modulo;
            ans += qCnt[target];
            ++qCnt[q];
        }
        
        return ans;
    }
};

//2023-09-13
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        unordered_map<int, int> pre;
        pre[0]=1;
        long long ans=0;
        long long cnt=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] % modulo == k) cnt=(cnt+1)%modulo;
            int target=(cnt-k+modulo) % modulo;
            ans += pre[target];
            ++pre[cnt];
        }
        
        return ans;
    }
};

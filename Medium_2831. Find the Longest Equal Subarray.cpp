//2023-08-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        unordered_map<int, vector<int>> groups;
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            groups[nums[i]].push_back(i);
        }
        
        int ans=1;
        for(auto& it: groups)
        {
            ans=max(ans, getLongest(it.second, k));
        }
        
        return ans;
    }
    
    int getLongest(vector<int>& index, int k)
    {
        int n=index.size();
        int ans=0;
        int left=0;
        int right=0;
        for(; right<n; ++right)
        {
            int len=right-left+1;            
            while(index[right]-index[left]+1-len > k)
            {
                ++left;
            }
            
            ans=max(ans, right-left+1);
        }
        
        return ans;
    }
};

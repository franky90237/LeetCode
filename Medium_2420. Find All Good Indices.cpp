//2022-09-25
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k)
    {
        int n=nums.size();
        
        vector<int> ans;                        
        for(int i=k; i<n-k; ++i)
        {
            if(k==1 || check_good(ans, nums, i, k))
            {                
                ans.push_back(i);               
            }
        }
        
        return ans;
    }
    
    bool check_good(vector<int>& ans, vector<int>& nums, int idx, int k)
    {
        int i=idx-k+1;
        if(!ans.empty()) 
        {
            int pre=ans.back();
            i=max(i, pre);
        }
        
        for(; i<idx; ++i)
        {
            if(nums[i-1] < nums[i]) return false;
        }
                
        i=idx+2;
        if(!ans.empty()) 
        {
            int pre=ans.back()+k+1;
            i=max(i, pre);
        }
        
        for(; i<=idx+k; ++i)
        {
            if(nums[i-1] > nums[i]) return false;
        }
        
        return true;
    }
};

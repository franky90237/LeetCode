//2022-05-02
//backtracking
//time  : O(2^n)
//space : O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(res,nums,tmp,0);
        
        //cout<<res.size()<<endl;
        return res;
    }
    
    void solve(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int now)
    {
        res.push_back(tmp);
        
        int n=nums.size();
        if(now>=n) return;
        
        for(int i=now; i<n; ++i)
        {
            tmp.push_back(nums[i]);
            solve(res,nums,tmp,i+1);
            tmp.pop_back();
        }
    }
};

//2022-09-03
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> tmp;
        vector<vector<int>> ans;
        dfs(0,candidates,target,tmp,ans);
        
        return ans;
    }
    
    void dfs(int cur,vector<int>& candidates, int target,vector<int>& tmp, vector<vector<int>>& ans)
    {
        int n=candidates.size();
        
        if(target==0)
        {
            ans.push_back(tmp);
            return;
        }
        else if(target<0 || cur>=n) return;
        
        for(int i=cur; i<n; ++i)
        {
            tmp.push_back(candidates[i]);
            dfs(i,candidates,target-candidates[i],tmp,ans);
            tmp.pop_back();
        }
    }
};

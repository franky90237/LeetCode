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

//2022-09-03
//two way
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
        
        //pick
        tmp.push_back(candidates[cur]);
        dfs(cur,candidates,target-candidates[cur],tmp,ans);
        tmp.pop_back();
        
        //not_pick
        dfs(cur+1,candidates,target,tmp,ans);
    }
};

//2022-09-03
//dp iterative
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        /*
        dp[i] = candidates[k] + dp[i-candidates[k]], for candidates[k]<=dp[i] 
        */
        
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> dp[target+1];
        for(auto& val:candidates) 
        {
            if(val<=target) dp[val].push_back({val});
        }
        
        /*for(int i=1; i<=target; ++i)
        {
            cout<<i<<" : ";
            for(auto& comb:dp[i])
            {                
                for(auto& val:comb) cout<<val<<" ";
                cout<<", ";
            }
            cout<<endl;
        }*/
        
        for(int i=1; i<=target; ++i)
        {
            for(int k=0; k<candidates.size() && candidates[k]<=i; ++k)
            {                
                int diff=i-candidates[k];                
                
                for(vector<int> pre_comb:dp[diff])
                {
                    if(candidates[k] < pre_comb.back()) continue;
                    
                    pre_comb.push_back(candidates[k]);
                    dp[i].push_back(pre_comb);
                }
            }
                        
            /*for(auto& comb:dp[i])
            {
                for(auto& val:comb) cout<<val<<" ";
                cout<<", ";
            }
            cout<<endl;*/
        }
        
        return dp[target];
    }    
};

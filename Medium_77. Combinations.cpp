class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        solve(res,1,n,k,k);
        
        return res;
    }
    
    void solve(vector<vector<int>>& res, int begin, int end, int cnt, int max)
    {
        if(cnt==0) return;
        
        //if(cnt==max) res.push_back({});
        
        for(int i=begin; i<=end; ++i)
        {
            if(cnt==max) res.push_back({});
            
            int seq=res.size()-1;
            res[seq].push_back(begin);
            
            solve(res,begin+1,end,cnt-1,max);
            
            res.push_back(res[seq]);
            res[seq+1].pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(1,n,k,res,tmp);
        
        return res;
    }
    
    void solve(int begin, int n, int k, vector<vector<int>>& res, vector<int>& tmp)
    {
        if(tmp.size()==k)
        {
            res.emplace_back(tmp);
            return; 
        }
        
        for(int i=begin; i<=n; ++i)
        {
            //cout<<i<<endl;
            tmp.emplace_back(i);
            solve(i+1,n,k,res,tmp);
            tmp.pop_back();
        }
        
        //cout<<endl;
    }
};

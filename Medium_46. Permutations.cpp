class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> tmp(nums);
        
        solve(res,tmp,0);
        
        return res;
    }
    
    void solve(vector<vector<int>>& res, vector<int>& tmp, int now)
    {
        int n=tmp.size();
        
        if(now>=n) 
        {
            //for(auto& i:tmp) cout<<i<<" ";
            //cout<<endl<<endl;
            
            res.push_back(tmp);
            return;
        }
        
        for(int i=now; i<n; ++i)
        {
            for(int j=i; j<n; ++j)
            {
                //cout<<i<<" , "<<j<<endl;
                
                if(i!=j) swap(tmp[i],tmp[j]);
                solve(res,tmp,i+1);
                if(i!=j) swap(tmp[i],tmp[j]);
            }
            
            break;
        }
        
    }
};

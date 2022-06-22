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

//2022-06-22
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        
        solve(0,nums,ans);
        return ans;
    }
    
    void solve(int now, vector<int>& nums, vector<vector<int>>& ans)
    {
        int n=nums.size();
        if(now==n)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=now; i<n; ++i)
        {
            swap(nums[now],nums[i]);
            solve(now+1,nums,ans);
            swap(nums[now],nums[i]);
        }
    }
};

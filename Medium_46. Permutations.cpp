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

//2022-06-22
//iterative
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        list<list<int>> ans;
        ans.push_back(list<int>(1,nums[0]));
        
        for(int i=1; i<nums.size(); ++i)
        {
            //cout<<i<<" : "<<endl;
            int cnt=ans.size();
            for(int j=0; j<cnt; ++j)
            {
                //cout<<j<<endl;
                list<int> tmp=ans.front();
                ans.pop_front();
                
                for(auto it=tmp.begin(); it!=tmp.end(); ++it)
                {                    
                    tmp.insert(it,nums[i]);
                    //for(auto& x:tmp) cout<<x<<" ";
                    //cout<<endl;
                    ans.push_back(tmp);
                    //auto removed=--it;
                    //++it;
                    --it;
                    it=tmp.erase(it);
                }
                
                tmp.push_back(nums[i]);
                //for(auto& x:tmp) cout<<x<<" ";
                //cout<<endl;
                ans.push_back(tmp);
            }
        }
        
        vector<vector<int>> final_ans;
        while(!ans.empty())
        {
            final_ans.push_back(vector<int>(ans.back().begin(),ans.back().end()));
            ans.pop_back();
        }
        
        return final_ans;
    }    
};

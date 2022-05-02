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

//2022-05-02
//iterative
//time  : O(2^n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<vector<int>> res;
        res.push_back({});
        
        for(int i=0; i<n; ++i)
        {
            int size=res.size();
            for(int j=0; j<size; ++j)
            {
                vector<int> tmp=res[j];
                tmp.push_back(nums[i]);
                
                res.push_back(tmp);
            }
        }
        
        //cout<<res.size()<<endl;
        return res;
    }
};

//2022-05-02
//bit manipulation
//time  : O(N*2^n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n=nums.size();
        int max_size=1<<n;
        
        vector<vector<int>> res(max_size,vector<int>());
        
        
        for(int bit=0; bit<max_size; ++bit)
        {
            for(int i=0; i<n; ++i)
            {
                //printf("%d,%d.  %d \n",bit,mask,mask&bit);
                if((1 & bit>>i)>0) res[bit].push_back(nums[i]);
            }
        }
        
        return res;
    }
};

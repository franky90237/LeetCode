//2022-05-02
//iterative
//time  : O(2^n)
//space : O(n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>> res;
        res.push_back({});
        
        sort(nums.begin(),nums.end());
        
        int cnt=0;
        for(int i=0; i<n; ++i)
        {
            int size=res.size();
            
            int j=0;            
            if(i!=0 && nums[i]==nums[i-1]) j=size-cnt;
            cnt=0;
            
            for(; j<size; ++j)
            {
                vector<int> tmp=res[j];
                tmp.push_back(nums[i]);
                
                res.push_back(tmp);
                ++cnt;
            }
        }
        
        //cout<<res.size()<<endl;
        return res;
    }
};

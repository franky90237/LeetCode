//2022-06-23
//rederence : https://www.youtube.com/watch?v=nYFd7VHKyWQ
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {                
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> num_cnt;
        num_cnt.push_back(vector<int>(2,1));
        num_cnt[0][0]=nums[0];
        
        for(int i=1; i<nums.size(); ++i)
        {
            if(nums[i-1]==nums[i])
            {
                ++num_cnt.back()[1];
            }
            else
            {
                num_cnt.push_back(vector<int>(2,1));
                num_cnt.back()[0]=nums[i];
            }
        }
        
        //for(int i=0; i<num_cnt.size(); ++i) printf("%d:%d \n",num_cnt[i][0],num_cnt[i][1]);
        
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(nums.size(),tmp,num_cnt,ans);
        return ans;
    }
    
    void solve(int max_size, vector<int>& tmp, vector<vector<int>>& nums, vector<vector<int>>& ans)
    {
        int n=nums.size();
        
        for(int i=0; i<n; ++i)
        {
            if(nums[i][1]==0) continue;
            
            --nums[i][1];
            tmp.push_back(nums[i][0]);
            
            solve(max_size,tmp,nums,ans);
            if(tmp.size()==max_size) ans.push_back(tmp);
            
            ++nums[i][1];
            tmp.pop_back();
        }        
    }
};

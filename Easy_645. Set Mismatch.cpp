//2022-04-23
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        
        int duplicate=0;
        for(int i=0; i<n; ++i)
        {
            int idx=abs(nums[i])-1;
            //cout<<idx<<endl;
            
            if(nums[idx]<0)
            {
                duplicate=idx+1;
            }
            else
            {
                nums[idx]=-nums[idx];
            }
        }
        
        for(int i=0; i<n; ++i)
        {            
            if(nums[i]>0)
            {
                return {duplicate,i+1};
            }
        }
        
        return {}; //dummy return
    }
};

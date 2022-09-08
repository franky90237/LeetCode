//2022-09-08
//time  : O(n)
//sapce : O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int n=nums.size();
        
        unordered_map<int,int> table;
        table[0]=-1;
        
        int ans=0;        
        int sum=0;        
        for(int i=0; i<n; ++i)
        {
            if(nums[i]==0) sum-=1;
            else sum+=1;            
            
            if(table.find(sum)==table.end())
            {
                table[sum]=i;
            }
            else
            {
                ans=max(ans,i-table[sum]);
            }
        }
        
        return ans;
    }
};

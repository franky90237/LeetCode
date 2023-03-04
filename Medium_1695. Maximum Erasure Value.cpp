class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        int left=0;
        int right=0;
        unordered_set<int> table;
        int sum=0;
        int ans=0;
        
        while(right < n)
        {
            while(table.count(nums[right]))
            {
                sum -= nums[left];
                table.erase(nums[left]);                
                ++left;
            }
            
            sum += nums[right];
            ans=max(ans, sum);
            table.insert(nums[right]);
            ++right;
            
            //cout<<right<<" "<<sum<<endl;
        }
        
        return ans;
    }
};

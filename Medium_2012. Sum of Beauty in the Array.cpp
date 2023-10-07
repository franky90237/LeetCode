class Solution {
public:
    int sumOfBeauties(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> left(n);
        left[0]=0;
        
        vector<int> right(n);
        right[n-1]=n-1;
        
        for(int i=1, k=n-2; i<n; ++i, --k)
        {
            if(nums[left[i-1]] < nums[i]) left[i]=i;
            else left[i]=left[i-1];
            if(nums[right[k+1]] > nums[k]) right[k]=k;
            else right[k]=right[k+1];
        }
        
        int ans=0;
        for(int i=1; i<n-1; ++i)
        {
            if(nums[left[i-1]] < nums[i] && nums[i] < nums[right[i+1]]) ans += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) ans += 1;
        }
        
        return ans;
    }
};

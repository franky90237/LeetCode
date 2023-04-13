//2023-04-13
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        int n=nums.size();
        if(n <= 4)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int k=3;        
        int left=0;
        int right=n-1;
        int lBound=k;
        int rBound=right-k;
        while(k > 0)
        {            
            int diffR=nums[right]-nums[rBound];
            int diffL=nums[lBound]-nums[left];
            if(diffL >= diffR)
            {
                nums[left]=nums[lBound];
                ++left;                                
            }
            else
            {
                nums[right]=nums[rBound];
                --right;
            }
                         
            --k;
            lBound=left+k;
            rBound=right-k;
        }   
        
        //for(auto num: nums) cout<<num<<" ";
        //cout<<endl;
        return nums[right]-nums[left];
    }
};

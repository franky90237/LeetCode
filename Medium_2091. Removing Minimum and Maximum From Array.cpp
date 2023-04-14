//2023-04-14
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        int minimum=nums[0];
        int maximum=nums[0];
        int minIdx=0;
        int maxIdx=0;
        
        int n=nums.size();
        for(int i=1; i<n; ++i)
        {
            if(nums[i] < minimum)
            {
                minimum=nums[i];
                minIdx=i;
            }
            
            if(nums[i] > maximum)
            {
                maximum=nums[i];
                maxIdx=i;
            }
        }
                
        int left=min(minIdx, maxIdx);
        int right=max(minIdx, maxIdx);
        //cout<<left<<" "<<right<<endl;
        
        int LR=left+(n-1-right)+2;
        int LL=right+1;
        int RR=n-1-left+1;
        
        return min(LR, min(LL, RR));
    }
};

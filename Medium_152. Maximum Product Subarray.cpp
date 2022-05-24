//2022-05-24
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n=nums.size();
        
        int leftProduct=1;
        int rightProduct=1;
        int res=nums[0];
        
        for(int i=0; i<n; ++i)
        {
            if(leftProduct==0) leftProduct=1;
            if(rightProduct==0) rightProduct=1;
            
            leftProduct*=nums[i];
            rightProduct*=nums[n-1-i];
            //printf("%d %d \n",leftProduct,rightProduct);
            
            res=max(res,max(leftProduct,rightProduct));
        }
        
        return res;
    }
};

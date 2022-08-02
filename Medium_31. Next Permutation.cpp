//2022-08-02
//time  : O(n)
//space : O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        /*
        1,2,3,4
        1,2,4,3
        1,3,2,4
        1,3,4,2        
        1,4,2,3
        1,4,3,2
        
        1,2,2
        2,1,2
        2,2,1
        
        1,3,(5),9,6,(5),4,2
        */
        
        int n=nums.size();
        if(n==1) return;
        
        int pre=n-2;       
        for(; pre>=0; --pre)
        {
            if(nums[pre]<nums[pre+1])
            {
                int pair=binary_search(nums,pre+1,n-1,nums[pre]);   
                //cout<<pair<<endl;
                
                swap(nums[pre],nums[pair]);
                reverse(nums,pre+1,n-1);
                break;
            }
        }
        
        //for all an decreasing order and not all same val
        //ex. [4,3,2,1], but bot [4,4,4,4]
        if(pre<0 && nums[0]!=nums[1]) reverse(nums,0,n-1);
    }
    
    int binary_search(vector<int>& nums, int left, int right, int target)
    {        
        while(left<right)
        {
            int mid=left+(right-left+1)/2;            
            //cout<<left<<" "<<mid<<" "<<right<<endl;
            
            //if(nums[mid]==target) right=mid-1;
            if(nums[mid]>target) left=mid;
            else right=mid-1;
        }
        
        return left;
    }
    
    void reverse(vector<int>& nums, int left, int right)
    {
        while(left<right)
        {
            swap(nums[left],nums[right]);
            ++left;
            --right;
        }
    }
};

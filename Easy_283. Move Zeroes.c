class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int insert_index=0;
        for(int current_index=0;current_index<nums.size();++current_index)
        {
            if(nums[current_index]!=0)
            {
                int temp=nums[insert_index];
                nums[insert_index]=nums[current_index];
                nums[current_index]=temp;
                
                ++insert_index;
            }
        }
    }
};

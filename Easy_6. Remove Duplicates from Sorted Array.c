class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int size=nums.size();
        if(size<=1) return size;
        
        int insert_index=1;
        for(int current_index=1;current_index<size;++current_index)
        {
            if(nums[current_index]!=nums[current_index-1])
            {
                nums[insert_index]=nums[current_index];
                ++insert_index;
            }            
        }
        
        return insert_index;
    }
};

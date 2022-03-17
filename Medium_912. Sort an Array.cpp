//merge sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        return merge_sort(nums,0,nums.size()-1);
    }
    
    vector<int> merge_sort(vector<int>& nums, int l, int h)
    {
        if(l>h) return {};
        if(l==h) return {nums[l]};
        
        int mid=l+(h-l)/2;
        vector<int> left_list=merge_sort(nums,l,mid);
        vector<int> right_list=merge_sort(nums,mid+1,h);
        
        return combine(left_list,right_list);
    }
    
    vector<int> combine(vector<int>& left, vector<int>& right)
    {
        vector<int> sorted_list(left.size()+right.size());
        
        int l=0,r=0,i=0;
        while(l<left.size() && r<right.size())
        {
            if(left[l]<right[r])
            {
                sorted_list[i]=left[l];
                ++l;
            }
            else
            {
                sorted_list[i]=right[r];
                ++r;
            }
            
            ++i;
        }
        
        while(l<left.size())
        {
            sorted_list[i]=left[l];
            ++l;
            ++i;
        }
        
        while(r<right.size())
        {
            sorted_list[i]=right[r];
            ++r;
            ++i;
        }
        
        return sorted_list;
    }
};

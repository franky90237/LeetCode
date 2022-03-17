//merge sort recursive
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

//merge sort iterative
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        merge_sort(nums);
        return nums;
    }
    
    void merge_sort(vector<int>& nums)
    {
        int n=nums.size();
        int merge_size=1;
        while(merge_size<n)
        {
            int cnt=ceil(n/(2*merge_size));
            for(int i=0; i<n; i+=2*merge_size)
            {
                merge(nums,merge_size,i,i+merge_size);
            }
            
            merge_size*=2;
        }
    }
    
    void merge(vector<int>& nums, int merge_size, int left, int right)
    {
        vector<int> tmp;
        
        //cout<<left<<" "<<right<<endl;
        int l=left,r=right;
        while(l<left+merge_size && r<nums.size() && r<right+merge_size)
        {
            if(nums[l]<nums[r])
            {
                tmp.push_back(nums[l]);
                ++l;
            }
            else
            {
                tmp.push_back(nums[r]);
                ++r;
            }
        }
        
        while(l<left+merge_size)
        {
            tmp.push_back(nums[l]);
            ++l;
        }
        
        while(r<nums.size() && r<right+merge_size)
        {
            tmp.push_back(nums[r]);
            ++r;
        }
        
        int i=left;
        for(auto& j:tmp) 
        {
            nums[i]=j;
            ++i;
        }
    }
};

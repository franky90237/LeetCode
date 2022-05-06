//2022-05-05
//quick select
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int n=nums.size();
        k=n-k;
        
        int res;
        int left=0;
        int right=n-1;
        
        do
        {            
            res=partition(nums,left,right);
            
            if(res>k) right=res-1;
            else left=res+1;
            
            //print_array(nums);
        } while(res!=k);
        
        return nums[res];
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        swap(nums[right],nums[left+(right-left)/2]);
        
        int small=left;
        while(left<right)
        {
            if(nums[left]<nums[right])
            {
                swap(nums[left],nums[small]);
                ++small;
            }
            
            ++left;
        }
        
        if(nums[small]>nums[right])
        {
            swap(nums[small],nums[right]);
        }
        
        return small;
    }
    
    void print_array(vector<int>& nums)
    {
        for(auto& i:nums)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

//2022-05-06
//time  : O(nlog(k))
//space : O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>> min_heap;
        
        for(auto& num:nums)
        {
            if(min_heap.size()<k)
            {
                min_heap.push(num);
            }
            else
            {
                if(num > min_heap.top())
                {
                    min_heap.pop();
                    min_heap.push(num);
                }
            }
        }
        
        return min_heap.top();
    }
};

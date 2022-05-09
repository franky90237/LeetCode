//2022-05-06
//bucket sort
//time  : O(n)
//space : O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) return;
        
        int bucket[5001]={0};
        for(auto& num:nums) ++bucket[num];
        
        int b_i=0;
        int n_i=(n%2==0) ? n-2 : n-1;
        for(; n_i>=0; ++b_i)
        {
            while(bucket[b_i]!=0 && n_i>=0)
            {
                nums[n_i]=b_i;
                n_i-=2;
                --bucket[b_i];
            }                        
        }
        
        b_i=5000;
        n_i=1;
        for(; n_i<n; --b_i)
        {
            while(bucket[b_i]!=0 && n_i<n)
            {
                nums[n_i]=b_i;
                n_i+=2;
                --bucket[b_i];
            }
        }
        
    }
};

//2022-05-09
//time  : O(n)
//space : O(1)
class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int n=nums.size();
        median_quick_select(nums);
        //for(int i=0; i<5; ++i) printf("%d,%d \n",i,new_index(i,5));
        
        int mid_val=nums[n/2];
        int i=0, left=0, right=n-1;
        while(i<=right)
        {            
            if(nums[new_index(i,n)]>mid_val)
            {
                swap(nums[new_index(i,n)],nums[new_index(left,n)]);
                ++left;
                ++i;
            }
            else if(nums[new_index(i,n)]<mid_val)
            {
                swap(nums[new_index(i,n)],nums[new_index(right,n)]);
                --right;
                //++i;
            }
            else
            {
                ++i;
            }
            
            //printf("%d : ", new_index(i-1,n));
            //print_nums(nums);
        }
    }
    
    void median_quick_select(vector<int>& nums)
    {
        int n=nums.size();
        int mid=(n-1)/2;
        
        int idx;
        int left=0;
        int right=n-1;
        do
        {
            idx=partition(nums,left,right);
            
            if(idx>mid) right=idx-1;
            else left=idx+1;
            
            //print_nums(nums);
        } while(idx!=mid);                
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        swap(nums[right],nums[left+(right-left)/2]);
        
        int i=left;
        int big=left;        
        while(i<right)
        {
            if(nums[i]>nums[right])
            {
                swap(nums[i],nums[big]);
                ++big;
            }
            
            ++i;
        }
        
        if(nums[right]>nums[big])
        {
            swap(nums[right],nums[big]);
        }        
        
        return big;
    }
    
    //assume index between 0 to 3
    //0 maps to 1 : 0*2+1=1
    //1 maps to 3 : 1*2+1=3
    //2 maps to 0 : (2-2)*2+1-1=0
    //3 maps to 2 : (3-2)*2+1-1=2
    int new_index(int original, int size)
    {
        int odd=size/2;
        
        if(original>=odd) return (original-odd)*2+1-1;
        return original*2+1;
    }
    
    void print_nums(vector<int>& nums)
    {
        for(auto& i:nums) printf("%d ",i);
        printf("\n");
    }
};

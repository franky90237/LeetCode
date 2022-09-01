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

//2022-06-22
//time  : O(n)
//space : O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n=nums.size();
        
        int zero=0;        
        for(int i=0; i<n; ++i)
        {
            if(nums[i]!=0)
            {
                swap(nums[zero],nums[i]);
                ++zero;
            }
            
            //for(auto& num:nums) cout<<num<<" ";
            //cout<<endl;
        }                
    }
};

//2022-06-22
//no swap
//time  : O(n)
//space : O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n=nums.size();
        
        int zero=0;        
        for(int i=0; i<n; ++i)
        {
            if(nums[i]!=0)
            {
                nums[zero]=nums[i];
                ++zero;
            }
            
            for(auto& num:nums) cout<<num<<" ";
            cout<<endl;
        }
        
        while(zero<n)
        {
            nums[zero]=0;
            ++zero;
        }
    }
};

//2022-09-01
//time  : O(n)
//space : O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int idx=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]!=0)
            {
                swap(nums[idx],nums[i]);
                ++idx;
            }
        }                
    }
};

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

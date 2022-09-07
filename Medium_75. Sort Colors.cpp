//2022-05-03
//time  : O(n)
//space : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int cnt[3]={0};
        for(auto& num:nums) ++cnt[num];
        
        int idx=0;
        for(int i=0; i<3; ++i)
        {
            while(cnt[i]!=0) 
            {                
                nums[idx]=i;
                ++idx;
                
                --cnt[i];
            }
        }
    }
};

//2022-05-04
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int zero=0;
        int i=0;
        int two=nums.size()-1;
        
        while(i<=two)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[zero]);
                ++i;
                ++zero;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[two]);
                --two;
            }
            else
            {
                ++i;
            }
        }
    }
};

//2022-09-07
//time  : O(n)
//sapce : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        /*

        i
        *  
        1,2,2,0,0
        ^       ^
        f       s

        i=0:
        *
        1,2,2,0,0
        ^       ^
        f       s

        i=1:
          *
        1,0,2,0,2
        ^     ^
        f     s

        i=1:
          *
        0,1,2,0,2
          ^   ^
          f   s

        i=2:
            *
        0,1,0,2,2
          ^ ^
          f s

        i=2:
            *
        0,0,1,2,2
            ^
            s
            f

        i=3:
              *
        0,0,1,2,2
            ^
            s
            f

        */        
        int n=nums.size();
        
        int p0=0;
        int p2=n-1;
        int i=0;
        while(i<=p2)
        {
            if(nums[i]==2)
            {
                swap(nums[i],nums[p2]);
                --p2;
            }
            else if(nums[i]==0)
            {
                swap(nums[i],nums[p0]);
                ++p0;
                ++i;
            }
            else
            {
                ++i;
            }
        }
        
    }
};

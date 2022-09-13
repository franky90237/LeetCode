//2022-09-13
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        /*
              3,5,6,7,8,8,8,8,2,1
              3,4,2,3
              ^   *
        s : 0
        c : 2
        3>2 4>3
        
            [-1,4,2,3]
                * ^
        b:    0 0 1  
        */
        
        int n=nums.size();
        
        int pre=nums[0];       
        int bigger=0;
        
        for(int i=1; i<n; ++i)
        {
            if(nums[i-1]>nums[i])
            {
                if(i-2>=0) 
                {
                    if(nums[i-2]>nums[i]) nums[i]=nums[i-1];
                    else nums[i-1]=nums[i-2];
                }                
                
                ++bigger;
            }
            
            if(bigger>=2) return false;
        }
                
        return true;
    }
};

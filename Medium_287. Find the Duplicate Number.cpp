//2022-04-22
//binary search
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size()-1;
        int low=1;
        int high=n;
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            int cnt_greater=0;
            int cnt_equal=0;
            for(auto& i:nums)
            {
                if(i>=mid) ++cnt_greater;
                if(i==mid) 
                {
                    ++cnt_equal;
                    if(cnt_equal==2) return mid;
                }
            }
            
            int diff=n-mid+1;
            if(cnt_greater>diff)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return low;
    }
};

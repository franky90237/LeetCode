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

//2022-04-22
//clear binary search
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
            
            int cnt=0;
            for(auto& i:nums)
            {
                if(i<=mid) ++cnt;
            }
                        
            if(cnt>mid) high=mid;
            else        low=mid+1;            
        }
        
        return low;
    }
};

//2022-04-22
//bit manipulation
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        int bits=log(n-1)/log(2);
        int res=0;
        for(int bit=0; bit<=bits; ++bit)
        {
            int sum1=0;
            for(int i=1; i<n; ++i) sum1+=(i>>bit)&1;
            
            int sum2=0;
            for(auto& i:nums) sum2+=(i>>bit)&1;
            
            if(sum2>sum1) res+=(1<<bit);
        }
        
        return res;
    }
};

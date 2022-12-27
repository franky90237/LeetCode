//2022-12-27
//time  : O(log(maxSum))
//space : O(1)
class Solution 
{    
public:
    int maxValue(int n, int index, int maxSum)
    {
        int l=1;
        int r=maxSum;
        int ans=0;
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            
            if(check(n, index, maxSum, mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        return ans;
    }
    
    bool check(int n, int index, int maxSum, int val)
    {        
        int left_len=index;
        int right_len=n-index-1;
                
        long left_sum = get_sum(left_len, val);
        long right_sum = get_sum(right_len, val);
        long sum = left_sum + right_sum + val;
        //cout<<left_sum<<" "<<right_sum<<endl;
        
        return sum <= maxSum;
    }
    
    long get_sum(int len, int maxVal)
    {
        if(len <= 0) return 0;
        
        long sum=0;
        long end=maxVal-1;
        long begin=maxVal-len;
        if(begin <= 0)
        {            
            sum += -(begin)+1;
            begin=1;
        }
        
        sum += (begin+end) * (end-begin+1) / 2;
        
        /*if(len < maxVal)
        {
            long begin = maxVal - len;
            long end = maxVal - 1;
            sum = (begin + end) * len / 2;
        }
        else
        {
            long begin = maxVal - len;
            long end = maxVal - 1;
            sum = -(begin)+1 + (1+end)*end/2;
        }*/
        
        return sum;
    }
};

//2023-10-29
//time  : O(n)
//space : O(1)
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {        
        long long sum1=0;
        long long cnt1=0;
        for(int num: nums1)
        {
            sum1 += num;
            if(num == 0) ++cnt1;
        }
        
        long long sum2=0;
        long long cnt2=0;
        for(int num: nums2)
        {
            sum2 += num;
            if(num == 0) ++cnt2;
        }
        
        //cout<<cnt1<<" "<<sum1<<endl;
        //cout<<cnt2<<" "<<sum2<<endl;
        
        if(sum1 == sum2)
        {
            if((cnt1 == 0 && cnt2 > 0) || (cnt1 > 0 && cnt2 == 0)) return -1;
            return sum1 + max(cnt1, cnt2);
        }
        
        if(sum1 > sum2) return minSum(nums2, nums1);        
        
        if(cnt1 > cnt2)
        {            
            if(cnt1 >= (sum2-sum1+cnt2))
            {
                if(cnt2 == 0)
                {
                    if(cnt1 > sum2-sum1) return -1;
                }
                return sum1 + cnt1;
            }
            return sum2 + cnt2;
        }
        else //if(cnt1 <= cnt2)
        {          
            if(cnt1 <= 0) return -1;
            return sum2 + cnt2;
        }                        
    }
};

//2023-10-30
//time  : O(n)
//space : O(1)
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long sum1=0;
        long long cnt1=0;
        for(int num: nums1)
        {
            if(num == 0) ++cnt1;
            sum1 += num;
        }
        
        long long sum2=0;
        long long cnt2=0;
        for(int num: nums2)
        {
            if(num == 0) ++cnt2;
            sum2 += num;
        }
        
        //cout<<sum1<<" "<<cnt1<<endl;
        //cout<<sum2<<" "<<cnt2<<endl;
        
        if(cnt1 == 0 && cnt2 == 0)
        {
            if(sum1 == sum2) return sum1;
            return -1;
        }
        
        /*
        
        15
        0 0 9
        
        1
        0 0 9
        
        */
        
        if(cnt1 == 0 && cnt2 > 0)
        {
            if(sum1 < sum2+cnt2) return -1;
            return sum1;
        }
        
        if(cnt2 == 0 && cnt1 > 0)
        {
            if(sum2 < sum1+cnt1) return -1;
            return sum2;
        }
                
        /*
        
        0 0 0 0
        0 0 1
        
        0 0 
        0 0 0 0 1
        
        0 0 0 0  
        0 0 9
        
        0 0 
        0 0 0 0 9
        */
                
        long long diff=abs(sum1-sum2);
        if(sum1 < sum2)
        {
            //cout<<diff<<" "<<cnt2<<endl;
            if(diff+cnt2 < cnt1) return sum1+cnt1;
            return sum2+cnt2;
        }
        else
        {
            if(diff+cnt1 < cnt2) return sum2+cnt2;
            return sum1+cnt1;
        }
    }
};

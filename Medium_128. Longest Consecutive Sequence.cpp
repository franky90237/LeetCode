//2022-05-27
//TLE
//time  : O(max(nums))
//space : O(max(nums))
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0) return 0;
        
        int max_num=abs(nums[0]);
        for(int i=1; i<n; ++i) max_num=max(max_num,abs(nums[i]));
        
        cout<<max_num<<endl;
        bool *buckets=new bool[2*max_num+1];
        memset(buckets,0,sizeof(bool)*(2*max_num+1));
        
        for(auto& num:nums) 
        {
            //cout<<num+max_num<<" ";
            buckets[num+max_num]=1;
        }
        //for(int i=0; i<=2*max_num; ++i) cout<<buckets[i]<<" ";
        
        int max_len=1;        
        for(int i=0; i<=2*max_num; ++i)
        {            
            if(buckets[i]==0) continue;
            
            int len=1;
            int j=i+1;
            while(j<=2*max_num && buckets[j]!=0)
            {
                ++j;
                ++len;
            }
            
            max_len=max(max_len,len);
            i=j-1;
        }
        
        return max_len;
    }
};

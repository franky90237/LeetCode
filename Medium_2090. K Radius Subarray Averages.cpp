//2022-12-06
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        if(k == 0) return nums;
        
        int n=nums.size();
        vector<int> ans(n, -1);
        
        int len=2*k+1;
        if(len > n) return ans;
        
        long long sum=0;       
        for(int i=0; i<len; ++i) 
        {        
            sum += nums[i];
        }
        
        ans[k]=sum/len;
        
        for(int i=k+1; i+k<n; ++i)
        {           
            sum -= nums[i-k-1];
            sum += nums[i+k];
            //cout<<sum<<endl;
            ans[i]=sum/len;
        }
        
        return ans;
    }
};

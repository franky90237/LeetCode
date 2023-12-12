//2023-12-12
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int target=*max_element(nums.begin(), nums.end());
                
        vector<int> idx;
        long long ans=0;
        for(int i=0; i<n; ++i)
        {            
            if(nums[i] == target) idx.push_back(i);                            
                                 
            int left=idx.size()-k;
            if(left >= 0) ans += idx[left] + 1LL;            
            
            //cout<<i<<" | "<<left<<" "<<ans<<endl;
        }
        
        return ans;
    }
};

//2023-12-12
//time  : O(n)
//space : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int target=*max_element(nums.begin(), nums.end());
        
        long long ans=0;
        int cnt=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            if(nums[right] == target) ++cnt;
            while(cnt >= k)
            {
                if(nums[left] == target) --cnt;
                ++left;
            }
            
            if(cnt == k-1) ans += left;
        }
        
        return ans;
    }
};

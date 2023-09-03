//2023-09-03
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int, int> preCnt;
        preCnt[0]=1;
        int cnt=0;
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] % 2 == 1) ++cnt;
            int target=cnt-k;
            if(preCnt.find(target) != preCnt.end()) ans += preCnt[target];
            ++preCnt[cnt];
        }
        
        return ans;
    }
};

//2023-09-03
//time  : O(n)
//spcae : O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int left=0;
        while(left < n && nums[left] % 2 == 0) ++left;
        
        int pre=-1;
        int cnt=0;
        int ans=0;
        for(int right=left; right<n; ++right)
        {
            if(nums[right] % 2 == 1) 
            {                
                ++cnt;
            }
            
            if(cnt > k)
            {
                pre=left;
                ++left;
                while(left < right && nums[left] % 2 != 1)
                {
                    ++left;
                }
                --cnt;                                
            }
            
            if(cnt == k)
            {
                ans += left-pre;
            }
            
            //cout<<left<<" "<<right<<" | "<<ans<<endl;
        }
        
        return ans;
    }
};

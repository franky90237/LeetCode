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

//2023-10-15
//time  : O(n)
//space : O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        std::transform(nums.begin(), nums.end(), nums.begin(), [](int num)-> int
        {
            return num = (num%2 == 1);
        });
        
        //for(auto i: nums) cout<<i<<" "; cout<<endl;
        
        int n=nums.size();
        int ans=0;
        int sum=0;
        unordered_map<int, int> prefixSum;
        prefixSum[0]=1;
        for(int i=0; i<n; ++i)
        {
            sum += nums[i];
            int target=sum-k;
            if(prefixSum.count(target) > 0)
            {
                ans += prefixSum[target];
            }
            
            ++prefixSum[sum];
        }
        
        return ans;
    }
};

//2023-10-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        std::transform(nums.begin(), nums.end(), nums.begin(), [](int num)-> int
        {
            return num = (num%2 == 1);
        });
        
        //for(auto i: nums) cout<<i<<" "; cout<<endl;
        
        int n=nums.size();
        int ans=0;
        int sum=0;
        int cntSubarray=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            sum += nums[right];                        
            
            if(sum == k)
            {
                cntSubarray=0;
                while(sum == k)
                {
                    ++cntSubarray;
                    sum -= nums[left];
                    ++left;
                }                                
            }
            
            ans += cntSubarray;
        }
        
        return ans;
    }
};

//2023-08-29
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int target) 
    {
        int n=nums.size();
        long long total=accumulate(nums.begin(), nums.end(), 0LL);
        if(total < target) return -1;
        
        sort(nums.begin(), nums.end());
        
        int ans=0;        
        int idx=0;
        long long powerOf2=1;
        for(int i=0; i<32; ++i)
        {
            if(((target>>i)&1) == 0) continue;
            
            powerOf2=1<<i;
            long long sum=0;
            while(idx < n)
            {
                sum+=nums[idx];
                if(sum >= powerOf2)
                {
                    int diff=getDiff(sum, powerOf2);
                    ans += diff;
                    if(diff > 0) i += diff-1;
                    ++idx;
                    break;
                }
                
                ++idx;                
            }
        }
        
        return ans;
    }
    
    int getDiff(int a, int b)
    {
        int cnt=0;
        while((a>>1) >= b)
        {
            ++cnt;
            a=a>>1;
        }
        
        return cnt;
    }
};

//2023-08-29
//time  : O(n)
//space : O(32)
class Solution {
public:
    int minOperations(vector<int>& nums, int target) 
    {
        int n=nums.size();
        long long total=accumulate(nums.begin(), nums.end(), 0LL);
        if(total < target) return -1;
        
        vector<int> bitCnt(33, 0);
        for(auto num: nums)
        {
            int power=log2(num);
            ++bitCnt[power];
        }
        
        int ans=0;
        for(int i=0; i<32; ++i)
        {
            //cout<<endl<<i<<" "<<((target>>i)&1)<<endl;
            if(((target>>i)&1) == 1)
            {
                //cout<<i<<" "<<ans<<" | "<<bitCnt[i]<<endl;
                if(bitCnt[i] >= 1)
                {
                    --bitCnt[i];
                }
                else
                {
                    while(i < 32 && bitCnt[i] == 0)
                    {
                        ++ans;
                        ++i;
                    }

                    --bitCnt[i];
                    --i;
                }
            }
            
            bitCnt[i+1]+=bitCnt[i]/2;
        }
        
        return ans;
    }    
};

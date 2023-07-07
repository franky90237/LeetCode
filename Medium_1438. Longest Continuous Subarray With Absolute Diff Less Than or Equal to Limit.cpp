//2023-07-05
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int n=nums.size();
        int ans=0;
        map<int, int> table;
        for(int left=0, right=0; right<n; ++right)
        {
            ++table[nums[right]];
            while((table.rbegin())->first - (table.begin())->first > limit)
            {
                --table[nums[left]];
                if(table[nums[left]] == 0) table.erase(nums[left]);
                ++left;
            }
                        
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};

//2023-07-08
//time  : O(n)
//space : O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int n=nums.size();
        int ans=0;
        deque<int> dqMax;
        deque<int> dqMin;
        for(int left=0, right=0; right<n; ++right)
        {
            while(!dqMax.empty() && nums[dqMax.back()] <= nums[right])
            {
                dqMax.pop_back();
            }
            
            while(!dqMin.empty() && nums[dqMin.back()] >= nums[right])
            {
                dqMin.pop_back();
            }
            
            dqMax.push_back(right);
            dqMin.push_back(right);
            
            while(nums[dqMax.front()] - nums[dqMin.front()] > limit)
            {
                if(dqMax.front() < dqMin.front()) 
                {
                    left=dqMax.front()+1;
                    dqMax.pop_front();
                }
                else 
                {
                    left=dqMin.front()+1;
                    dqMin.pop_front();
                }
            }
            
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};

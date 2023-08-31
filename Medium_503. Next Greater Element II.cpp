//2023-09-01
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n, -1);
        stack<int> monoStack;
        for(int i=0; i<n; ++i)
        {
            while(!monoStack.empty() && nums[monoStack.top()] < nums[i])
            {
                ans[monoStack.top()]=nums[i];
                monoStack.pop();
            }
            
            monoStack.push(i);
        }
        
        for(int i=0; i<n; ++i)
        {
            while(!monoStack.empty() && nums[monoStack.top()] < nums[i])
            {
                ans[monoStack.top()]=nums[i];
                monoStack.pop();
            }
            
            if(monoStack.empty()) break;
        }                
        
        return ans;
    }
};

//2023-08-30
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) 
    {
        int n=nums.size();
        
        stack<int> monoStack;
        multimap<int, int> base;
        vector<int> ans(n, -1);
        for(int i=0; i<n; ++i)
        {
            while(!base.empty() && (base.begin())->first < nums[i])
            {                
                int idx=(base.begin())->second;                
                ans[idx]=nums[i];
                base.erase(base.begin());
            }
            
            while(!monoStack.empty() && nums[monoStack.top()] < nums[i])
            {
                base.insert({nums[monoStack.top()], monoStack.top()});
                monoStack.pop();
            }
            
            monoStack.push(i);
            //for(auto x: ans) cout<<x<<" "; cout<<endl;
        }
        
        return ans;
    }
};

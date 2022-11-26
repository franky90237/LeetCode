//2022-11-26
//time  : O(n)
//space : O(n)
/*
thinking :
1. only 1 elemnt, only 2 element, ... only n element
2. from small to big
3. from big to small
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();        
        int mod=1e9+7;
        
        int ans=0;
        int preSum=0;
        vector<pair<int, int>> monoStack;
        for(int i=0; i<n; ++i)
        {        
            while(!monoStack.empty() && arr[monoStack.back().first] >= arr[i])
            {
                monoStack.pop_back();
            }
            
            int sum=0;
            int left=-1;
            if(!monoStack.empty())
            {
                left=monoStack.back().first;
                sum = monoStack.back().second;
            }
            
            int len=i-left;
            sum = (sum + arr[i]*len) % mod;
            
            monoStack.push_back({i, sum});
            ans = (ans + sum)  % mod;
        }
        
        return ans;
    }
};

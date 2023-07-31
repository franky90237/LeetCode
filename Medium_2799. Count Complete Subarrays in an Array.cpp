//2023-07-31
//time  : O(n)
//space : O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {        
        unordered_map<int, int> table;
        for(auto num: nums)
        {
            ++table[num];
        }
        
        int n=nums.size();
        
        unordered_map<int, int> tmp;
        int cnt=0;
        int left=0;
        for(int right=0; right<n; ++right)
        {
            ++tmp[nums[right]];
            while(tmp.size() == table.size())
            {
                --tmp[nums[left]];
                if(tmp[nums[left]] == 0) tmp.erase(nums[left]);
                ++left;
            }
            
            cnt += right-left+1;
            //cout<<tmp.size()<<" | "<<table.size()<<endl;
            //cout<<left<<" "<<right<<" | "<<cnt<<endl;
        }
        
        return (1+n)*n/2 - cnt;
    }
};

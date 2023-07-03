//2023-07-03
//time  : O(nlogn)
//space : O(n)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        long long ans=0;
        multiset<int> array;
        int n=nums.size();
        for(int i=0, j=0; j<n; ++j)
        {
            array.insert(nums[j]);
            while(!valid(array))
            {
                auto it=array.find(nums[i]);
                array.erase(it);
                ++i;
            }
            
            ans += j-i+1;
        }
        
        return ans;
    }
    
    bool valid(multiset<int>& array)
    {
        int small=*(array.begin());
        int large=*(array.rbegin());
        int diff=large-small;
        return (0 <= diff) && (diff <= 2);
    }
};

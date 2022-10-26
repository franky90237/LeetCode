//2022-10-26
//TLE
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        //int totalNums=accumulate(nums.begin(), nums.end(), 0);
        
        int n=nums.size();
        
        unordered_set<int> remainder[n];
        remainder[0].insert(nums[0]%k);
        
        for(int i=1; i<nums.size(); ++i)
        {            
            int r=nums[i]%k;
            //cout<<i<<" "<<r<<endl;
            if(remainder[i-1].find((k-r)%k) != remainder[i].end()) return true;
            
            remainder[i].insert(r);
            for(auto& it: remainder[i-1])
            {                
                remainder[i].insert((it+r)%k);
            }
        }
        
        return false;
    }
};

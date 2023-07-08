//2023-07-08
//time  : O(nlogn)
//space : O(nlogn)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        set<pair<int, int>> subseq;
        subseq.insert({nums[0]+k, nums[0]-k});
        for(int i=1; i<n; ++i)
        {
            auto it=getSubseq(subseq, nums[i], k);
            if(it == subseq.end())
            {
                //cout<<nums[i]<<endl;                
                subseq.insert({nums[i]+k, nums[i]-k});
            }
            else
            {
                int left=max(nums[i]-k , it->second);
                int right=min(nums[i]+k, it->first);
                subseq.erase(it);
                subseq.insert({right, left});
            }
        }
        
        return subseq.size();
    }
    
    set<pair<int, int>>::iterator getSubseq(set<pair<int, int>>& subseq, int val, int k)
    {
        auto it=subseq.lower_bound({val, INT_MIN});
        //cout<<val<<" | "<<it->second<<" "<<it->first<<endl;
        if(it == subseq.end()) return it;        
        if(it->second <= val && val <= it->first) return it;
        return subseq.end();
    }
};

//2023-07-08
//time  : O(nlogn)
//space : O(nlogn)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();        
        int ans=1;
        for(int left=0, right=0; right<n; ++right)
        {
            if(nums[right]-nums[left] > k)
            {
                ++ans;
                left=right;
            }
        }
        
        return ans;
    }     
};

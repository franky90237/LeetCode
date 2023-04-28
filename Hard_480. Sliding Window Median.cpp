//2023-04-28
//time  : O(nlog(k))
//space : O(k)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        vector<double> ans;
        multiset<long long> lower;
        multiset<long long> upper;
        
        int n=nums.size();
        int left=0;
        for(int right=0; right<n; ++right)
        {
            int len=right-left+1;
            if(len > k)
            {
                auto it=lower.find(nums[left]);
                if(it != lower.end())
                {
                    lower.erase(it);
                }
                else
                {
                    auto it=upper.find(nums[left]);
                    if(it != upper.end())
                    {
                        upper.erase(it);
                    }
                }
                
                ++left;
            }
            
            int lowerThreshold=(k+1)/2;
            lower.insert(nums[right]);
            if(lower.size() > lowerThreshold)
            {
                auto it=std::prev(lower.end(), 1);
                int target=*(it);
                lower.erase(it);
                upper.insert(target);
            }
            
            if(lower.size() == lowerThreshold && !upper.empty() && *(lower.rbegin()) > *(upper.begin()))
            {
                auto it=std::prev(lower.end(), 1);
                int target=*(it);
                lower.erase(it);
                upper.insert(target);

                it=upper.begin();
                target=*(it);
                upper.erase(it);
                lower.insert(target);
            }
            
            if(len >= k)
            {
                if(k % 2 == 1)
                {
                    ans.push_back(*(lower.rbegin()));
                }
                else
                {                    
                    ans.push_back((*(lower.rbegin()) + *(upper.begin())) / 2.0);
                }
            }
            
            /*
            cout<<endl<<right<<"***"<<endl;
            for(auto& it: lower) cout<<it<<" ";
            cout<<endl;
            for(auto& it: upper) cout<<it<<" ";
            cout<<endl;
            */
        }
        
        return ans;
    }
};

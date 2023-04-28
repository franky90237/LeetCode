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

//2023-04-28
//time  : O(nlog(k))
//space : O(k)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        vector<double> ans;
        
        auto compLower = [&](const int a, const int b)
        {            
            return nums[a] > nums[b];
        };
        multiset<int, decltype(compLower)> lower(compLower);
        
        /*
        lower.insert(0);
        lower.insert(1);
        for(auto& it: lower) cout<<nums[it]<<" "; cout<<endl;
        cout<<endl;
        lower.erase(0);
        for(auto& it: lower) cout<<nums[it]<<" "; cout<<endl;
        return ans;
        */
        
        auto compUpper = [&](const int a, const int b)
        {
            return nums[a] < nums[b];
        };
        multiset<int, decltype(compUpper)> upper(compUpper);
                
        auto balance = [&]()
        {
            int maxCntLower=(k+1)/2;
            if(lower.size() > maxCntLower)
            {  
                int target=*(lower.begin());
                lower.erase(lower.begin());
                upper.insert(target);
            }
            
            if(!upper.empty() && nums[*(lower.begin())] > nums[*(upper.begin())])
            {                
                int target=*(lower.begin());
                lower.erase(lower.begin());
                upper.insert(target);
                                
                target=*(upper.begin());
                upper.erase(upper.begin());
                lower.insert(target);
            }
        };
        
        int cnt=0;
        int n=nums.size();
        int left=0;
        for(int right=0; right<n; ++right)
        {
            int len=right-left+1;
            if(len > k)
            {
                if(lower.find(left) != lower.end())
                {
                    lower.erase(lower.find(left));
                }
                else
                {
                    upper.erase(upper.find(left));
                }
                
                ++left;
            }
                        
            lower.insert(cnt++);
            balance();
            
            if(len >= k)
            {
                if(k % 2 == 1)
                {
                    ans.push_back(nums[*(lower.begin())]);
                }
                else
                {
                    long long lPart=nums[*(lower.begin())];
                    long long rPart=nums[*(upper.begin())];
                    double median = (lPart + rPart) / 2.0;
                    ans.push_back(median);
                }
            }
            
            /*
            cout<<right<<"***"<<endl;
            for(auto& it: lower) cout<<nums[it]<<" ";
            cout<<endl;
            for(auto& it: upper) cout<<nums[it]<<" ";
            cout<<endl;
            */          
        }
        
        return ans;
    }
};

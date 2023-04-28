//2023-04-23
//time  : O(n*range of nums)
//space : O(n)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x)
    {
        int n=nums.size();
        vector<int> ans;
        
        map<int, int> freq;
        for(int i=0; i<n; ++i)
        {
            if(i >= k && nums[i-k] < 0)
            {
                --freq[nums[i-k]];
            }
            
            if(nums[i] < 0) 
            {
                ++freq[nums[i]];
            }
            
            if(i >= k-1)
            {
                int xthMin = getXthMin(freq, x);
                ans.push_back(xthMin);
            }
        }
        
        return ans;
    }
    
    int getXthMin(map<int, int>& freq, int x)
    {               
        int sum=0;
        for(auto& it: freq)
        {
            int num=it.first;
            int cnt=it.second;
            
            sum+=cnt;
            if(sum >= x) return num;
        }
        
        return 0;
    }
};

//2023-04-28
//time  : O(nlog(k))
//spcae : O(k)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        int n=nums.size();
        vector<int> ans;
        multiset<int> lower;
        multiset<int> upper;
        
        int left=0;
        for(int right=0; right<n; ++right)
        {                        
            int len=right-left+1;
            if(len > k)
            {
                auto it=upper.find(nums[left]);
                if(it != upper.end())
                {
                    upper.erase(it);
                }
                else
                {
                    it = lower.find(nums[left]);
                    if(it != lower.end())
                    {
                        lower.erase(it);
                        if(lower.size() < x && !upper.empty())
                        {
                            lower.insert(*(upper.begin()));
                            upper.erase(upper.begin());
                        }
                    }
                }
                
                ++left;
            }
            
            if(nums[right] < 0)
            {
                if(lower.size() < x)
                {
                    lower.insert(nums[right]);
                }
                else
                {
                    auto last=lower.end();
                    auto it=std::prev(lower.end(), 1);
                    int target=*it;
                    lower.erase(it);

                    upper.insert(target);
                    upper.insert(nums[right]);                
                    target=*(upper.begin());
                    upper.erase(upper.begin());

                    lower.insert(target);
                }
            }
            
            if(len >= k)
            {
                if(lower.size() == x) ans.push_back(*(lower.rbegin()));
                else ans.push_back(0);
            }
            
            /*
            cout<<right<<"****"<<endl;
            for(auto& it: lower) cout<<it<<" ";
            cout<<endl;
            for(auto& it: upper) cout<<it<<" ";
            cout<<endl;
            */
        }
        
        return ans;
    }
};

/*
[1,-1,-3,-2,3]
3
2
[-46,-34,-46]
3
3
[39,-7,27,19,12]
3
3
[-30,-17,23,35]
3
1
[0,-28,-8]
1
1
[-28,8,-37,-35,-4]
3
1
[-6,40,-38,-36,-36,-4,-38,-43,8]
2
2
*/

//2023-04-28
//time  : O(nlog(k))
//spcae : O(k)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        int n=nums.size();
        vector<int> ans;
        multiset<int> lower;
        multiset<int> upper;
        
        int left=0;
        for(int right=0; right<n; ++right)
        {                        
            int len=right-left+1;
            if(len > k)
            {
                auto it=upper.find(nums[left]);
                if(it != upper.end())
                {
                    upper.erase(it);
                }
                else
                {
                    it = lower.find(nums[left]);
                    if(it != lower.end())
                    {
                        lower.erase(it);                     
                    }
                }
                
                ++left;
            }
            
            if(nums[right] < 0)
            {
                upper.insert(nums[right]);                                              
            }
            
            if(lower.size() < x && !upper.empty())
            {
                int target=*(upper.begin());
                upper.erase(upper.begin());
                lower.insert(target);
            }
            
            if(lower.size() == x && !upper.empty() && *(lower.rbegin()) > *(upper.begin()))
            {
                int target=*(lower.rbegin());
                lower.erase(std::prev(lower.end(), 1));
                upper.insert(target);
                
                target=*(upper.begin());
                upper.erase(upper.begin());
                lower.insert(target);                
            }
                                    
            if(len >= k)
            {
                if(lower.size() == x) ans.push_back(*(lower.rbegin()));
                else ans.push_back(0);
            }
            
            /*
            cout<<right<<"****"<<endl;
            for(auto& it: lower) cout<<it<<" ";
            cout<<endl;
            for(auto& it: upper) cout<<it<<" ";
            cout<<endl;
            */
        }
        
        return ans;
    }
};

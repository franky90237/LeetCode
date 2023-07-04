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

//2023-07-04
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        int n=nums.size();
        long long ans=0;
        deque<int> minimum;
        deque<int> maximum;
        for(int i=0, j=0; j<n; ++j)
        {
            while(!isInRange(nums, minimum, nums[j]))
            {
                i = max(i, minimum.front()+1);
                minimum.pop_front();
            }
            
            while(!isInRange(nums, maximum, nums[j]))
            {
                i = max(i, maximum.front()+1);
                maximum.pop_front();
            }
            
            while(!minimum.empty() && minimum.front() < i)
            {
                minimum.pop_front();
            }
            
            while(!maximum.empty() && maximum.front() < i)
            {
                maximum.pop_front();
            }
            
            while(!minimum.empty() && nums[minimum.back()] >= nums[j])
            {
                minimum.pop_back();
            }
            
            while(!maximum.empty() && nums[maximum.back()] <= nums[j])
            {
                maximum.pop_back();
            }
            
            minimum.push_back(j);
            maximum.push_back(j);
            
            ans += j-i+1;
            
            /*
            cout<<i<<" "<<j<<" | "<<ans<<endl;
            for(int i=0; i<minimum.size(); ++i) cout<<minimum[i]<<" ";
            cout<<endl;
            for(int i=0; i<maximum.size(); ++i) cout<<maximum[i]<<" ";
            cout<<endl;
            */
        }
        
        return ans;
    }
    
   bool isInRange(vector<int>& nums, deque<int>& dq, int cur)
   {
       if(dq.empty()) return true;
       
       int diff=abs(nums[dq.front()]-cur);
       return (0 <= diff) && (diff <= 2);
   }
};

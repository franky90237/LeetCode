//2022-06-06
//TLE
//time  : O((n-k)*k)
//space : O(1)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        
        int max_num, max_idx;
        find_max(nums,0,k-1,max_num,max_idx);
        res.push_back(max_num);
        
        int n=nums.size();
        for(int i=1; i<=n-k; ++i)
        {
            if(max_idx<i)
            {
                find_max(nums,i,k+i-1,max_num,max_idx);
            }
            else if(max_num<=nums[k+i-1])
            {
                max_num=nums[k+i-1];
                max_idx=k+i-1;
            }
            
            res.push_back(max_num);
        }
        
        return res;
    }
    
    void find_max(vector<int>& nums, int l, int r, int& max_num, int& max_idx)
    {
        max_num=nums[l];
        max_idx=l;
        for(int i=l+1; i<=r; ++i)
        {
            if(max_num<=nums[i])
            {
                max_num=nums[i];
                max_idx=i;
            }
        }
    }
};

//2022-06-06
//use map(balanced binary search tree)
//time  : O((n-k)*log(k))
//space : O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        
        map<int,int> window;
        for(int i=0; i<=k-1; ++i) ++window[nums[i]];
        res.push_back(window.rbegin()->first);
        
        //print(window);
        int n=nums.size();
        for(int i=1; i<=n-k; ++i)
        {
            if(window[nums[i-1]]>1) --window[nums[i-1]];
            else window.erase(nums[i-1]);
            
            ++window[nums[k+i-1]];
            res.push_back(window.rbegin()->first);
            
            //print(window);
        }
        
        return res;
    }
    
    void  print(map<int,int>& window)
    {
        for(auto& i:window) cout<<i.first<<" ";
        cout<<endl;
    }
};

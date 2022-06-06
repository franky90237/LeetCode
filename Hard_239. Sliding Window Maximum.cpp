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

//2022-06-06
//use deque
//time  : O((n)
//space : O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        
        deque<int> dq;
        
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            if(!dq.empty() && dq.front()<i-k+1) dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
            //print(dq);
        }
        
        return res;
    }
    
    void  print(deque<int> dq)
    {
        for(auto& i:dq) cout<<i<<" ";
        cout<<endl;
    }
};

//2022-06-06
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int> res;
        int left[n];
        int right[n];
        
        for(int i=0; i<=(n-1)/k; ++i)
        {
            for(int j=i*k; j<n && j<(i+1)*k; ++j)
            {
                if(j==i*k)
                {
                    left[j]=nums[j];
                    continue;
                }
                
                left[j]=max(left[j-1],nums[j]);
            }
        }
        
        for(int i=0; i<=(n-1)/k; ++i)
        {
            for(int j=(i+1)*k-1; j>=i*k; --j)
            {
                if(j>=n) continue;
                
                if(j==(i+1)*k-1 || j==n-1)
                {
                    right[j]=nums[j];
                    continue;
                }
                
                right[j]=max(right[j+1],nums[j]);
            }
        }
        
        //print(right,n);
        //print(left,n);
        
        for(int i=0; i<=n-k; ++i)
        {
            //int l=(i+k-1<n) ? i+k-1 : n-1;
            int l=i+k-1;
            int r=i;
            res.push_back(max(left[l],right[r]));
        }
        
        return res;
    }
    
    void print(int arr[], int n)
    {
        for(int i=0; i<n; ++i) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

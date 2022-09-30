//2022-09-29
//time  : O(nlog(k))
//space : O(k)
using pii = pair<int, int>;
class Solution
{
private:
    class comp
    {
     public:
        bool operator()(pii& a, pii& b)
        {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        }
    };
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int n=arr.size();
        if(k==n) return arr;
        
        priority_queue<pii, vector<pii>, comp> maxHeap;
        for(int i=0; i < n; ++i)
        {
            int diff=abs(arr[i]-x);
            if(maxHeap.size() < k)
            {
                maxHeap.push({diff, i});
            }
            else
            {                
                if(diff < maxHeap.top().first)
                {
                    maxHeap.pop();
                    maxHeap.push({diff, i});
                }
            }
        }
        
        vector<int> ans;
        while(!maxHeap.empty())
        {
            int idx=maxHeap.top().second;
            ans.push_back(arr[idx]);
            maxHeap.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//2022-09-30
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int l=0;
        int r=arr.size()-k;
        while(l < r)
        {
            int mid=l+(r-l)/2;
            
            if(x <= arr[mid])
            {
                r=mid;
            }
            else if(x >= arr[mid+k])
            {
                l=mid+1;
            }
            else
            {
                int diff_mid=abs(x-arr[mid]);
                int diff_midK=abs(x-arr[mid+k]);
                
                if(diff_mid <= diff_midK)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        
        vector<int> ans;
        for(int i=l; i<l+k; ++i)
        {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};

//2022-09-30
//time  : O(n-k)
//space : O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int l=0;
        int r=arr.size()-1;
        while(r-l+1 > k)
        {
            int diff_l=abs(x-arr[l]);
            int diff_r=abs(x-arr[r]);
            
            if(diff_l <= diff_r) --r;
            else ++l;
        }
        
        vector<int> ans;
        for(int i=l; i<l+k; ++i)
        {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};

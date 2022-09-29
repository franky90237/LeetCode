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

//time  : O(nlogk)
//space : O(n)
class Solution {
private:
    typedef pair<int,int> pair_int;
    struct valueCompare
    {
        bool operator()(const pair_int& up, const pair_int& down)
        {
            return up.second > down.second;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        
        //O(n)
        unordered_map<int,int> m;
        for(auto& i:nums) ++m[i];          
        
        //O(nlogk)
        priority_queue<pair_int,vector<pair_int>,valueCompare> min_heap;
        for(auto it=m.begin();it!=m.end();++it)
        {
            if(min_heap.size()<k) min_heap.emplace(it->first,it->second);
            else if(min_heap.top().second < it->second)
            {
                min_heap.pop();
                min_heap.emplace(it->first,it->second);
            }
        }
        
        //O(k)
        while(!min_heap.empty())
        {
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }
        
        return res;
    }
};

//build hash map with "key as num" and "value as frequency"
//create a vector as buckts with index as frequency and each bucket storing the num in that frequency
//iterate the vector from back(most freq.) to front(less freq.) to get the top k num
//time  : O(n)+O(n)+O(n)
//space : O(n)+O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //O(n)
        unordered_map<int,int> m;
        for(auto& i:nums) ++m[i];        
        
        //O(n)
        vector<vector<int>> buckets(nums.size()+1,vector<int>());
        for(auto it=m.begin(); it!=m.end(); ++it)
        {
            int freq=it->second;
            buckets[freq].push_back(it->first);
        }
        
        //O(n)
        vector<int> res;
        int freq=buckets.size()-1;
        while(k!=0 && freq!=0)
        {
            if(buckets[freq].size()!=0)
            {
                res.insert(res.end(),buckets[freq].begin(),buckets[freq].end());
                k-=buckets[freq].size();
            }
            
            --freq;            
        }
        
        return res;
    }
};

//2024-01-16
//time  : O(nlogk)
//space : O(n)
class item
{
public:        
    int val;
    int cnt;
    
    item() = default;
    
    item(int _val, int _cnt) : val(_val), cnt(_cnt) 
    {
        
    }
};

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> numCnt;
        for(int num : nums) ++numCnt[num];
        
        auto myComp = [](const item& a, const item& b)
        {
            return a.cnt > b.cnt;
        };
        
        priority_queue<item, vector<item>, decltype(myComp)> minHeap;        
                
        for (auto& it : numCnt)
        {
            int val=it.first;
            int cnt=it.second;
            minHeap.push(item(val, cnt));
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while (!minHeap.empty())
        {
            //cout << minHeap.top().val << " ";
            ans.push_back(minHeap.top().val);
            minHeap.pop();
        }
        
        return ans;
    }
};

//2024-01-16
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> numCnt;
        for(int num : nums) ++numCnt[num];
        
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto& it : numCnt)
        {
            int num=it.first;
            int cnt=it.second;
            bucket[cnt].push_back(num);
        }
        
        vector<int> ans;
        for(int i=n; k>0; --i)
        {
            while(!bucket[i].empty() && k > 0)
            {
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                --k;
            }            
        }
        
        return ans;
    }
};

//2024-01-16
//time  : O(log(n))
//space : O(n)
class item
{
public:        
    int val;
    int cnt;
    
    item() = default;
    
    item(int _val, int _cnt) : val(_val), cnt(_cnt) 
    {
        
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> numCnt;
        for (int num : nums) ++numCnt[num];
        
        vector<item> input;
        for(auto [val, cnt] : numCnt)
        {
            input.push_back(item(val, cnt));
        }
        
        int targetPos = input.size() - k;
        int pos = -1;
        int left = 0;
        int right = input.size() - 1;
        do
        {
            pos = quickSelect(input, left, right);
            if (pos < targetPos) left = pos + 1;
            else right = pos - 1;
        } while (pos != targetPos);
        
        vector<int> ans;
        for (int i = pos; i < input.size(); ++i)
        {
            ans.push_back(input[i].val);
        }
        
        return ans;        
    }
    
    int quickSelect(vector<item>& input, int left, int right)
    {	
        int mid = left + (right - left) / 2;
        swap(input[mid], input[right]);

        int swapIdx = left;
        for (; left <= right - 1; ++left)
        {
            if (input[left].cnt < input[right].cnt)
            {
                swap(input[swapIdx], input[left]);
                ++swapIdx;
            }
        }
        
        swap(input[swapIdx], input[right]);
        return swapIdx;
    }
};

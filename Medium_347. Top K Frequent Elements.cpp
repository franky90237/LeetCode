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

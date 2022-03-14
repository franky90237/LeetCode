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

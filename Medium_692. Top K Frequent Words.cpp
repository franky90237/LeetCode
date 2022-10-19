//2022-10-19
//time  : O(nlog(k))
//space : O(n)
class Solution 
{
private:
    /*struct item
    {
        int cnt;
        string word;
    };*/
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {        
        unordered_map<string, int> wordCnt;
        for(auto& word: words)
        {
            ++wordCnt[word];
        }
        
        auto comp = [] (const pair<int, string>& a, const pair<int, string>& b)
        {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> minHeap(comp);
        for(auto& it: wordCnt)
        {
            if(minHeap.size() < k)
            {
                minHeap.push({it.second, it.first});
            }
            else
            {
                if(it.second > minHeap.top().first || it.second == minHeap.top().first && it.first < minHeap.top().second)
                {
                    minHeap.pop();
                    minHeap.push({it.second, it.first});
                }
            }
        }
        
        vector<string> ans;
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

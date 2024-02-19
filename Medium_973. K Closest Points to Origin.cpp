//2024-02-19
//time  : O(nlog(k))
//space : O(k)
class Item
{
 public:
    int distance;
    vector<int> point;
    
    Item() = default;
    Item(int _distance, vector<int> _point) : distance(_distance), point(_point) { }     
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        auto comp = [](Item& a, Item& b)
        {
            return a.distance < b.distance;
        };
        priority_queue<Item, vector<Item>, decltype(comp)> maxHeap;
        
        for(auto& point : points)
        {
            int a = point[0];
            int b = point[1];
            int distance = a*a + b*b;
            
            Item item(distance, point);
            maxHeap.push(item);
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        vector<vector<int>> res;
        while(!maxHeap.empty())
        {
            res.push_back(maxHeap.top().point);
            maxHeap.pop();
        }
        
        return res;
    }
};

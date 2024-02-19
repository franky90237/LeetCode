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

//2024-02-19
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        quickSelect(points, k-1);
        
        vector<vector<int>> res;
        for(int i=0; i<k; ++i)
        {
            res.push_back(points[i]);            
        }
        
        return res;
    }
    
    void quickSelect(vector<vector<int>>& points, int k)
    {
        int left = 0;
        int right = points.size() - 1;
        int idx = -1;
        do
        {            
            idx = partition(points, left, right);
            //cout<<left<<" "<<right<<" | "<<idx<<endl;
            if(idx < k) left = idx + 1;
            else if(idx > k) right = idx - 1;
        } while(idx != k);
    }
    
    int partition(vector<vector<int>>& points, int left, int right)
    {
        int mid = left + (right-left)/2;
        swap(points[right], points[mid]);
        
        int targetD = getDistance(points[right]);
        int bigIdx = left;
        for(int i=left; i<=right-1; ++i)
        {
            int curD = getDistance(points[i]);
            if(curD < targetD) 
            {
                swap(points[bigIdx], points[i]);
                ++bigIdx;
            }
        }
        
        /*
        1 2 3 4 5
        4 5 1 2 3
        
        1 2 4 5 3        
        */        
        swap(points[bigIdx], points[right]);
        return bigIdx;
    }
    
    int getDistance(vector<int>& point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
};

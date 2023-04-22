//2023-04-22
//TLE
//time  : O(n*n)
//space : O(n)
class MedianFinder 
{
private:
    vector<int> nums;
    
public:
    MedianFinder()
    {
        
    }
    
    void addNum(int num)
    {
        nums.push_back(num);
    }
    
    double findMedian()
    {
        int n=nums.size();
        if(n == 0) return 0;
        
        
        if(n % 2 == 0)
        {
            return (quickSelect(0, n/2, n-1) + quickSelect(0, (n/2)-1, n-1)) / 2.0;
        }
        
        return quickSelect(0, n/2, n-1);
    }
    
    double quickSelect(int left, int target, int right)
    {
        int idx = partition(left, right);
        
        if(idx == target)
        {
            return nums[idx];
        }
        else if(idx > target)
        {
            return quickSelect(left, target, idx-1);
        }
        else
        {
            return quickSelect(idx+1, target, right);
        }
    }
    
    int partition(int left, int right)
    {
        int n=nums.size();
        swap(nums[left+(right-left)/2], nums[right]);
        
        
        for(int i=left; i<right; ++i)
        {
            if(nums[i] < nums[right])
            {
                swap(nums[left], nums[i]);
                ++left;
            }
        }
        
        swap(nums[left], nums[right]);
        return left;
    }
};

//2023-04-22
//timee  : O(nlog(n))
//space  : O(n)
class MedianFinder 
{
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    MedianFinder()
    {
        maxHeap.push(INT_MIN);
        minHeap.push(INT_MAX);
    }
    
    void addNum(int num)
    {
        if(maxHeap.size() <= minHeap.size())
        {
            if(num > minHeap.top())
            {
                int right = minHeap.top();
                minHeap.pop();
                maxHeap.push(right);
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }
        else
        {                    
            if(num < maxHeap.top())
            {
                int left = maxHeap.top();
                maxHeap.pop();
                minHeap.push(left);
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }
        }
    }
    
    double findMedian()
    {        
        if(maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

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

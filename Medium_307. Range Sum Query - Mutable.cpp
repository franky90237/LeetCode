//2024-03-04
//time  : O(nlog(n))
//space : O(n)
class NumArray 
{
private:
    vector<int> vals;
    vector<int> nodes;
    
    int lowbit(int i)
    {
        return i & (-i);
    }
    
public:
    NumArray(vector<int>& nums)
    {
        int n = nums.size();        
        
        nodes.resize(n+1, 0);
        for(int i = 0; i < n; ++i) 
        {
            add(i+1, nums[i]);
        }
        
        vals = nums;
    }
    
    void update(int index, int val) 
    {
        int diff = val - vals[index];  
        vals[index] = val;
        
        add(index+1, diff);
    }
    
    int sumRange(int left, int right)
    {
        return query(right+1) - query(left);
    }
    
    void add(int index, int val)
    {        
        while(index < nodes.size())
        {        
            nodes[index] += val;
            index += lowbit(index);
        }        
    }
    
    int query(int index)
    {
        int res = 0;        
        while(index > 0)
        {
            res += nodes[index];
            index -= lowbit(index);
        }
        
        return res;
    }        
};

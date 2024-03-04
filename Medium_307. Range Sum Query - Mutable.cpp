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

//2024-03-04
//time  : O(nlog(n))
//space : O(n)
class SegmentTree
{
private:
    vector<int> nodes;
    
public:
    SegmentTree(int n) : nodes(4*n, 0)
    {
        
    }
    
    void update(int cL, int cR, int target, int val, int cur)
    {
        if(cL == cR)
        {
            nodes[cur] = val;
            return;
        }
        
        int mid = cL + (cR - cL) / 2;
        if(target <= mid) update(cL, mid, target, val, 2*cur + 1);
        else update(mid+1, cR, target, val, 2*cur + 2);
        
        nodes[cur] = nodes[2*cur + 1] + nodes[2*cur + 2];
    }
    
    int query(int cL, int cR, int tL, int tR, int cur)
    {
        /*
           tL--------tR
              cL--cR
        
        */        
        if(tL <= cL && cR <= tR) return nodes[cur];
        
        /*
              tL--------tR
           cL-------------cR
           
               tL--------tR
           cL-------------cR
        
        */        
        int mid = cL + (cR - cL) / 2;
        if(tR <= mid) return query(cL, mid, tL, tR, 2*cur + 1);
        else if(tL > mid) return query(mid+1, cR, tL, tR, 2*cur + 2);
        else return query(cL, mid, tL, tR, 2*cur + 1) + query(mid+1, cR, tL, tR, 2*cur + 2);
    }
};

class NumArray 
{
private:
    SegmentTree st;    
    int n;
    
public:
    NumArray(vector<int>& nums) : st(nums.size()), n(nums.size())
    {        
        for(int i = 0; i < n; ++i)
        {
            st.update(0, n-1, i, nums[i], 0);
        }
    }
    
    void update(int index, int val) 
    {
        st.update(0, n-1, index, val, 0);
    }
    
    int sumRange(int left, int right)
    {
        return st.query(0, n-1, left, right, 0);
    }           
};

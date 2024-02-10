//2024-02-10
//time  : O(nlog(n)) for add, O(1) for count
//space : O(n)
class CountIntervals 
{
private:
    map<int, int> intervals;
    int cnt = 0;
    
public:
    CountIntervals() 
    {
        
    }
    
    void add(int left, int right) 
    {
        /*
        if(intervals.empty())
        {
            intervals[left]=right;
            cnt = right - left + 1;
            return;
        }
        */
        
        auto it = intervals.lower_bound(left);     
        if(it != intervals.begin()) it = prev(it);
        if(it != intervals.end() && !overlap(it->first, it->second, left, right)) it = next(it);
        
        int sum = 0;
        while(it != intervals.end() && overlap(it->first, it->second, left, right))
        {
            left=min(left, it->first);
            right=max(right, it->second);
            sum += it->second - it->first + 1;
            
            it = intervals.erase(it);
        }
        
        intervals[left]=right;
        cnt = cnt - sum + (right-left + 1);
    }
    
    int count() 
    {
        return cnt;
    }
    
    bool overlap(int l1, int r1, int l2, int r2)
    {
        if((l1 <= l2 && l2 <= r1) || (l2 <= l1 && l1 <= r2)) return true;
        return false;
    }
};

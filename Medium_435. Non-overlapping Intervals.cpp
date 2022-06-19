//2022-06-20
//TLE
class Solution 
{
private:
    struct Mycomp
    {
        bool operator()(vector<int>& a, vector<int>& b)
        {
            if(a[0]<b[0]) return true;
            else if(a[0]==b[0]) return a[1]<b[1];
            else return false;            
        }
    } comp;
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comp);
        
        return solve(0,0,intervals);
    }
    
    int solve(int pre, int now, vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        if(now>=n) return 0;
        
        if(pre!=now && Overlapping(pre,now,intervals))
        {
            int sum1=1+solve(pre, now+1, intervals);
            int sum2=1+solve(now, now+1, intervals);
            
            return min(sum1,sum2);
        }
        else
        {
            return solve(now, now+1, intervals);
        }
    }
    
    bool Overlapping(int pre, int now, vector<vector<int>>& intervals)
    {
        return (intervals[now][0]<intervals[pre][1]);
    }
};

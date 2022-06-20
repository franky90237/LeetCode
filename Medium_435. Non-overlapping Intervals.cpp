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

//2022-06-20
//MLE
//dp recursive
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
        
        int n=intervals.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,intervals,dp);
    }
    
    int solve(int pre, int now, vector<vector<int>>& intervals, vector<vector<int>>& dp)
    {
        int n=intervals.size();
        if(now>=n) return 0;
        if(pre!=now && dp[pre][now]!=-1) return dp[pre][now];
        
        int res;
        if(pre!=now && Overlapping(pre,now,intervals))
        {
            int sum1=1+solve(pre, now+1, intervals,dp);
            int sum2=1+solve(now, now+1, intervals,dp);
            
            res=min(sum1,sum2);
        }
        else
        {
            res=solve(now, now+1, intervals,dp);
        }
        
        dp[pre][now]=res;
        return res;
    }
    
    bool Overlapping(int pre, int now, vector<vector<int>>& intervals)
    {
        return (intervals[now][0]<intervals[pre][1]);
    }
};

//2022-06-20
//greedy
//time  : O(nlog(n))
//space : O(1)
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
        
        int n=intervals.size();
        
        int cnt=0;
        int pre_end=intervals[0][1];
        for(int i=1; i<n; ++i)
        {
            if(pre_end<=intervals[i][0])
            {
                pre_end=intervals[i][1];
            }
            else
            {
                pre_end=min(pre_end,intervals[i][1]);
                ++cnt;
            }
        }
        
        return cnt;
    }    
};

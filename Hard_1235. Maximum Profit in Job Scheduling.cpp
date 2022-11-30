//2022-11-26
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    int dp[50001];
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int n=startTime.size();
        
        vector<vector<int>> input;
        for(int i=0; i<n; ++i)
        {
            input.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(input.begin(), input.end());
        
        memset(dp, -1, sizeof(dp));
        //cout<<dp<<endl;
        return dfs(input, 0);
    }
    
    int dfs(vector<vector<int>>& input, int cur)
    {
        //cout<<cur<<endl;
        int n = input.size();
        
        if(cur >= n) return 0;        
        if(dp[cur] != -1) 
        {
            //cout<<cur<<" "<<dp[cur]<<endl;
            return dp[cur];
        }
        
        int idx = binarySearch(input, cur+1, input[cur][1]);
        //cout<<cur<<" "<<idx<<endl;
        int pick = input[cur][2] + dfs(input, idx);
        
        int notPick = dfs(input, cur+1);
        
        dp[cur] = max(pick, notPick);
        return dp[cur];
    }
    
    int binarySearch(vector<vector<int>>& input, int l, int target)
    {
        int r=input.size()-1;
        //if(l >= r) return r+1;
        
        while(l < r)
        {
            int m=l+(r-l)/2;
            if(target <= input[m][0]) r=m;
            else l=m+1;
        }
        
        if(target <= input[r][0]) return r;
        return r+1;
    }
    
    bool overlapping(vector<vector<int>>& input, int pre, int cur)
    {         
        if(pre == -1) return false;        
        return input[pre][1] > input[cur][0];
    }
};

//2022-11-30
//time  : O(n)
//space : O(n)
class Solution 
{
private:
    int dp[50001];
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int n=startTime.size();
        
        vector<vector<int>> input;
        for(int i=0; i<n; ++i)
        {
            input.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(input.begin(), input.end());
        
        memset(dp, -1, sizeof(dp));
        dp[n]=0;
        int ans=0;
        for(int i=n-1; i>=0; --i)
        {
            int idx=binarySearch(input, i+1, input[i][1]);
            int profit = input[i][2] + dp[idx];
            dp[i]=max(dp[i+1], profit);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }    
    
    int binarySearch(vector<vector<int>>& input, int l, int target)
    {
        int r=input.size()-1;
        //if(l >= r) return r+1;
        
        while(l < r)
        {
            int m=l+(r-l)/2;
            if(target <= input[m][0]) r=m;
            else l=m+1;
        }
        
        if(target <= input[r][0]) return r;
        return r+1;
    }
    
};

//2023-11-05
//time  : O(n+e)
//space : O(n+e)
class Solution 
{
private:
    vector<unordered_set<int>> graph;
    vector<vector<long long>> dp;
    
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        int n=values.size();
        
        graph.resize(n);                
        for(auto edge: edges)
        {
            int a=edge[0];
            int b=edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        
        dp.resize(n, vector<long long>(2, -1));
        return dfs(values, -1, 0, true);
    }
    
    long long dfs(vector<int>& values, int parent, int cur, bool getZero)
    {
        if(isLeaf(parent, cur))
        {
            if(!getZero) return values[cur];
            else return 0;
        }
        
        if(dp[cur][getZero] != -1) return dp[cur][getZero];
        
        long long sum=0;
        if(!getZero)
        {
            sum += (long long)values[cur];
            for(auto &next: graph[cur])
            {
                if(next == parent) continue;
                sum += dfs(values, cur, next, false);
            }
            
            dp[cur][getZero]=sum;
            return sum;
        }
        
        long long pick = (long long)values[cur];
        long long notPick = 0;
        for(auto &next: graph[cur])
        {
            if(next == parent) continue;
            pick += dfs(values, cur, next, true);
            notPick += dfs(values, cur, next, false);            
        }
        
        dp[cur][getZero] = max(pick, notPick);
        return dp[cur][getZero];
    }
    
    bool isLeaf(int parent, int cur)
    {
        if(graph[cur].size() == 1 && *(graph[cur].begin()) == parent) return true;
        return false;
    }
};

//2023-11-06
//time  : O(n+e)
//space : O(n+e)
class Solution 
{
private:
    vector<unordered_set<int>> graph;    
    
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        int n=values.size();
        
        graph.resize(n);                
        for(auto edge: edges)
        {
            int a=edge[0];
            int b=edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
                
        vector<long long> ans = dfs(values, -1, 0);
        return max(ans[0], ans[1]);
    }
    
    vector<long long> dfs(vector<int>& values, int parent, int cur)
    {
        if(isLeaf(parent, cur))
        {
            return {values[cur], 0, values[cur], false};
        }
        
        vector<long long> res{values[cur], 0, values[cur], true};
        for(auto& next: graph[cur])
        {
            if(next == parent) continue;
            vector<long long> tmp = dfs(values, cur, next);
            if(tmp[3] == true)
            {
                res[0] += max(tmp[0], tmp[1]);
                res[1] += tmp[2];
                res[2] += tmp[2];
            }
            else
            {
                res[0] += tmp[1];
                res[1] += tmp[0];
                res[2] += tmp[2];
            }
        }
        
        return res;
    }
    
    bool isLeaf(int parent, int cur)
    {
        if(graph[cur].size() == 1 && *(graph[cur].begin()) == parent) return true;
        return false;
    }
};

//2023-11-06
//time  : O(n+e)
//space : O(n+e)
class Solution 
{
private:
    vector<unordered_set<int>> graph;    
    vector<vector<long long>> dp;
    
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        int n=values.size();
        
        graph.resize(n);                
        for(auto edge: edges)
        {
            int a=edge[0];
            int b=edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        
        dp.resize(n, vector<long long>(2, -1));
        return dfs(values, -1, 0, false);
    }
    
    long long dfs(vector<int>& values, int parent, int cur, bool isHealthy)
    {
        if(isLeaf(parent, cur))
        {
            return isHealthy ? values[cur] : 0;
        }
        if(dp[cur][isHealthy] != -1) return dp[cur][isHealthy];
        
        long long taken=values[cur];
        long long notTaken=0;
        for(auto& next: graph[cur])
        {
            if(next == parent) continue;
            taken += dfs(values, cur, next, isHealthy);
            if(!isHealthy) notTaken += dfs(values, cur, next, true);
        }
        
        dp[cur][isHealthy] = max(taken, notTaken);
        return dp[cur][isHealthy];
    }
    
    bool isLeaf(int parent, int cur)
    {
        if(graph[cur].size() == 1 && *(graph[cur].begin()) == parent) return true;
        return false;
    }
};

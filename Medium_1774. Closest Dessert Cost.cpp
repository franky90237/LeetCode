//2024-03-01
//time  : O(n*m^3)
//sapce : O(m)
class Solution 
{
private:
    int res = -1e9;
    
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {        
        for (int i = 0; i < baseCosts.size(); ++i)
        {
            solve(toppingCosts, 0, baseCosts[i], target);            
        }
        
        return res;
    }
    
    void solve(vector<int>& top, int i, int cur, int target)
    {
        //cout << i << " : " << cur << endl;        
        if(abs(target - cur) < abs(target-res) || (cur < res && abs(target - cur) == abs(target-res))) res = cur;    
        
        int n = top.size();
        if (cur >= target || i >= n) return;                       

        solve(top, i + 1, cur, target);
        solve(top, i + 1, cur + top[i], target);
        solve(top, i + 1, cur + 2 * top[i], target);       
    }    
};

//2024-03-01
//time  : O(m*maxSum)
//sapce : O(m*maxSum)
class Solution 
{
private:
    unordered_map<int, unordered_map<int, int>> table;
    
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        int res = -1e9;
        for (int i = 0; i < baseCosts.size(); ++i)
        {
            int sum = solve(toppingCosts, 0, baseCosts[i], target);
            //cout << sum << endl;		
            if (abs(target - sum) < abs(target - res)) res = sum;
            else if(sum < res && abs(target - sum) <= abs(target - res)) res = sum;
        }
        
        return res;
    }
    
    int solve(vector<int>& top, int i, int cur, int target)
    {
        //cout << i << " : " << cur << endl;
        int n = top.size();
        if (cur >= target) return cur;
        if (i >= n) return cur;
        if (table.find(cur) != table.end() && table[cur].find(target) != table[cur].end())
        {
            //cout << i << " : " << cur << endl; 
            return table[cur][target];
        }

        int notTake = solve(top, i + 1, cur, target);
        int take1 = solve(top, i + 1, cur + top[i], target);
        int take2 = solve(top, i + 1, cur + 2 * top[i], target);

        int diff1 = abs(target - notTake);
        int diff2 = abs(target - take1);
        int diff3 = abs(target - take2);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({ diff1, notTake });
        pq.push({ diff2, take1 });
        pq.push({ diff3, take2 });

        //cout << i << " : " << notTake << " " << take1 << " " << take2 << endl;
        table[i][cur] = pq.top()[1];
        return pq.top()[1];
    }    
};

//2024-03-02
//time  : O(n*target)
//space : O(n*target)
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {                        
        int n = toppingCosts.size();    
        vector<vector<int>> dp(n+1, vector<int>(target + 1, 1e9));        
        for(int sum = 0; sum<=target; ++sum) dp[n][sum] = sum;
                
        for(int i = n - 1; i >= 0; --i)
        {
            for(int sum = target; sum >= 0; --sum)
            {
                int notTake = dp[i+1][sum];
                int take1 = (sum + toppingCosts[i] >= target) ? sum + toppingCosts[i] : dp[i+1][sum + toppingCosts[i]];
                int take2 = (sum + 2*toppingCosts[i] >= target) ? sum + 2*toppingCosts[i] : dp[i+1][sum + 2*toppingCosts[i]];
                
                if(close(notTake, dp[i][sum], target)) dp[i][sum] = notTake;
                if(close(take1, dp[i][sum], target)) dp[i][sum] = take1;
                if(close(take2, dp[i][sum], target)) dp[i][sum] = take2;
            }
        }
        
        int res = 1e9;
        for(int base : baseCosts)
        {
            if(base >= target)
            {
                if(close(base, res, target)) res = base;
                continue;
            }
            
            if(close(dp[0][base], res, target)) res = dp[0][base];
        }
        
        /*        
        for(int i = 0; i <= n; ++i)
        {
            for(int sum = 0; sum <= target; ++sum) cout<<dp[i][sum]<<" "; cout<<endl;                             
        }
        */
        
        return res;
    }
    
    bool close(int a, int b, int target)
    {
        if(abs(target - a) < abs(target - b)) return true;
        if(a < b && abs(target - a) == abs(target - b)) return true;
        return false;
    }
};

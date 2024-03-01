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

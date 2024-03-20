//2024-03-20
//time  : O(n*n*len)
//sapce : O(n + d*len)
class Solution 
{
private:
    unordered_set<string> table;
    vector<int> dp;
    
public:    
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        for (string& st : dictionary) table.insert(st);

        int n = s.size();
        dp.resize(n, -1);
        return f(s, 0);        
    }
    
    int f(string& s, int i)
    {
        int n = s.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int skip = f(s, i + 1) + 1;

        string cur;
        int notSkip = n;
        for (int j = i; j < n; ++j)
        {
            cur.push_back(s[j]);
            if (table.count(cur) == 0) continue;

            notSkip = min(notSkip, f(s, j + 1));
        }
        
        return dp[i] = min(skip, notSkip);
    }
};

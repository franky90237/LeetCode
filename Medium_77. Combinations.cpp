class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(1,n,k,res,tmp);
        
        return res;
    }
    
    void solve(int begin, int n, int k, vector<vector<int>>& res, vector<int>& tmp)
    {
        if(tmp.size()==k)
        {
            res.emplace_back(tmp);
            return; 
        }
        
        for(int i=begin; i<=n; ++i)
        {
            //cout<<i<<endl;
            tmp.emplace_back(i);
            solve(i+1,n,k,res,tmp);
            tmp.pop_back();
        }
        
        //cout<<endl;
    }
};

/*class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<vector<int>>> cache[n+1];
        
        for(int i=1; i<=n; ++i) 
        {
            for(int j=1; j<=i; ++j)
            {
                vector<vector<int>> tmp;
                cache[i].emplace_back(tmp);
            }
        }
        
        solve(n,k,cache);        
        return cache[n][k];
    }
    
    void solve(int n, int k, vector<vector<vector<int>>> cache[])
    {
        if(!cache[n][k].empty()) return;
        
        
    }
    
    void print(int m, int p, int arr[][p])
    {
        int i, j;
        for (i = 0; i < m; i++)
          for (j = 0; j < p; j++)
            printf("%d ", arr[i][j]);
    }
};*/

//2023-12-02
//time  : O(C(n, k))
//space : O(n)
class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> cur;
    
public:
    vector<vector<int>> combine(int n, int k) 
    {
        solve(n, k, 1);
        return ans;
    }
    
    void solve(int maxVal, int k, int curVal)
    {
        if(k == 0)
        {
            ans.push_back(cur);
            return;
        }
        
        if(curVal > maxVal)
        {
            return;
        }
        
        for(int nxtVal=curVal; nxtVal<=maxVal; ++nxtVal)
        {
            cur.push_back(nxtVal);
            solve(maxVal, k-1, nxtVal+1);
            cur.pop_back();
        }
    }
};

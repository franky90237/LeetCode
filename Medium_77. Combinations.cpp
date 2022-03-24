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

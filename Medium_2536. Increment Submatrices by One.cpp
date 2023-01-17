//2023-01-15
//slower
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<pair<int, int>>> rows(n);
        
        for(auto& q: queries)
        {
            int r1=q[0];
            int r2=q[2];
            int c1=q[1];
            int c2=q[3];
            
            for(int r=r1; r<=r2; ++r)
            {                
                rows[r].push_back({c1, c2});
            }
        }
        
        for(int r=0; r<n; ++r)
        {            
            sort(rows[r].begin(), rows[r].end());
            change(ans, rows[r], r);            
        }
            
        return ans;
    }
    
    void change(vector<vector<int>>& ans, vector<pair<int, int>>& row, int r)
    {
        int n=ans.size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;        
        
        int k=0;
        int num=0;
        
        for(int i=0; i<n; ++i)
        {
            //cout<<i<<" "<<k<<" "<<num<<endl;
            while(k < row.size() && i == row[k].first)
            {                
                ++num;
                minHeap.push(row[k].second);
                ++k;
            }                       
            
            ans[r][i] += num;
            
            while(!minHeap.empty() && i == minHeap.top())
            {
                --num;                            
                minHeap.pop();                                
            }                                   
        }
    }
};

//2023-01-17
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for(auto& q: queries)
        {
            int r1=q[0];
            int r2=q[2];
            int c1=q[1];
            int c2=q[3]+1;            
            
            for(int r=r1; r<=r2; ++r)
            {
                ans[r][c1] += 1;
                if(c2 < n) ans[r][c2] -= 1;
            }
        }
        
        for(int r=0; r<n; ++r)
        {
            for(int c=1; c<n; ++c)
            {
                ans[r][c] = ans[r][c] + ans[r][c-1];
            }
        }
        
        return ans;
    }
};

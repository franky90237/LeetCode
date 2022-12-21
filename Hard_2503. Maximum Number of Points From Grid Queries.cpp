class Solution {
private:
    vector<vector<bool>> done;
    vector<vector<bool>> vis;
    queue<pair<int, int>> node;

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {        
        vector<pair<int, int>> item;
        for(int i=0; i<queries.size(); ++i)
        {
            item.push_back({queries[i], i});
        }
        
        sort(item.begin(), item.end());
        
        int m=grid.size();
        int n=grid[0].size();
        
        done.resize(m, vector<bool>(n, false));
        vis.resize(m, vector<bool>(n, false));
        
        //queue<pair<int, int>> node;
        node.push({0, 0});
        
        vector<int> ans(item.size(), 0);
        int threshold=grid[0][0];
        for(int i=0; i<item.size(); ++i)
        {
            //cout<<i<<" | "<<item[i].first<<" "<<item[i].second<<endl;
            if(i != 0 && (item[i].first == item[i-1].first || item[i].first <= threshold)) 
            {
                ans[i]=ans[i-1];
                continue;
            }
            
            int cnt = (i==0) ? 0 : ans[i-1];
            int val=item[i].first;
            
            int size=node.size();
            while(size > 0)
            {
                int r=node.front().first;
                int c=node.front().second;
                node.pop();
                done[r][c]=false;
                vis[r][c]=false;
                cnt += dfs(grid, r, c, val, threshold);
                
                --size;
            }
            
            //cout<<i<<" "<<cnt<<" | "<<node.size()<<endl;            
            //print_queue(node);
            
            //if(cnt == 0)
            {
                //break;
            }
            
            ans[i]=cnt;
        }
        
        //cout<<"----------"<<endl;
        vector<int> res(item.size());
        for(int i=0; i<item.size(); ++i)
        {                 
            int idx=item[i].second;            
            res[idx]=ans[i];
        }
        
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c, int val, int threshold)
    {
        //cout<<r<<", "<<c<<endl;
        int m=grid.size();
        int n=grid[0].size();
        
        if(r < 0 || r >= m || c < 0 || c >= n || vis[r][c] || done[r][c])
        {            
            return 0;
        }
        
        done[r][c]=true;
        vis[r][c]=true;
        
        //cout<<r<<", "<<c<<" | "<<grid[r][c]<<" "<<val<<endl;
        if(grid[r][c] >= val)
        {
            threshold=min(threshold, grid[r][c]);
            node.push({r, c});            
            return 0;
        }               
                
        int up=dfs(grid, r-1, c, val, threshold);
        int down=dfs(grid, r+1, c, val, threshold);
        int left=dfs(grid, r, c-1, val, threshold);
        int right=dfs(grid, r, c+1, val, threshold);
        
        //vis[r][c]=false;
        
        return 1+up+down+left+right;
    }
    
    void print_queue(queue<pair<int, int>> q)
    {        
        while(!q.empty())
        {
            cout<<"("<<q.front().first<<", "<<q.front().second<<") ";
            q.pop();
        }        
        cout<<endl;        
    }
};

//2022-12-21
//time  : O(k + m*n)
//space : O(m*n + k)
class union_find
{
private:
    vector<int> parent;
    vector<int> size;
    
public:
    union_find(int n)
    {
        for(int i=0; i<n; ++i)
        {
            parent.push_back(i);
        }
        
        size.resize(n, 1);
    }
    
    void combine(int a, int b)
    {
        int root_a=find(a);
        int root_b=find(b);
        //if(a == 3 && b == 0) cout<<root_a<<" "<<root_b<<endl;
        if(root_a == root_b) return;
        
        if(size[root_a] <= size[root_b])
        {
            parent[root_a]=root_b;
            size[root_b] += size[root_a];
        }
        else
        {
            parent[root_b]=root_a;
            size[root_a] += size[root_b];            
        }
    }
    
    int find(int a)
    {
        if(parent[a] == a) return a;
                
        parent[a]=find(parent[a]);
        //size[a]=1;
        return parent[a];
    }
    
    int get_size(int a)
    {
        int root_a=find(a);
        
        return size[root_a];
    }
    
    void print()
    {
        for(int i=0; i<parent.size(); ++i)
        {
            cout<<i<<" : ";
            cout<<parent[i]<<", ";
            cout<<size[i]<<endl;            
        }
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> nums;
        for(int r=0; r<m; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                nums.push_back({grid[r][c], r, c});
            }
        }
        sort(nums.begin(), nums.end());
        
        /*for(int i=0; i<m*n; ++i)
        {
            cout<<nums[i][0]<<" ";
        }
        cout<<endl;*/
        
        int k=queries.size();
        vector<vector<int>> queries_sorting(k);
        for(int i=0; i<k; ++i)
        {
            queries_sorting[i]={queries[i], i};
        }
        sort(queries_sorting.begin(), queries_sorting.end());                
        
        int dir[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        union_find uf(m*n);
        int idx=0;
        vector<int> ans(k, 0);
        for(int i=0; i<k; ++i)
        {   
            //cout<<i<<" | "<<queries_sorting[i][0]<<endl;   
            int val=queries_sorting[i][0];
            if(grid[0][0] >= val) continue;
            
            while(idx < m*n && nums[idx][0] < val)
            {
                //cout<<idx<<" : "<<nums[idx][0]<<" | ";
                int r=nums[idx][1];
                int c=nums[idx][2];
                for(int i=0; i<4; ++i)
                {
                    int nr=r+dir[i][0];
                    int nc=c+dir[i][1];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] >= val) continue;
                    
                    //cout<<"("<<nr<<", "<<nc<<", "<<grid[nr][nc]<<")"<<endl;
                    uf.combine(r*n+c, nr*n+nc);
                    //uf.print();
                    //cout<<endl;
                }
                //cout<<endl;
                ++idx;
            }
                      
            ans[queries_sorting[i][1]]=uf.get_size(0);
        }
        
        //uf.print();
        return ans;
    }
};

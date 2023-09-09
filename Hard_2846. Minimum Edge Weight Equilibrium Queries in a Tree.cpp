//2023-09-09
//time  : O(nlog(n))
//space : O(nlog(n))
class Solution 
{
private:
    vector<vector<int>> weightCnt;
    vector<vector<int>> kthTarget;
    int k;
    
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        k=ceil(log2(n))+1;
        build(n, edges);
        
        //cout<<"**"<<queries.size()<<endl;
        //int x=0;
        vector<int> ans;
        for(auto q: queries)
        {
            //cout<<x<<" | "<<q[0]<<" "<<q[1]<<endl;
            int a=q[0];
            int b=q[1];
            int mid=lca(a, b);
            //cout<<x++<<endl;
            //cout<<a<<" "<<mid<<" "<<b<<endl;
            
            int maxCnt=0;
            int total=0;
            for(int i=0; i<27; ++i)
            {
                int cnt=weightCnt[a][i]+weightCnt[b][i]-2*weightCnt[mid][i];
                maxCnt=max(maxCnt, cnt);
                total+=cnt;
            }
            
            ans.push_back(total-maxCnt);
        }
        
        return ans;
    }
    
    int lca(int a, int b)
    {
        //int oa=a, ob=b;
        //if(oa == 0 && ob == 20) cout<<a<<" "<<b<<" | "<<level(a)<<" "<<level(b)<<endl;
        if(level(a) < level(b)) moveUp(b, level(b)-level(a));
        else if(level(a) > level(b)) moveUp(a, level(a)-level(b));
        if(a == b) return a;
        //if(oa == 0 && ob == 20) cout<<a<<" "<<b<<endl;
        //if(oa == 0 && ob == 20) cout<<"pre processing done!"<<endl;
        
        for(int step=k-1; step>=0; --step)
        {
            int pA=kthTarget[step][a];
            int pB=kthTarget[step][b];
            if(pA == pB) continue;
            a=kthTarget[step][a];
            b=kthTarget[step][b];
        }
        
        return kthTarget[0][a];
    }
    
    int level(int a)
    {
        int cnt=0;
        for(int i=0; i<27; ++i)
        {
            cnt += weightCnt[a][i];
        }
        
        return cnt;
    }
    
    void moveUp(int& a, int val)
    {
        int oa=a;
        int cnt=ceil(log2(val))+1;
        for(int i=0; i<cnt; ++i)
        {
            //if(oa == 20 && val == 17) cout<<i<<" "<<((1>>i)&val)<<" | "<<a<<endl;
            if(((1<<i)&val) == 0) continue;            
            a=kthTarget[i][a];            
        }
    }
    
    void build(int n, vector<vector<int>>& edges)
    {
        vector<unordered_map<int, int>> tree(n);
        for(auto e: edges)
        {
            tree[e[0]][e[1]]=e[2];
            tree[e[1]][e[0]]=e[2];
        }
                
        weightCnt.resize(n, vector<int>(27, 0));
        kthTarget.resize(k, vector<int>(n, -1));
        vector<bool> vis(n, false);
        vector<int> weight(27, 0);
        dfs(tree, weight, vis, -1, 0);
        
        
        //cout<<"dfs done!"<<endl;
        /*for(int i=0; i<n; ++i)
        {
            cout<<i<<" : ";
            for(int x=0; x<27; ++x) if(weightCnt[i][x] != 0) cout<<"("<<x<<","<<weightCnt[i][x]<<") ";
            cout<<endl;
        }        
        */
        
        for(int step=1; step<k; ++step)
        {
            for(int i=0; i<n; ++i)
            {
                if(kthTarget[step-1][i] == -1) continue;
                kthTarget[step][i]=kthTarget[step-1][kthTarget[step-1][i]];
            }
        }
        
        
        //cout<<"kthTarget done!"<<endl;
        /*for(int step=0; step<k; ++step)
        {
            cout<<step<<" : ";
            for(int i=0; i<n; ++i) cout<<kthTarget[step][i]<<" ";
            cout<<endl;
        }
        */
    }
    
    void dfs(vector<unordered_map<int, int>>& tree, vector<int>& weight, vector<bool>& vis, int pre, int cur)
    {
        if(vis[cur]) return;
        vis[cur]=true;
        
        if(pre != -1) 
        {
            ++weight[tree[pre][cur]];
            for(int i=0; i<27; ++i) weightCnt[cur][i]=weight[i];            
        }
        kthTarget[0][cur]=pre;
        
        for(auto& it: tree[cur])
        {
            int neighbor=it.first;
            dfs(tree, weight, vis, cur, neighbor);
        }
        
        if(pre != -1) --weight[tree[pre][cur]];
        vis[cur]=false;
    }
};

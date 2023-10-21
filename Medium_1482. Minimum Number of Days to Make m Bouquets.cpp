//2023-10-21
//time  : O(nlog(n))
//space : O(n)
class UnionFind
{
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UnionFind(int n)
    {
        for(int i=0; i<n; ++i)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    void combine(int a, int b)
    {
        int rootA=find(a);
        int rootB=find(b);
        if(rootA == rootB) return;
        
        if(size[rootA] < size[rootB])
        {
            size[rootB] += size[rootA];
            parent[rootA] = rootB;
        }
        else
        {
            size[rootA] += size[rootB];
            parent[rootB] = rootA;            
        }
    }
    
    int find(int a)
    {
        if(a == parent[a]) return a;
        return parent[a]=find(parent[a]);
    }
    
    int getSize(int a)
    {
        int rootA=find(a);
        return size[rootA];
    }
};

class Solution 
{
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n=bloomDay.size();
        if(n/k < m) return -1;
        
        vector<int> idx(n);
        for(int i=0; i<n; ++i) idx[i]=i;
        sort(idx.begin(), idx.end(), [&bloomDay](int a, int b)
             {
                 return bloomDay[a] < bloomDay[b];
             });
        
        vector<bool> vis(n, false);
        UnionFind uf(n);
        int ans=0;
        for(int i=0; i<n; ++i)
        {
            vis[idx[i]]=true;
            
            int preSize1=0, preSize2=0;
            if(isValid(vis, idx[i] - 1)) 
            {
                preSize1=uf.getSize(idx[i]-1);
                uf.combine(idx[i], idx[i]-1);
            }
            if(isValid(vis , idx[i] + 1)) 
            {
                preSize2=uf.getSize(idx[i]+1);
                uf.combine(idx[i], idx[i]+1);
            }
            
            int preCnt = preSize1 / k + prenSize2 / k;
            int newSize = uf.getSize(idx[i]);
            int newCnt = newSize / k;
            ans += newCnt-preCnt;
            if(ans >= m) return bloomDay[idx[i]];
            //cout<<idx[i]<<" "<<bloomDay[idx[i]]<<" | "<<preSize1<<" "<<preSize2<<" "<<newSize<<" : "<<ans<<endl;
        }
        
        return -1;
    }
    
    bool isValid(vector<bool>& vis, int idx)
    {
        int n=vis.size();
        if(idx < 0 || idx >=n || !vis[idx]) return false;
        return true;
    }
};

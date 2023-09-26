//2023-09-26
//time  : O(n)
//space : O(n)
class unionFind
{
private:
    vector<int> parent;
    vector<int> size;
    
public:
    unionFind(int n)
    {
        for(int i=0; i<=n; ++i)
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
        if(parent[a] == a) return a;
        return parent[a]=find(parent[a]);
    }
    
    int getCnt(int a)
    {
        int rootA=find(a);
        return size[rootA];
    }
};

class Solution 
{
public:
    long long countPaths(int n, vector<vector<int>>& edges) 
    {        
        vector<bool> isPrime(n+1, true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2; i<=n; ++i)
        {
            if(!isPrime[i]) continue;
            
            long long cur=(long)i*i;
            while(cur <= n)
            {
                isPrime[cur]=false;
                cur += i;
            }
        }
                
        unionFind uf(n);
        vector<set<int>> graph(n+1);
        for(auto e: edges)
        {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
            if(!isPrime[e[0]] && !isPrime[e[1]]) uf.combine(e[0], e[1]);
        }
        
        //cout<<"starting! \n";
        long long ans=0;
        for(int i=2; i<=n; ++i)
        {
            if(!isPrime[i]) continue;
            
            long long sum=1;
            vector<int> subTreeNodesCnt;
            for(auto neighbor: graph[i])
            {
                if(isPrime[neighbor]) continue;
                
                int cnt=uf.getCnt(neighbor);
                subTreeNodesCnt.push_back(cnt);
                sum += cnt;                
                //cout<<i<<" : "<<neighbor<<" | "<<cnt<<endl;
            }
            
            for(auto nodesCnt: subTreeNodesCnt)
            {
                sum -= nodesCnt;
                ans += nodesCnt*sum;
            }
        }
        
        return ans;
    }        
};

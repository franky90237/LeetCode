//2024-01-27
//time  : O(v*v*log(e))
//space : O(v*v)
class UF
{
private:
    vector<int> parent;
    vector<int> size;
    
public:
    UF(int n)
    {
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i]=i;
        
        size.resize(n, 1);
    }
    
    bool combine(int a, int b)
    {
        int rootA=find(a);
        int rootB=find(b);
        //cout<<a<<" "<<b<<" | "<<rootA<<" "<<rootB<<endl;
        if(rootA == rootB) return false;
        
        if(size[rootA] < size[rootB])
        {
            parent[rootA]=rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            parent[rootB]=rootA;
            size[rootA] += size[rootB];
        }
        
        return true;
    }
    
    int find(int a)
    {
        //cout<<a<<" "<<parent[a]<<endl;
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    void print()
    {
        for(int i=0; i<parent.size(); ++i) cout<<find(i)<<" "; cout<<endl;
        //for(int i=0; i<parent.size(); ++i) cout<<parent[i]<<" "; cout<<endl;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();        
                        
        UF uf(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        buildMinHeap(points, minHeap);
        
        int edges=n-1;
        int res=0;
        while(edges > 0)
        {
            int val=minHeap.top()[0];
            int node1=minHeap.top()[1];
            int node2=minHeap.top()[2];
            minHeap.pop();
            
            if(uf.combine(node1, node2))
            {
                //cout<<node1<<" "<<node2<<" | "<<val<<endl;
                res += val;
                --edges;
            }                
        }
        
        //cout<<endl;
        return res;
    }
    
    void buildMinHeap(vector<vector<int>>& points, priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>& minHeap)
    {
        int n=points.size();
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                //if(i == j) continue;
                int val = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                minHeap.push({val, i, j});
            }
        }
        
        /*
        auto tmp = minHeap;
        while(!tmp.empty())
        {
            cout<<tmp.top()[1]<<" "<<tmp.top()[2]<<" : "<<tmp.top()[0]<<endl;
            tmp.pop();
        }
        cout<<endl;
        */
    }
};

//2024-01-27
//time  : O(v*v*log(e))
//space : O(v*v)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();        
                
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;        
        for(int i=1; i<n; ++i) minHeap.push({getVal(points[0], points[i]), 0, i});        
        
        vector<bool> vis(n, false);
        vis[0]=true;
        
        int edges=n-1;
        int res=0;
        while(edges > 0)
        {
            int val=minHeap.top()[0];
            int p1=minHeap.top()[1];
            int p2=minHeap.top()[2];
            minHeap.pop();
            
            if(vis[p2]) continue;
            vis[p2]=true;
            
            res += val;                  
            
            for(int i=0; i<n; ++i)
            {
                if(vis[i]) continue;
                minHeap.push({getVal(points[p2], points[i]), p2, i});
            }
            
            --edges;
        }
        
        //cout<<endl;
        return res;
    }
    
    int  getVal(vector<int>& p1, vector<int>& p2)
    {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};

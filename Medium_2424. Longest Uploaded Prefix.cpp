//2023-12-08
//time  : O(n)
//spsace : O(n)
class UnionFind
{
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind() = default;
    
    UnionFind(int n) : parent(n), size(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    void combine(int a, int b)
    {
        int rootA=find(a);
        int rootB=find(b);
        if(rootA == rootB) return;

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
    }

    int find(int a)
    {
        if(a == parent[a]) return a;
        return parent[a]=find(parent[a]);
    }

    int getSize(int a)
    {
        int parent=find(a);
        return size[parent];
    }
};

class LUPrefix 
{
private:
    int maxNumber;
    vector<bool> used;
    UnionFind uf;

public:
    LUPrefix(int n) : maxNumber(n), used(n+1, false), uf(n+1)
    {

    }
    
    void upload(int video) 
    {
        //cout<<video<<endl;
        if(video-1 >= 0 && used[video-1]) uf.combine(video, video-1);
        if(video+1 <= maxNumber && used[video+1]) uf.combine(video, video+1);
        used[video]=true;
    }
    
    int longest() 
    {
        //cout<<"longest"<<endl;
        if(!used[1]) return 0;        
        return uf.getSize(1);
    }
};

//203-12-08
//time  : O(n)
//space : O(n)
class LUPrefix 
{
private:
    unique_ptr<bool[]> used;
    int cur=1;

public:
    LUPrefix(int n)
    {
        used=make_unique<bool[]>(n+2);        
    }
    
    void upload(int video) 
    {
        used[video]=true;
    }
    
    int longest() 
    {
        if(!used[1]) return 0;
        while(used[cur])
        {
            ++cur;
        }

        return cur-1;
    }
};

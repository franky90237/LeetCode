//2023-09-06
//time  : O(nlog(n))
//space : O(nlog(n))
class TreeAncestor 
{
private:
    vector<vector<int>> dst;
    int cnt;
    
public:
    TreeAncestor(int n, vector<int>& parent) 
    {
        cnt=ceil(log2(n))+1;
        dst.resize(cnt, vector<int>(n , -1));
        for(int i=0; i<n; ++i) dst[0][i]=parent[i];
        for(int i=1; i<cnt; ++i)
        {
            for(int x=0; x<n; ++x)
            {
                if(dst[i-1][x] == -1) continue;
                dst[i][x]=dst[i-1][dst[i-1][x]];
            }
        }
        
        /*
        for(int i=0; i<cnt; ++i) 
        {
            cout<<i<<" : ";
            for(int x=0; x<n; ++x) cout<<dst[i][x]<<" "; 
            cout<<endl;
        }
        */
    }
    
    int getKthAncestor(int node, int k) 
    {
        int res=node;        
        for(int i=0; i<cnt; ++i)
        {
            if(((k>>i)&1) == 0) continue;
            
            res=dst[i][res];            
            if(res == -1) break;
        }
        
        return res;
    }
};

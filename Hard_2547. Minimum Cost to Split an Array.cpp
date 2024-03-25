//2024-03-25
//time  : O(nlog(n))
//space : O(n)
class SegmentTree
{
private:
    vector<int> nodes;
    vector<int> extra;
    
    bool overlap(int a, int b, int c, int d)
    {
        /*
            c-----d
               a------b
        */
        if(a <= c && c <= b) return true;
        if(c <= a && a <= d) return true;
        return false;
    }
    
    void store(int idx, int val)
    {
        nodes[idx] += val;
        extra[idx] += val;
    }
    
    void propagate(int idx)
    {
        if(extra[idx] == 0) return;
                
        store(2*idx+1, extra[idx]);
        store(2*idx+2, extra[idx]);
        extra[idx] = 0;
    }
    
public:
    SegmentTree(int n) : nodes(4*n, 0), extra(4*n, 0)
    {
        
    }
    
    void update(int cL, int cR, int tL, int tR, int idx, int val)
    {        
        if(tL > tR) return;
        if(!overlap(cL, cR, tL, tR)) return;
        if(tL <= cL && cR <= tR)
        {
            //if(tL == tR) cout<<tL<<" | "<<cL<<" "<<cR<<endl;
            store(idx, val);
            return;
        }
        
        propagate(idx);
        
        /*
        
         cL------------cR
              tL---tR
        */
        
        int mid=cL+(cR-cL)/2;
        update(cL, mid, tL, tR, 2*idx+1, val);
        update(mid+1, cR, tL, tR, 2*idx+2, val);
        nodes[idx] = min(nodes[2*idx+1], nodes[2*idx+2]);
    }
    
    int query(int cL, int cR, int tL, int tR, int idx)
    {        
        if(!overlap(cL, cR, tL, tR)) return INT_MAX;
        if(tL <= cL && cR <= tR) return nodes[idx];        
        
        propagate(idx);
        int mid=cL+(cR-cL)/2;
        return min(query(cL, mid, tL, tR, 2*idx+1), query(mid+1, cR, tL, tR, 2*idx+2));
    }
    
    void print(int left, int right)
    {
        //for(int i=0; i<nodes.size(); ++i) cout<<nodes[i]<<" "; cout<<endl;
        //for(int i=0; i<extra.size(); ++i) cout<<extra[i]<<" "; cout<<endl;
        for(int i=left; i<=right; ++i) cout<<query(left, right, i, i, 0)<<" "; cout<<endl;
    }
};

class Solution {
public:
    int minCost(vector<int>& nums, int k) 
    {
        int n=nums.size();
        
        SegmentTree st(n);               
        
        vector<int> f(n+1, 0);
        vector<int> last1(n+1, -1);
        vector<int> last2(n+1, -1);
                
        for(int i=1; i<=n; ++i)
        {
            int val=nums[i-1];
            //cout<<nums[i-1]<<" | "<<last2[val]<<" "<<last1[val]<<endl;
            
            st.update(0, n-1, last2[val]+1, last1[val], 0, 2);
            st.update(0, n-1, 0, last2[val], 0, 1);
            
            st.update(0, n-1, i-1, i-1, 0, f[i-1]+k);
            f[i] = st.query(0, n-1, 0, i-1, 0);        
            
            last2[val] = last1[val];
            last1[val] = i-1;
            
            //cout<<f[i-1]<<endl;            
            //st.print(0, n-1);
        }
        
        return f[n];
    }
};

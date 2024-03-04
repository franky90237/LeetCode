//2024-03-04
//time  : O(nlog(n))
//space : O(n)
class SegmentTree
{
private:
    vector<int> nodes;
    int n;
    
public:
    SegmentTree(int _n) : nodes(4*_n, 0), n(_n)
    {
        
    }
    
    void update(int target, int val)
    {
        update(0, n-1, target, val, 0);
    }
    
    int query(int left, int right)
    {
        if(left > right) return 0;
        return query(0, n-1, left, right, 0);
    }
    
    void update(int cL, int cR, int target, int val, int cur)
    {
        if(cL == cR)
        {
            nodes[cur] += val;
            return;
        }
        
        int mid = cL + (cR - cL) / 2;
        if(target <= mid) update(cL, mid, target, val, 2*cur + 1);
        else update(mid+1, cR, target, val, 2*cur + 2);
        
        nodes[cur] = nodes[2*cur + 1] + nodes[2*cur + 2];
    }
    
    int query(int cL, int cR, int tL, int tR, int cur)
    {
        /*
           tL--------tR
              cL--cR
        
        */        
        if(tL <= cL && cR <= tR) return nodes[cur];
        
        /*
              tL--------tR
           cL-------------cR
           
               tL--------tR
           cL-------------cR
        
        */        
        int mid = cL + (cR - cL) / 2;
        if(tR <= mid) return query(cL, mid, tL, tR, 2*cur + 1);
        else if(tL > mid) return query(mid+1, cR, tL, tR, 2*cur + 2);
        else return query(cL, mid, tL, tR, 2*cur + 1) + query(mid+1, cR, tL, tR, 2*cur + 2);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) 
    {
        map<int, int> mapping;
        for(int num : nums) mapping[num] = 0;
        
        int idx = 0;
        for(auto& it : mapping) 
        {            
            it.second = idx;
            ++idx;
        }
                        
        vector<int> arrL{nums[0]};
        vector<int> arrR{nums[1]};
        
        int n = mapping.size();
        SegmentTree stL(n);
        SegmentTree stR(n);
        
        stL.update(mapping[nums[0]], 1);
        stR.update(mapping[nums[1]], 1);
        
        //for(int i = 0; i < n; ++i) cout<<stL.query(i, i)<<" "; cout<<endl;
        //for(int i = 0; i < n; ++i) cout<<stR.query(i, i)<<" "; cout<<endl;
        //cout<<nums.size()<<" "<<mapping.size()<<endl;
        
        for(int i = 2; i < nums.size(); ++i)
        {
            int cntL = stL.query(mapping[nums[i]]+1, n-1);
            int cntR = stR.query(mapping[nums[i]]+1, n-1);
            
            //cout<<nums[i]<<" "<<mapping[nums[i]]<<" | "<<cntL<<" "<<cntR<<endl;
            //for(int i : arrL) cout<<i<<" "; cout<<endl;
            //for(int i : arrR) cout<<i<<" "; cout<<endl<<endl;            
            
            if(cntL < cntR || (cntL == cntR && arrL.size() > arrR.size()))
            {
                stR.update(mapping[nums[i]], 1);
                arrR.push_back(nums[i]);
            }
            else
            {
                stL.update(mapping[nums[i]], 1);
                arrL.push_back(nums[i]);                
            }                        
        }
        
        //for(int i : arrL) cout<<i<<" "; cout<<endl;
        //for(int i : arrR) cout<<i<<" "; cout<<endl;
        
        arrL.insert(arrL.end(), arrR.begin(), arrR.end());
        return arrL;
    }
};

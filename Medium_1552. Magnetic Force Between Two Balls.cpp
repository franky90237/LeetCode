//2022-12-29
//time  : O(nlog(1e9))
//space : O(1)
class Solution {
public:
    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());
        
        int l=1;
        int r=position.back()-position[0];
        int ans=r;
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            if(check(position, m, mid))
            {
                ans=mid;
                l=mid+1;                
            }
            else
            {
                r=mid-1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& position, int m, int target)
    {
        //cout<<"**"<<target<<endl;
        --m;
        
        int i=0;
        int cur=position[0];
        while(m > 0)
        {
            int nxt=cur+target;
            auto it=lower_bound(position.begin()+i, position.end(), nxt);
            if(it == position.end()) 
            {
                //cout<<endl;
                return false;
            }
            
            i=it-position.begin();
            cur=*it;
            --m;
            
            //cout<<i<<" ";
        }
        
        //cout<<endl;
        return true;
    }
};

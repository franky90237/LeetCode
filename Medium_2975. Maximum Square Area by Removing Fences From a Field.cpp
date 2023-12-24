//2023-12-24
//time  : O(len*len)
//space : O(len*len)
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) 
    {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        int x=hFences.size();
        int y=vFences.size();
        
        unordered_set<int> diffH;
        for(int i=0; i<x; ++i)
        {
            for(int k=i+1; k<x; ++k) 
            {
                //cout<<hFences[k]-hFences[i]<<endl;
                diffH.insert(hFences[k]-hFences[i]);
            }
        }
        
        unordered_set<int> diffV;
        for(int i=0; i<y; ++i)
        {
            for(int k=i+1; k<y; ++k) 
            {
                //cout<<vFences[k]-vFences[i]<<endl;
                diffV.insert(vFences[k]-vFences[i]);
            }
        }        
        
        long long modulo=1e9+7;
        long long ans=-1;
        for(auto& r : diffH)
        {
            if(diffV.count(r) != 0)
            {
                ans = max(ans, (long long)r*(long long)r);
            }
        }
        
        //cout<<ans<<endl;
        return ans%modulo;
    }
};

//2023-02-22
//time  : O(n)
//space : O(n)
class Solution {
public:
    int minimumScore(string s, string t) 
    {
        int m=s.size();
        int n=t.size();        
        /*if(s[0] != t[0] && s.back() != t.back()) 
        {
            return n;
        }*/
        
        vector<vector<int>> left;
        left.push_back({-1, 0});        
                
        int l=0;
        for(int i=0; i<m && l<n; ++i)
        {
            if(s[i] == t[l])
            {                
                ++l;
                left.push_back({i, l});
            }            
        }
        
        if(l >= n)
        {
            return 0;
        }
        
        /*
        for(int i=0; i<left.size(); ++i)
        {
            cout<<left[i][0]<<" : "<<left[i][1]<<endl;
        }
        cout<<endl;
        */
        
        int ans=n-(left.back()[1]);
        l=left.size()-1;
        int r=n-1;
        for(int i=m-1; i>=0; --i)
        {            
            if(s[i] == t[r])
            {
                
                --r;
                while(l >= 0 && (left[l][0] >= i || left[l][1] > r))
                {
                    --l;
                }
                
                //cout<<i<<" : "<<l<<" "<<r<<" | "<<left[l][1]<<" "<<ans<<endl;
                
                if(l >= 0)
                {
                    ans = min(ans, r-left[l][1]+1);
                }
            }            
        }
        
        //cout<<l<<" "<<r<<" "<<ans<<endl;        
        return ans;
    }        
};

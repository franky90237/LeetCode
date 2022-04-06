class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n=prices.size();
        const int k=2+1;
        int s0[n][k];
        int s1[n][k];
        
        for(int i=0; i<n; ++i) s0[i][0]=0;
        for(int t=1; t<k; ++t) s0[0][t]=0;
        
        for(int i=0; i<n; ++i) s1[i][0]=0;
        s1[0][0]=-prices[0];
        s1[0][1]=-prices[0];
        s1[0][2]=0;
        
        for(int i=1; i<n; ++i)
        {
            for(int t=1; t<k; ++t)
            {
                s0[i][t]=max(s0[i-1][t],s1[i-1][t-1]+prices[i]);
                cout<<s0[i][t]<<" ";
            }
            cout<<endl;
            
            for(int t=1; t<k; ++t)
            {
                s1[i][t]=max(s1[i-1][t],s0[i-1][t-1]-prices[i]);
            }
        }
        
        /*for(auto& i:s0) cout<<i<<"  ";
        cout<<endl;
        for(auto& i:s1) cout<<i<<" ";*/
        
        return s0[n-1][k-1];
    }
};

//2024-01-29
//time  : O(n*n*n)
//space : O(n*n)
class Solution { 
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {     
        
        vector<vector<int>> minCost(n+1, vector<int>(n+1, INT_MAX/2));
        for(int i=0; i<=n; ++i) minCost[i][i]=0;
        for(auto& time : times)
        {
            int s=time[0];
            int t=time[1];
            int c=time[2];            
            minCost[s][t]=c;
        }        
        
        for(int k=1; k<=n; ++k)
        {
            for(int i=1; i<=n; ++i)
            {
                for(int j=1; j<=n; ++j)
                {
                    if(minCost[i][j] > minCost[i][k] + minCost[k][j])
                    {
                        minCost[i][j] = minCost[i][k] + minCost[k][j];
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=1; i<=n; ++i)
        {
            //cout<<k<<" "<<i<<" | "<<minCost[k][i]<<endl;
            if(i == k) continue;
            if(minCost[k][i] == INT_MAX/2) return -1;        
            ans = max(ans, minCost[k][i]);
        }
        
        return ans;
    }          
};

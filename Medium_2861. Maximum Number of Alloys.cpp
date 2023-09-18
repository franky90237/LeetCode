//2023-09-18
//time  : O(log(INT_MAX)*n*k)
//space : O(1)
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) 
    {
        int low=0;
        int high=INT_MAX;
        int ans=0;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            if(check(budget, composition, stock, cost, mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
    
    bool check(int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, long cnt)
    {
        for(int i=0; i<composition.size(); ++i)
        {
            long curCost=0;
            for(int x=0; x<composition[i].size(); ++x)
            {
                long rest=max(cnt*composition[i][x]-stock[x], 0L);
                curCost += rest*cost[x];
            }
            
            if(curCost <= budget) return true;
        }
        
        return false;
    }
};

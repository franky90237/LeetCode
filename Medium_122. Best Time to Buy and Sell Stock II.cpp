//dp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {                
        int n=prices.size();
        int last=n-1;
        while(prices[last]==0) --last;
                
        n=last+1;
        int table[n];
        table[n-1]=0;
        for(int i=n-2; i>=0; --i)
        {
            int max_profit=table[i+1];
            for(int j=i+1; j<n; ++j)
            {
                int diff=(prices[j]-prices[i] < 0) ? 0 : prices[j]-prices[i];
                
                max_profit=max(max_profit,diff+table[j]);
            }
            
            table[i]=max_profit;
        }
        
        //for(auto& i:table) cout<<i<<" ";
        
        return table[0];
    }
};

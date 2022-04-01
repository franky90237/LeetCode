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

//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int profit=0;
        
        for(int i=1; i<n; ++i)
        {
            int diff=prices[i]-prices[i-1];
            if(diff>0)
            {
                profit+=diff;
            }
        }
        
        return profit;
    }
};

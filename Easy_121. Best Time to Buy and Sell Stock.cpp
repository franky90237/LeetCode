//TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n==1) return 0;
        
        int min=-1;
        int max=0;
        int profit=0;
        for(int i=0; i<n; ++i)
        {
            if(min!=-1 && prices[min]<=prices[i]) continue;
            
            if(i>=max) max=find_max(prices,i);
            
            if(prices[max]-prices[i]>profit) 
            {
                profit=prices[max]-prices[i];
                min=i;
            }
        }
        
        return profit;
    }
    
    int find_max(vector<int>& prices, int begin)
    {
        int n=prices.size();
        int max=begin;
        for(int i=begin+1; i<n; ++i)
        {
            if(prices[max]<prices[i]) max=i;
        }
        
        //cout<<begin<<" "<<max<<endl;
        
        return max;
    }
};

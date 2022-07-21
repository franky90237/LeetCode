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

//
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n==1) return 0;
        
        vector<int> new_prices;
        remove_continuous_duplicate(prices,new_prices);
        swap(prices,new_prices);
        n=prices.size();
        
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
    
    void remove_continuous_duplicate(vector<int>& prices, vector<int>& new_prices)
    {
        int pre=prices[0];
        new_prices.push_back(prices[0]);
        for(int i=1; i<prices.size(); ++i)
        {
            if(prices[i]!=pre)
            {
                new_prices.push_back(prices[i]);
                pre=prices[i];
            }
        }
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

//time  : O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int min=0;
        int profit=0;
        
        for(int i=0; i<n; ++i)
        {
            if(prices[i]<prices[min]) min=i;
            else if(prices[i]-prices[min]>profit) profit=prices[i]-prices[min];
        }
        
        return profit;
    }
};

//2022-07-21
//greedy
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {        
        int profit=0;
        int buy=prices[0];
        for(auto price:prices)
        {
            if(price>buy)
            {
                profit=max(profit,price-buy);
            }
            else
            {
                buy=price;
            }
        }
        
        return profit;
    }
};

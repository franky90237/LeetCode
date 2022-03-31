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

/*class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n==1) return 0;
        
        int max=0;
        int min=0;
        find_max_min(prices,max,min);
        
        if(min<=max) return prices[max]-prices[min];
        
        int max_after_min=find_max(prices,min,n-1);
        int min_befor_max=find_min(prices,0,max);
        
        int res1=prices[max_after_min]-prices[min];
        int res2=prices[max]-prices[min_befor_max];
        
        return res1 > res2 ? res1 : res2;
    }
    
    void find_max_min(vector<int>& prices, int& max, int & min)
    {
        int n=prices.size();
        
        for(int i=1; i<n; ++i)
        {
            if(prices[max]<prices[i]) max=i;
            if(prices[min]>prices[i]) min=i;
        }
    }
    
    int find_max(vector<int>& prices, int begin, int end)
    {
        int max=begin;
        for(int i=begin+1; i<=end; ++i)
        {
            if(prices[max]<prices[i]) max=i;
        }
        
        //cout<<begin<<" "<<max<<endl;
        
        return max;
    }
    
    int find_min(vector<int>& prices, int begin, int end)
    {
        int min=begin;
        for(int i=begin+1; i<=end; ++i)
        {
            if(prices[min]>prices[i]) min=i;
        }
        
        //cout<<begin<<" "<<min<<endl;
        
        return min;
    }
    
};*/

//2023-12-23
//time  : O(nlog(n))
//space : O(n)
class Solution {   
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) 
    {
        map<int, long long> buy;
        map<int, long long> sell;
        int modulo=1e9+7;
        long long buyTotal=0;
        long long sellTotal=0;
        
        int n=orders.size();
        for(auto& order: orders)
        {
            int price=order[0];
            int amount=order[1];
            
            if(order[2] == 0) // buy
            {                
                buy[-price] += amount;
                long long sum=0;
                
                for(auto it=sell.begin(); it!=sell.end(); )
                {
                    //int sellPrice=it->first;
                    //int sellAmount=it->second;
                    //cout<<it->first<<" "<<it->second<<endl;
                    if(it->first > price) break;
                    if(it->second >= buy[-price])
                    {
                        sum += buy[-price];
                        it->second -= buy[-price];
                        if(it->second == 0) sell.erase(it);
                        buy.erase(-price);
                        break;
                    }
                                        
                    buy[-price] -= it->second;
                    sum += it->second;
                    it=sell.erase(it);
                }
                                
                buyTotal = (buyTotal+amount-sum);
                sellTotal = (sellTotal-sum);
            }
            else
            {
                sell[price] += amount;                
                long long sum=0;
                
                for(auto it=buy.begin(); it!=buy.end(); )
                {
                    //int buyPrice=-(it->first);
                    //int buyAmount=it->second;
                    //cout<<it->first<<" "<<it->second<<endl;
                    if(-(it->first) < price) break;
                    if(it->second >= sell[price])
                    {
                        sum += sell[price];
                        it->second -= sell[price];
                        if(it->second == 0) buy.erase(it);
                        sell.erase(price);
                        break;
                    }
                    
                    sell[price] -= it->second;
                    sum += it->second;
                    it=buy.erase(it);
                }
                
                buyTotal = (buyTotal-sum);
                sellTotal = (sellTotal+amount-sum);
            }
            
            //cout<<buyTotal<<" "<<sellTotal<<" | "<<buyTotal+sellTotal<<endl;
        }
        
        /*
        long long ans=0;
        for(auto& it : buy) ans = ans + it.second;
        for(auto& it : sell) ans = ans + it.second;
        return ans%modulo;
        */
        
        return (buyTotal+sellTotal)%modulo;
    }       
};

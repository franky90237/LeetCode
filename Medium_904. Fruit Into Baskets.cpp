//2022-01-13
//time  : O(n)
//space : O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        map<int, vector<int>> baskets;
        int l=0;
        int ans=0;
        
        for(int i=0; i<fruits.size(); ++i)
        {
            int type=fruits[i];
            
            if(baskets.size() == 2 && baskets.count(type) == 0)
            {                
                for(auto& it: baskets)
                {
                    if(it.first == fruits[i-1])
                    {
                        l=it.second[0];
                        break;
                    }
                }
                
                baskets.clear();
                baskets[fruits[i-1]].push_back(l);                
            }
            
            if(baskets.count(type) >= 1 && i-baskets[type].back() >= 2)
            {                
                baskets.erase(type);
            }
            
            baskets[type].push_back(i);
            
            //cout<<i<<" "<<l<<endl;
            ans=max(ans, i-l+1);
        }
        
        return ans;
    }
};

//2023-06-16
//time  : O(n*n)
//space : O(n)
class Solution 
{   
public:
    long long minCost(vector<int>& nums, int x)
    {   
        int n=nums.size();
        
        vector<int> minimum(n, INT_MAX);
        long long res=LLONG_MAX;
        for(int cnt=0; cnt<n; ++cnt)
        {
            long long curCost=0;
            for(int i=0; i<n; ++i)
            {
                minimum[i]=min(minimum[i], nums[(i+cnt)%n]);
                curCost += minimum[i];
            }
            
            curCost += (long long)x*cnt;
            res=min(res, curCost);
        }
        
        return res;
    }    
};


/*

[15,150,56,69,214,203]
42

0 : 15+150+56+69+214+203 = 707
1 : 15+56+56+69+203+15+42 = 456
2 : 15+56+56+69+15+15+42*2 = 310
3 : 15+56+56+15+15+15+42*3 = 298
4 : 15+56+15+15+15+15+42*4 = 299
5 : 15*6+42*5 = 300
*/

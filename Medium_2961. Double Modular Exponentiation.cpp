//2023-12-11
//time  : O(n * (log(b) + log(c)))
//space : O(n)
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) 
    {       
        vector<int> ans;
        int i=0;
        for(auto& var : variables)
        {
            int a=var[0], b=var[1], c=var[2], m=var[3];
                        
            int tmp = getPower(a, b , 10);
            int res = getPower(tmp, c, m);
            
            //cout<<i<<" | "<<tmp<<" "<<res<<endl;
            if(res == target) ans.push_back(i);
            ++i;
        }
        
        return ans;
    }
    
    int getPower(int base, int x, int modulo)
    {
        /*
        
        2^10 = 2^5 * 2^5
        
        2^10 = 2^(1010)
        
        10 = 1010 = 2^3 + 2^1 = 8+2
        
        8 4 2 1                     
        
        */
        
        if(x == 0) return 1;
        if(x == 1) return base%modulo;
        
        int ans=1;
        int cur=base;
        int i=0;
        while(x > 0)
        {
            if((x&1) == 1)
            {
                ans = (ans*cur) % modulo;
            }
            
            ++i;
            cur = (cur*cur) % modulo;
            x >>= 1;
        }
        
        return ans;
    }
};

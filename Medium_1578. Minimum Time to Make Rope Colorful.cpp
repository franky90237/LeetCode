//2022-10-03
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n=colors.size();
        
        int ans=0;
        int i=0;
        while(i < n)
        {
            int biggest=neededTime[i];
            int sum=neededTime[i];
            int k=i+1;
            while(k < n && colors[k] == colors[i])
            {
                sum+=neededTime[k];
                biggest=max(biggest, neededTime[k]);
                ++k;
            }
            
            if(k != i+1)
            {
                ans = ans + sum - biggest;
            }
            
            //cout<<i<<","<<k<<" | "<<sum<<" "<<ans<<endl;
            i=k;
        }
        
        return ans;
    }
};

//2022-10-03
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n=colors.size();
        
        int biggest=0;
        int ans=0;        
        int i=0;
        while(i < n)
        {
            if(i-1 >= 0 && colors[i] != colors[i-1])
            {
                biggest=0;
            }
            
            ans+=min(biggest, neededTime[i]);
            biggest=max(biggest, neededTime[i]);
            
            ++i;
        }
        
        return ans;
    }
};

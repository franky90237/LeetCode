//2023-12-29
//time  : O(v*v*v + n*n*k)
//space : O(v*v)
class Solution 
{
private:
    long long inf=LLONG_MAX/2LL;
    
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) 
    {
        unordered_map<string, int> table;
        int number=0;
        for(int i=0; i<original.size(); ++i)
        {
            if(table.count(original[i]) == 0) table[original[i]]=number++;
        }
        
        for(int i=0; i<changed.size(); ++i)
        {
            if(table.count(changed[i]) == 0) table[changed[i]]=number++;
        }
        
        vector<vector<long long>> minCost(number, vector<long long>(number, inf));
        for(int i=0; i<number; ++i)
        {
            minCost[i][i]=0;
        }
        
        for(int i=0; i<original.size(); ++i)
        {
            int begin=table[original[i]];
            int end=table[changed[i]];
            minCost[begin][end]=min(minCost[begin][end], (long long)cost[i]);
        }
        
        for(int k=0; k<number; ++k)
        {
            for(int begin=0; begin<number; ++begin)
            {
                if(minCost[begin][k] >= inf) continue;
                for(int end=0; end<number; ++end)
                {
                    if(minCost[begin][end] > minCost[begin][k] + minCost[k][end])
                    {
                        minCost[begin][end] = minCost[begin][k] + minCost[k][end];
                    }                    
                }
            }
        }
        
        unordered_set<int> beginLen;    
        for(auto& s: original)
        {
            beginLen.insert(s.size());
        }
        
        //cout<<"done !  number : "<<number<<endl;
        
        int n=source.size();
        vector<long long> dp(n+1, inf);
        dp[n]=0;
        for(int left=n-1; left>=0; --left)
        {
            //string sA;
            //string sB;
            //bool isSame=true;
            
            if(source[left] == target[left])
            {
                dp[left]=min(dp[left], dp[left+1]);
            }
            
            for(int len : beginLen)
            {                
                //cout<<left<<" "<<right<<endl;
                //sA.push_back(source[right]);
                //sB.push_back(target[right]);
                //isSame = isSame && (source[right] == target[right]);
                
                int right=left+len-1;
                if(right >= n) continue;
                string sA=source.substr(left, len);
                string sB=target.substr(left, len);                
                                
                if(sA == sB)
                {
                    dp[left]=min(dp[left], dp[right+1]);
                }
                if(table.count(sA) != 0 && table.count(sB) != 0)
                {                    
                    int a=table[sA];
                    int b=table[sB];
                    //cout<<left<<" "<<right<<" | "<<sA<<" "<<sB<<" | "<<minCost[a][b]<<endl;
                    dp[left]=min(dp[left], minCost[a][b] + dp[right+1]);
                }
            }
        }
        
        //for(int i: dp) cout<<i<<" "; cout<<endl;
        return dp[0] >= inf ? -1 : dp[0];                        
    }
};

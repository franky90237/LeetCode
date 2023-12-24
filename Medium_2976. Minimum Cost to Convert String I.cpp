//2023-12-24
//time  : O(n+26*26*26)
//space : O(26*26*26)
class Solution 
{
private:
    int infinite=1e8;   
    long long minCost[128][128][27];
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {            
        for(int i=0; i<128; ++i)
        {
            for(int j=0; j<128; ++j)
            {                            
                for(int k=0; k<27; ++k) 
                {
                    if(i == j) minCost[i][j][k]=0;
                    else minCost[i][j][k]=infinite;
                }
            }                    
        }
        
        for(int i=0; i<original.size(); ++i)
        {
            char a=original[i];
            char b=changed[i];
            //cout<<(char)a<<" "<<(char)b<<" | "<<table[a][b]<<endl;
            
            minCost[a][b][0]=min(minCost[a][b][0], (long long)cost[i]);
        }
                
        for(int k='a'; k<='z'; ++k)
        {
            for(int a='a'; a<='z'; ++a)
            {                                                
                for(int b='a'; b<='z'; ++b)
                {
                    if(a == b) continue;
                    
                    int p=k-'a'+1;
                    if(minCost[a][b][p-1] > minCost[a][k][p-1] + minCost[k][b][p-1])
                    {
                        minCost[a][b][p]=minCost[a][k][p-1] + minCost[k][b][p-1];
                    }
                    else
                    {
                        minCost[a][b][p]=minCost[a][b][p-1];
                    }
                }
            }
        }
        
        //cout<<"minCost done!"<<endl;
        
        long long ans=0;
        for(int i=0; i<source.size(); ++i)
        {
            char a=source[i];
            char b=target[i];
            if(a == b) continue;
            if(minCost[a][b][26] >= infinite)  return -1;            
            
            //cout<<" *** "<<(char)a<<" "<<(char)b<<" | "<<minCost[a][b]<<endl;
            ans += minCost[a][b][26];            
        }
        
        return ans;
    }       
};

//2023-12-24
//time  : O(n+v*v*v)
//space : O(v*v*v)
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

//2023-12-28
//time  : O(n+v*v*v)
//space : O(v*v)
class Solution 
{
private:
    int inf=1e8;
    vector<vector<long long>> minCost;    
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        minCost.resize(26, vector<long long>(26, inf));
        for(int i=0; i<26; ++i)
        {
            minCost[i][i]=0;
        }
        
        for(int i=0; i<original.size(); ++i)
        {
            char a=original[i]-'a';
            char b=changed[i]-'a';
            minCost[a][b]=min(minCost[a][b], (long long)cost[i]);
        }
        
        for(int k=0; k<26; ++k)
        {
            for(int i=0; i<26; ++i)
            {
                for(int j=0; j<26; ++j)
                {
                    if(minCost[i][j] > minCost[i][k] + minCost[k][j])
                    {
                        minCost[i][j] = minCost[i][k] + minCost[k][j];
                    }
                }
            }
        }
        //cout<<"done! \n";
        
        long long ans=0;
        for(int i=0; i<source.size(); ++i)
        {
            int a=source[i]-'a';
            int b=target[i]-'a';
            if(minCost[a][b] == inf) return -1;            
            ans += minCost[a][b];
        }
        
        return ans;
    }
};

//2023-12-28
//time  : O(n+v*vlogv*e)
//space : O(v*v)
class Solution 
{
private:
    int inf=1e8;
    vector<vector<int>> graph;
    vector<vector<long long>> minCost;    
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        minCost.resize(26, vector<long long>(26, inf));
        graph.resize(26, vector<int>(26, inf)); 
        for(int i=0; i<26; ++i)
        {
            minCost[i][i]=0;
            graph[i][i]=0;
        }
        
        for(int i=0; i<original.size(); ++i)
        {
            char a=original[i]-'a';
            char b=changed[i]-'a';
            graph[a][b]=min(graph[a][b], cost[i]);
        }
        
        for(int begin=0; begin<26; ++begin)
        {
            priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minHeap;
            minHeap.push({0, begin});
            
            while(!minHeap.empty())
            {
                long long curCost=minHeap.top()[0];                
                char end=minHeap.top()[1];
                //cout<<(char)(begin+'a')<<" "<<(char)(end+'a')<<" | "<<minCost[begin][end]<<" "<<curCost<<endl;
                minCost[begin][end]=min(minCost[begin][end], curCost);
                minHeap.pop();
                
                for(int next=0; next<26; ++next)
                {
                    if(minCost[begin][next] > curCost+graph[end][next])
                    {
                        minHeap.push({curCost+graph[end][next], next});
                    }
                }
            }
        }
        
        long long ans=0;
        for(int i=0; i<source.size(); ++i)
        {
            int a=source[i]-'a';
            int b=target[i]-'a';
            if(minCost[a][b] == inf) return -1;   
            //cout<<minCost[a][b]<<endl;
            ans += minCost[a][b];
        }
        
        return ans;
    }
};

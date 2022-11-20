//2022-10-24
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {        
        int n=nums.size();
        int ans=0;        
        for(int i=0; i<n; ++i)
        {
            int GCD=nums[i];            
            for(int j=i; j<n && nums[j]%k==0; ++j)
            {
                GCD=gcd(GCD, nums[j]);
                if(GCD == k) ++ans;                
            }            
        }
        
        return ans;
    }    
};

//2022-10-25
//time  : O(n*m), m is the preGCD count
//space : O(n*m)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {        
        int n=nums.size();                
        int ans=0;
        
        unordered_map<int, int> preGCD[n];
        if(nums[0]%k == 0) 
        {
            ++preGCD[0][nums[0]];
            if(nums[0] == k) ++ans;
        }
                
        for(int i=1; i<n; ++i)
        {
            if(nums[i]%k != 0) continue;
                        
            ++preGCD[i][nums[i]];
            if(nums[i] == k) ++ans;
            
            for(auto& it: preGCD[i-1])
            {
                int curGCD=gcd(nums[i], it.first);
                if(curGCD%k == 0)
                {
                    preGCD[i][curGCD] += it.second;
                    if(curGCD == k) ans += it.second;
                }
            }
            //cout<<ans<<endl;
        }
        
        /*for(int i=0; i<n; ++i)
        {
            for(auto& it: preGCD[i])
            {
                cout<<"("<<it.first<<","<<it.second<<") ";
            }
            cout<<endl;
        }*/
        
        return ans;
    }
};

//2022-11-20
//time  : O(n)
//space : O(n)
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n=roads.size();
        if(n == 0) return 0;
        
        vector<vector<int>> graph(100001);        
        createGraph(roads, graph);                
        
        vector<bool> visited(100001, false);
        long long ans=0;
        dfs(graph, 0, seats, visited, ans);
        return ans;
    }
    
    int dfs(vector<vector<int>>& graph, int cur, int seats, vector<bool>& visited, long long& ans)
    {    
        if(visited[cur]) return 0;
        visited[cur]=true;
        
        int cnt=1;
        for(auto& neighbor: graph[cur])
        {            
            cnt+=dfs(graph, neighbor, seats, visited, ans);
        }
        if(cur != 0) ans += ceil(cnt/(double)seats);
        
        visited[cur]=false;
        return cnt;
    }       
    
    void createGraph(vector<vector<int>>& roads, vector<vector<int>>& graph)
    {        
        for(auto road: roads)
        {
            int a=road[0];
            int b=road[1];
            graph[a].push_back(b);
            graph[b].push_back(a);            
        }
        
    }
};

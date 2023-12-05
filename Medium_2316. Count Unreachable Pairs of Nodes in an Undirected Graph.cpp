//2023-12-05
///time  : O(n+e)
//space  : O(n+e)
class Solution 
{
private:
    vector<vector<int>> graph;
    vector<bool> used;

public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        graph.resize(n);
        for(auto edge : edges)
        {
            int a=edge[0];
            int b=edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        //cout<<"Graph created!\n";

        used.resize(n, false);
        vector<int> groupCnt;
        for(int i=0; i<n; ++i)
        {
            if(used[i]) continue;            
            vector<bool> vis(n, false);
            int cnt = getCnt(vis, i);
            groupCnt.push_back(cnt);
            //cout<<i<<" : "<<cnt<<endl;
        }       
        //cout<<endl;

        for(int i=0; i<n; ++i)
        {
            if(!used[i]) groupCnt.push_back(1);
        }

        long long ans=0;
        long long sum=groupCnt[0];
        for(int i=1; i<groupCnt.size(); ++i)
        {
            ans += (long long)groupCnt[i]*sum;
            sum += (long long)groupCnt[i];
        }

        return ans;
    }

    int getCnt(vector<bool>& vis, int cur)
    {
        if(vis[cur]) return 0;
        vis[cur]=true;
        used[cur]=true;

        int cnt=1;
        for(int next : graph[cur])
        {
            if(vis[next]) continue;
            cnt += getCnt(vis, next);
        }

        return cnt;
    }
};

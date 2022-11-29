//2022-11-28
//time  : O(nlog(n))
//sapce : O(n)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end());
        /*for(auto& event: events)
        {
            cout<<"("<<event[0]<<", "<<event[1]<<", "<<event[2]<<") ";
        }*/
        
        int n=events.size();
        vector<int> postMax(n);
        postMax[n-1]=events[n-1][2];
        for(int i=n-2; i>=0; --i)
        {
            postMax[i]=max(postMax[i+1], events[i][2]);
            //cout<<postMax[i]<<" ";
        }        
        //cout<<endl;
        
        vector<int> dp(n, -1);
        return dfs(events, postMax, dp, 0);
    }
    
    int dfs(vector<vector<int>>& events, vector<int>& postMax, vector<int>& dp, int cur)
    {
        int n=events.size();
        if(cur >= n) return 0;                
        if(dp[cur] != -1) return dp[cur];
        
        int pick = events[cur][2];
        int idx = binarySerarch(events, cur, events[cur][1]);
        //cout<<cur<<" "<<idx<<endl;
        if(idx != -1)
        {
            pick += postMax[idx];
        }
        
        int notPick = dfs(events, postMax, dp, cur+1);        
        
        dp[cur]=max(pick, notPick);
        return dp[cur];
    }
    
    int binarySerarch(vector<vector<int>>& events, int l, int target)
    {        
        int r=events.size()-1;
        //if(l > r) return -1;       
        
        while(l < r)
        {            
            int mid=l+(r-l)/2;            
            if(target < events[mid][0]) r=mid;
            else l=mid+1;
        }
                
        if(target < events[l][0]) return l;
        return -1;
    }
};

//2022-11-29
//time  : O(nlog(n))
//sapce : O(n)
class Solution {
private:
    struct Item
    {
        int time;
        bool isBegin;
        int value;
    };
    
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        vector<Item> nodes;        
        for(auto& event: events)
        {
            Item item1={event[0], true, event[2]}; 
            Item item2={event[1], false, event[2]};
            nodes.push_back(item1);
            nodes.push_back(item2);
        }
        
        sort(nodes.begin(), nodes.end(), [](Item& a, Item& b)
             {
                 if(a.time == b.time) return a.isBegin > b.isBegin;
                 return a.time < b.time;
             });
        
        int ans=0;
        int preMax=0;
        for(auto& node: nodes)
        {
            //cout<<ans<<" "<<preMax<<endl;
            if(node.isBegin)
            {
                ans=max(ans, preMax+node.value);
            }
            else
            {
                preMax=max(preMax, node.value);
            }
        }
        
        return ans;
    }
};

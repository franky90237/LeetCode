//2022-09-12
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        
        /*
        [5,10],[6,8],[1,5],[2,3],[1,10]
        (1,1,2, 5, 6)
        (3,5,8,10,10)                
        */
        vector<int> start;
        vector<int> end;
        
        for(auto& interval:intervals)
        {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int ans=0;
        int cur=0;
        int s=0;
        int e=0;
        
        while(s<intervals.size())
        {
            if(start[s]<=end[e])
            {                
                ++cur;
                ++s;
                ans=max(ans,cur);
            }
            else
            {
                --cur;
                ++e;
            }                        
        }
        
        return ans;
    }
};

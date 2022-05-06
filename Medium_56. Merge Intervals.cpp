//2022-05-06
//time  : O(nlog(n))
//space : O(1)
class Solution {
private:
    class comp 
    {
    public:
        bool operator() (vector<int> i,vector<int> j) 
        { 
            if(i[1]<j[1]) return true;
            else if(i[1]==j[1]) return (i[0]<j[0]);            
            return false;
        }
    };
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        comp compare;
        sort(intervals.begin(),intervals.end(),compare);
        print_intervals(intervals);
                
        vector<vector<int>> res;
        int n=intervals.size();        
        for(int i=0 ; i<n; ++i)
        {
            int start=intervals[i][0];
            int end  =intervals[i][1];
            int j=i+1;
            while(j<n && end >= intervals[j][0] && end <= intervals[j][1])
            {
                start=min(start,intervals[j][0]);
                end=intervals[j][1];
                ++j;
                ++i;
            }
            
            res.push_back({start,end});
            
        }
        
        return res;
    }
    
    void print_intervals(vector<vector<int>>& intervals)
    {
        for(auto& i:intervals)
        {
            printf("[%d,%d] ",i[0],i[1]);
        }
        printf("\n");
    }
};

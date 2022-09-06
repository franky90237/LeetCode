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
            if(i[0]<j[0]) return true;
            else if(i[0]==j[0]) return (i[0]<j[0]);            
            return false;
        }
    };
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        comp compare;
        sort(intervals.begin(),intervals.end(),compare);
        //print_intervals(intervals);
                
        vector<vector<int>> res;
        int n=intervals.size();        
        for(int i=0 ; i<n; ++i)
        {
            int start=intervals[i][0];
            int end  =intervals[i][1];
            int j=i+1;
            /*while(j<n && start <= intervals[j][0] && end >= intervals[j][1])
            {
                start=min(start,intervals[j][0]);
                end=max(end,intervals[j][1]);
                ++j;
                ++i;
            }*/
                        
            while(j<n && 
                 ((end >= intervals[j][0] && end <= intervals[j][1]) || 
                  (start <= intervals[j][0] && end >= intervals[j][1])))
            {
                start=min(start,intervals[j][0]);
                end=max(end,intervals[j][1]);
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

//2022-09-06
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        int n=intervals.size();
        for(int i=1; i<n; ++i)
        {
            if(overlapping(ans.back(),intervals[i]))
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
    
    bool overlapping(vector<int>& a, vector<int>& b)
    {
        /*
        --------
          ---------
        */
        return a[1]>=b[0];
    }
};

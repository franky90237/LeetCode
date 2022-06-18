//2022-06-13
//time  : O(n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n=intervals.size();
        
        if(n==0) return {{newInterval[0],newInterval[1]}};
        if(newInterval[0]>intervals.back()[1])
        {
            intervals.push_back({newInterval[0],newInterval[1]});
            return intervals;
        }
        
        vector<vector<int>> ans;
        int i;
        for(i=0; i<n; ++i)
        {
            if(newInterval[1]<intervals[i][0])
            {
                ans.push_back({newInterval[0],newInterval[1]});                
                break;
            }
            
            //cout<<i<<endl;
            if(Overlapping(intervals[i],newInterval))
            {                
                do
                {                    
                    newInterval[0]=min(intervals[i][0],newInterval[0]);
                    newInterval[1]=max(intervals[i][1],newInterval[1]);
                    
                    //cout<<i<<": "<<newInterval[0]<<" "<<newInterval[1]<<endl;
                    ++i;                    
                } while(i<n && Overlapping(intervals[i],newInterval));
                
                ans.push_back({newInterval[0],newInterval[1]});
                break;
            }
            else
            {
                ans.push_back({intervals[i][0],intervals[i][1]});                
            }
        }        
        
        while(i<n)
        {
            ans.push_back({intervals[i][0],intervals[i][1]});
            ++i;
        }
        
        return ans;
    }
    
    bool Overlapping(vector<int>& curInterval, vector<int>& newInterval)
    {        
        if( (newInterval[0]<=curInterval[0] && newInterval[1]>=curInterval[0]) ||
            (newInterval[0]>=curInterval[0] && newInterval[0]<=curInterval[1]) )
        {            
            return true;
        }
        
        return false;
    }
};

//2022-06-18
//clear
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n=intervals.size();
        if(n==0) return {newInterval};
        
        vector<vector<int>> res;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]) 
        {
            res.push_back(intervals[i]);
            ++i;
        }
        
        //cout<<i<<endl;
        while(i<n && Overlaping(intervals[i],newInterval))
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            ++i;
        }
        
        res.push_back(newInterval);
        
        while(i<n)
        {
            res.push_back(intervals[i]);
            ++i;            
        }
        
        return res;
    }
    
    bool Overlaping(vector<int>& curInterval, vector<int>& newInterval)
    {
        return (newInterval[1]>=curInterval[0]);
    }
};

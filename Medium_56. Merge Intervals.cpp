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
//time  : O(nlong(n))
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

//2024-01-25
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;		
        res.push_back({ intervals[0][0], intervals[0][1] });
                
        for (int i = 1; i < n; ++i)
        {
            if(!overlap(res.back()[0], res.back()[1], intervals[i][0], intervals[i][1]))
            {
                res.push_back({ intervals[i][0], intervals[i][1] });
                continue;
            }
                    
            int last=res.size()-1;
            do
            {
                res[last][1] = max(res[last][1], intervals[i][1]);
                ++i;
            } while (i < n  && overlap(res.back()[0], res.back()[1], intervals[i][0], intervals[i][1]));
            
            --i;
        }                        
        
        return res;
    }
    
    bool overlap(int a, int b, int c, int d)
    {
        if (b >= c) return true;
        return false;
    }
};

//2024-02-20
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i)
        {
            if (overlap(res.back()[0], res.back()[1], intervals[i][0], intervals[i][1]))
            {
                res.back()[0] = min(res.back()[0], intervals[i][0]);
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
    
    bool overlap(int a, int b, int c, int d)
    {
        if (a <= c && c <= b) return true;
        if (c <= a && a <= d) return true;
        return false;
    }    
};

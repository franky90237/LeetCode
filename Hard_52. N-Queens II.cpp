class Solution {
private:
    //enum {
public:
    int totalNQueens(int n)
    {
        int res=0;
        
        for(int c=0; c<n; ++c)
        {
            unordered_set<int> visited[4];
            visited[0].insert(0);
            visited[1].insert(c);
            visited[2].insert(0+c);
            visited[3].insert(0-c);
            
            countNQueues(c,n,res,visited);
        }
        
        return res;
    }
    
    void countNQueues(int col, int n, int& res, unordered_set<int> visited[])
    {
        if(col<0 || col>=n) return;
        
        int tmpr;
        //for(int c=0; c<n && c!=col; ++c)
        //{

        for(int r=0; r<n; ++r)
        {
            cout<<r<<" : "<<col<<endl;
            if(visited[0].find(r)!=visited[0].end() ||
               visited[1].find(col)!=visited[1].end() ||
               visited[2].find(r-col)!=visited[2].end() ||
               visited[3].find(r+col)!=visited[3].end()) 
            {
                if(r+1>=n) 
                {
                    //countNQueues(col-1,n,res,visited);
                    countNQueues(col+1,n,res,visited);
                }
                continue;
            }
            else 
            {
                visited[0].insert(r);
                visited[1].insert(col);
                visited[2].insert(r-col);
                visited[3].insert(r+col);
            }
            
            //cout<<r<<" : "<<col<<endl;
            
            tmpr=r;
            if(visited[0].size()>=n) ++res;
            //countNQueues(col-1,n,res,visited);
            countNQueues(col+1,n,res,visited);
            //break;
        }
            
        visited[0].erase(tmpr);
        visited[1].erase(col);
        visited[2].erase(tmpr-col);
        visited[3].erase(tmpr+col);
        
        cout<<endl;
            
        //}
    }
};

class Solution {
public:
    int totalNQueens(int n) 
    {
        int res=0;
        unordered_set<int> v[4];
        number_of_NQueens(0,n,res,v);
        
        return res;
    }
    
    void number_of_NQueens(int r, int n, int& res, unordered_set<int> v[])
    {
        if(r>=n) ++res;
        
        for(int c=0; c<n; ++c)
        {
            if(is_save(r,c,v))
            {
                update_constraint(r,c,v);
                
                number_of_NQueens(r+1,n,res,v);
                
                remove_constraint(r,c,v);
            }
        }
    }
    
    bool is_save(int r, int c, unordered_set<int> v[])
    {
        if(v[0].count(r)!=0 || v[1].count(c)!=0 || v[2].count(r+c)!=0 || v[3].count(r-c)!=0)
        {
            return false;
        }
        return true;
    }
    
    void update_constraint(int r, int c, unordered_set<int> v[])
    {
        v[0].insert(r);
        v[1].insert(c);
        v[2].insert(r+c);
        v[3].insert(r-c);
    }
    
    void remove_constraint(int r, int c, unordered_set<int> v[])
    {
        v[0].erase(r);
        v[1].erase(c);
        v[2].erase(r+c);
        v[3].erase(r-c);
    }
};

/*
class Solution {
private:
    //enum {
public:
    int totalNQueens(int n)
    {
        int res=0;
        
        for(int c=0; c<n; ++c)
        {
            cout<<"*****"<<c<<"*****"<<endl;
            unordered_set<int> visited[4];
            visited[0].insert(0);
            visited[1].insert(c);
            visited[2].insert(0-c);
            visited[3].insert(0+c);
            
            countNQueues(c,n,res,visited);
            cout<<c<<"\'s "<<res<<endl;
        }
        
        return res;
    }
    
    void countNQueues(int col, int n, int& res, unordered_set<int> visited[])
    {
        if(col<0 || col>=n) return;
                
        for(int c=0; c<n; ++c)
        {
            if(c==col || visited[1].find(c)!=visited[1].end())
            {
                continue;
            }
            
            int tmp_r=-1;
            for(int r=0; r<n; ++r)
            {
                cout<<r<<" : "<<c<<endl;
                
                if(visited[0].find(r)!=visited[0].end() ||
                   visited[1].find(c)!=visited[1].end() ||
                   visited[2].find(r-c)!=visited[2].end() ||
                   visited[3].find(r+c)!=visited[3].end()) 
                {
                    continue;
                }
                else 
                {
                    visited[0].insert(r);
                    visited[1].insert(c);
                    visited[2].insert(r-c);
                    visited[3].insert(r+c);                

                    cout<<r<<" : "<<c<<" - insert"<<endl;

                    tmp_r=r;
                    if(visited[0].size()>=n) ++res;
                    countNQueues(c,n,res,visited);
                    
                    visited[0].erase(r);
                    visited[1].erase(c);
                    visited[2].erase(r-c);
                    visited[3].erase(r+c);
                }
            }
            
            cout<<endl;            
        }
    }
};
*/

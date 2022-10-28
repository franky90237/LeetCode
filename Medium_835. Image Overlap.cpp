//2022-10-28
//time  : O(n*n*n*n)
//spcae : O(1)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        /*
        [3][3] [3][2] [3][1]
        [2][3] [1][2] [2][1]
        [1][3] [2][2] [1][1]
        [0][3] [0][2] [0][1] [0][0] [0][1] [0][2]
        [1][3] [1][2] [1][1] [1][0] [1][1] [1][2]
        [2][3] [2][2] [2][1] [2][0] [2][1] [2][2]
                                                  [3][3] [3][4] [3][5]
                                                  [4][3] [4][4] [4][5]
                                                  [5][3] [5][4] [5][5]
        */
        
        int n=img1.size();           
        
        int ans=0;
        for(int r=0-n; r<n; ++r)
        {
            for(int c=0-n+1; c<n; ++c)
            {
                //cout<<"("<<r<<","<<c<<") ";
                //n*n
                int cnt=0;                          
                for(int r1=r, r2=0; r2<n; ++r2, ++r1)
                {                    
                    for(int c1=c, c2=0; c2<n; ++c2, ++c1)
                    {                      
                        //cout<<"("<<r1<<","<<c1<<") ";
                        if(r1<0 || r1>=n || c1<0 || c1>=n || img1[r1][c1] == 0 || img2[r2][c2] == 0) continue;
                        ++cnt;
                    }
                    //cout<<endl;
                }
                               
                ans=max(ans, cnt);
                //cout<<":"<<cnt<<" ";
            }
            
            //cout<<endl;
        }                                
        
        return ans;
    }
};

//2022-10-28
//time  : O(n*n*n*n)
//spcae : O(n*n)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int n=img1.size();
        
        unordered_set<int> pos1;
        unordered_set<int> pos2;
        for(int r=0; r<n; ++r)
        {
            for(int c=0; c<n; ++c)
            {
                if(img1[r][c] == 1) pos1.insert(r*n+c);
                if(img2[r][c] == 1) pos2.insert(r*n+c);
            }
        }
        
        int ans=0;
        map<pair<int, int>, int> shift;
        for(auto& it1: pos1)
        {
            for(auto& it2: pos2)
            {
                int r1=it1/n, c1=it1%n;
                int r2=it2/n, c2=it2%n;
                
                int rDif=r2-r1;
                int cDif=c2-c1;                
                ++shift[{rDif, cDif}];
                
                ans=max(ans, shift[{rDif, cDif}]);
            }
        }
        
        return ans;
    }
};

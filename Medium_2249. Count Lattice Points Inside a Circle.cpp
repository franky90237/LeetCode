//2022-10-21
//time  : O(n*2r*2r), r is the circle radius
//space : O(n*2r*2r)
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) 
    {        
        set<pair<int, int>> point;
        for(auto& circle: circles)
        {
            int radius=circle[2];
            for(int r=circle[0]-radius; r<=circle[0]+radius; ++r)
            {
                for(int c=circle[1]-radius; c<=circle[1]+radius; ++c)
                {
                    int dist=(r-circle[0])*(r-circle[0])+(c-circle[1])*(c-circle[1]);
                    if(dist <= radius*radius)
                    {
                        point.insert({r,c});
                    }
                    //cout<<"("<<r<<","<<c<<") "<<dist<<endl;                    
                }
            }
            
            //point.erase({circle[0]-radius, circle[1]-radius});
            //point.erase({circle[0]-radius, circle[1]+radius});
            //point.erase({circle[0]+radius, circle[1]-radius});https://leetcode.com/problems/contains-duplicate-ii/
            //point.erase({circle[0]+radius, circle[1]+radius});
        }
        
        return point.size();
    }
};

//2022-10-22
//TLE
//bfs
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) 
    {
        set<pair<int, int>> point;       
        for(auto& circle: circles)
        {
            int cx=circle[0];
            int cy=circle[1];
            int r=circle[2];

            bfs(point, cx, cy, r);
        }
        
        return point.size();
    }
    
    void bfs(set<pair<int, int>>& point, int cx, int cy, int r)
    {
        int dir[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        vector<vector<bool>> visited(cx+r+1, vector<bool>(cy+r+1, false));
        //bool visited[200][200]={false};
        visited[cx][cy]=true;
            
        queue<pair<int, int>> q;
        q.push({cx, cy});        
        
        point.insert({cx, cy});        
        while(r > 0)
        {
            int size=q.size();
            while(size > 0)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int i=0; i<4; ++i)
                {
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    if(visited[nx][ny]) continue;
                    
                    q.push({nx, ny});
                    point.insert({nx, ny});                    
                }
                
                --size;
            }
            
            --r;
        }
    }
};

//2022-10-22
//time  : O(n*200*200)
//space : O(1)
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) 
    {
        int ans=0;
        for(int x=0; x<=200; ++x)
        {
            for(int y=0; y<=200; ++y)
            {
                for(auto& circle: circles)
                {
                    int cx=circle[0];
                    int cy=circle[1];
                    int r=circle[2];
                    
                    int dist=(x-cx)*(x-cx)+(y-cy)*(y-cy);
                    if(dist <= r*r) 
                    {
                        //cout<<x<<", "<<y<<" | "<<cx<<", "<<cy<<" : "<<r<<endl;
                        ++ans;
                        break;
                    }
                }
            }                        
        }
        
        return ans;           
    }
};

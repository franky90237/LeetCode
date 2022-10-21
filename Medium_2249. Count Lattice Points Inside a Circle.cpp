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

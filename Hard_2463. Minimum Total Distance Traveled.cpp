//2022-11-07
//time  : O(m*n*m)
//space : O(m*n*m)
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int m=robot.size();
        int n=factory.size();
        vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(n+1, vector<long long>(m+1, -1)));
        return solve(robot, factory, 0, 0, factory[0][1], dp);
    }

    long long solve(vector<int>& robot, vector<vector<int>>& factory, int x, int y, int z, vector<vector<vector<long long>>>& dp) 
    {
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(x >= robot.size()) return 0;

        while(y < factory.size() && z == 0) 
        {
            ++y;
            if(y >= factory.size()) return LLONG_MAX;
            z=factory[y][1];
        }        
                
        if(dp[x][y][z] != -1) 
        {            
            return dp[x][y][z];
        }
        
        long long pick;       
        pick = solve(robot, factory, x+1, y, z-1, dp);
        if(pick != LLONG_MAX) pick += abs(factory[y][0]-robot[x]);        

        long long notPick;
        if(y+1 < factory.size()) notPick=solve(robot, factory, x, y+1, factory[y+1][1], dp);
        else notPick = LLONG_MAX;

        long long distance=min(pick, notPick);        
        dp[x][y][z]=distance;        
        return distance;
    }
};

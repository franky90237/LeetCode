//2022-10-09
//time  : O(n)
//space : O(1)
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) 
    {
        int id=logs[0][0];
        int time=logs[0][1];    
        for(int i=1; i < logs.size(); ++i)
        {
            int diff=logs[i][1] - logs[i-1][1];
            if(diff > time || (diff == time && logs[i][0] < id))
            {
                time=diff;
                id=logs[i][0];                
            }          
        }
        
        return id;
    }
};

//2022-09-12
//time  : O(n)
//space : O(26)
class Solution {
public:
    int partitionString(string s)
    {
        bool visited[26]={0};
        
        int ans=1;
        for(auto& c:s)
        {
            if(visited[c-'a'])
            {
                fill(visited,visited+26,0);
                ++ans;
            }
            
            visited[c-'a']=true;
        }
        
        return ans;
    }
};

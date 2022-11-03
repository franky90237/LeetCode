//2022-11-03
//time  : O(n*n), n is the bank size
//spcae : O(n)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {        
        unordered_set<string> visited;
        int ans=dfs(start, end, bank, visited);
        return ans==999 ? -1 : ans;
    }
    
    int dfs(string start, string end, vector<string>& bank, unordered_set<string>& visited)
    {
        //cout<<start<<endl;
        if(start == end) return 0;        
        if(visited.find(start) != visited.end()) return 999;
        visited.insert(start);
        
        int minCnt=999;
        for(int i=0; i<bank.size(); ++i)
        {            
            if(visited.find(bank[i]) != visited.end()) continue;
            
            int diff=difference(start, bank[i]);
            if(diff > 1) continue;
            
            int cnt=dfs(bank[i], end, bank, visited);
            if(cnt == 999) continue;
            
            minCnt=min(minCnt, 1+cnt);                       
        }
        
        visited.erase(start);
        return minCnt;
    }
    
    int difference(string& a, string& b)
    {
        int diff=0;
        for(int i=0; i<a.size(); ++i)
        {
            if(a[i] != b[i])
            {
                ++diff;
                if(diff >= 2) break;
            }
        }
        
        return diff;
    }        
};

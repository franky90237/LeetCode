//2023-05-18
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> players(n, 0);
        int cur=0;
        int cnt=1;
        ++players[cur];        
        while(players[cur] <= 1)
        {            
            cur=(cur + k*cnt) % (n);
            ++cnt;
            ++players[cur];
        }
        
        vector<int> ans;
        for(int i=0; i<n; ++i)
        {
            if(players[i] == 0)
            {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

//2023-05-18
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> players(n, 0);
        int cur=0;
        int cnt=1;        
        while(players[cur] <= 0)
        {
            ++players[cur];        
            cur=(cur + k*cnt) % n;
            ++cnt;            
        }
        
        vector<int> ans;
        for(int i=0; i<n; ++i)
        {
            if(players[i] == 0)
            {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

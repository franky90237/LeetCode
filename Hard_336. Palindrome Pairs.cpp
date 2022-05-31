//2022-05-31
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        int n=words.size();
        
        vector<vector<int>> res;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i==j) continue;
                
                int start=0;
                int end=words[j].size()-1;
                while(start<words[i].size() && end>=0 && words[i][start]==words[j][end])
                {
                    ++start;
                    --end;
                }
                //printf("%d , %d \n",start,end);
                
                if(start>=words[i].size() && end<0)
                {
                    res.push_back({i,j});
                }
                else if(start<words[i].size() && end>=0 && words[i][start]!=words[j][end])
                {
                    continue;
                }
                else if(start<words[i].size())
                {
                    int k=words[i].size()-1;
                    while(start<k && words[i][start]==words[i][k])
                    {
                        ++start;
                        --k;
                    }
                    
                    if(start>=k) res.push_back({i,j});
                }
                else if(end>=0)
                {
                    int k=0;
                    while(k<end && words[j][k]==words[j][end])
                    {
                        ++k;
                        --end;
                    }
                    //printf("*** %d , %d \n",k,end);
                    if(k>=end) res.push_back({i,j});
                }
            }
        }
        
        return res;
    }
};

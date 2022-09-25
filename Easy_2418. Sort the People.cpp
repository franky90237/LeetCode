//2022-09-25
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n=names.size();
        
        vector<vector<int>> tmp(n, vector<int>(2));
        for(int i=0; i<n; ++i)
        {
            tmp[i][0]=heights[i];
            tmp[i][1]=i;
        }
        
        sort(tmp.begin(), tmp.end(), 
            [](vector<int>& a, vector<int>& b)
             {
                 return a[0] > b[0];
             });
        
        vector<string> ans(n);
        for(int i=0; i<n ;++i)
        {
            ans[i]=names[tmp[i][1]];
        }            
            
        return ans;
    }
};

//2022-09-25
//clear
//time  : O(nlog(n))
//space : O(n)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n=names.size();
        
        vector<int> tmp;
        for(int i=0; i<n; ++i)
        {
            tmp.push_back(i);
        }
        
        sort(tmp.begin(), tmp.end(), 
            [&](int a, int b)
            {
                return heights[a] > heights[b];
            });
        
        vector<string> ans;
        for(int i=0; i<n ;++i)
        {
            ans.push_back(names[tmp[i]]);
        }            
            
        return ans;
    }
};

//2023-09-04
//time  : O(nlog(k))
//spcae : O(nlog(k))
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) 
    {
        int n=receiver.size();
        int cnt=ceil(log2(k))+1;
        vector<vector<int>> destination(cnt, vector<int>(n));
        vector<vector<long long>> value(cnt, vector<long long>(n, 0));
        for(int i=0; i<n; ++i)
        {           
            destination[0][i]=receiver[i];            
            value[0][i]=i+receiver[i];
        }
        
        for(int i=1; i<cnt; ++i)
        {            
            for(int x=0; x<n; ++x)
            {
                int pre=destination[i-1][x];
                destination[i][x] = destination[i-1][pre];
                value[i][x] = value[i-1][x] + value[i-1][pre] - pre;
            }
        }
        
        /*
        for(int i=0; i<cnt; ++i)
        {
            for(int x=0; x<n; ++x) cout<<destination[i][x]<<" ";
            cout<<" | ";
            for(int x=0; x<n; ++x) cout<<value[i][x]<<" ";
            cout<<endl;
        }
        */
        
        //cout<<"Initialize!"<<endl;
        vector<long long> ans(n, 0);
        vector<vector<int>> target;
        bool isFisrtTime=true;
        for(int i=0; i<cnt; ++i)
        {
            //cout<<i<<" : ";
            if(((k>>i)&1LL) == 1)
            {
                target.push_back(vector<int>(n));
                for(int x=0; x<n; ++x)
                {
                    if(isFisrtTime)
                    {
                        target[0][x] = destination[i][x];
                        ans[x] += value[i][x];                        
                    }
                    else
                    {                        
                        int cur=target.size()-1;
                        target[cur][x] = destination[i][target[cur-1][x]];
                        ans[x] += value[i][target[cur-1][x]] - target[cur-1][x];
                    }                                       
                    //cout<<ans[x]<<" ";
                }
                
                isFisrtTime=false;
            }
            //cout<<endl;
        }
                
        return *max_element(ans.begin(), ans.end());
    }
};

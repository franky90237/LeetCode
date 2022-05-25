//2022-05-25
//TLE
//time. : O(n*n)
//space : O(max_width*max_height)
class Solution {
private:
    struct mycompare
    {
        bool operator()(vector<int>& a, vector<int>& b)
        {
            //cout<<a[0]<<" "<<b[0]<<endl;
            
            if(a[0]<b[0]) return true;
            if(a[0]==b[0])
            {
                if(a[1]<b[1]) return true;
                else return false;
            }
            
            return false;
        }
    } comp;
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end(),comp);
        print(envelopes);
        
        int maxW=1;
        int maxH=1;
        for(auto& i:envelopes)
        {
            maxW=max(maxW,i[0]);
            maxH=max(maxH,i[1]);
        }
        
        vector<vector<int>> dp(maxW+1,vector<int>(maxH+1,-1));
        int n=envelopes.size();
        int maxDolls=1;
        for(int i=0; i<n; ++i)
        {
            maxDolls=max(maxDolls,solve(dp,envelopes,i));
        }
        
        return maxDolls;
        
        return 0;
    }
    
    int solve(vector<vector<int>>& dp, vector<vector<int>>& envelopes, int now)
    {
        int n=envelopes.size();
        if(now>=n) return 0;
        
        int wn=envelopes[now][0];
        int hn=envelopes[now][1];
        if(dp[wn][hn]!=-1) return dp[wn][hn];
        
        int maxDolls=1;
        for(int i=now+1; i<n; ++i)
        {
            int wi=envelopes[i][0];
            int hi=envelopes[i][1];
            if(wi<=wn || hi<=hn)
            {
                continue;
            }
            
            maxDolls=max(maxDolls,1+solve(dp,envelopes,i));
        }
        
        dp[wn][hn]=maxDolls;
        return maxDolls;
    }
    
    void print(vector<vector<int>>& envelopes)
    {
        for(auto& i: envelopes)
        {
            printf("%d, %d \n",i[0],i[1]);
        }
        printf("\n");
    }
};

//2022-05-25
//sorting + longest increasing subsequence
//time. : O(nlog(n))
//space : O(n)
class Solution {
private:
    struct mycompare
    {
        bool operator()(vector<int>& a, vector<int>& b)
        {
            //cout<<a[0]<<" "<<b[0]<<endl;
            
            if(a[0]<b[0]) return true;
            if(a[0]==b[0])
            {
                if(a[1]>b[1]) return true;
                else return false;
            }
            
            return false;
        }
    } comp;
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(),envelopes.end(),comp);
        //print(envelopes);
        
        int n=envelopes.size();
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for(int i=1; i<n; ++i)
        {
            int h=envelopes[i][1];
            
            if(lis.back()<h) lis.push_back(h);
            else if(lis.back()==h) continue;
            else 
            {
                int idx=binary_search(lis,h);
                lis[idx]=h;
            }
        }
        
        return lis.size();
        
        return 0;
    }
    
    int binary_search(vector<int>& lis, int target)
    {
        int left=0;
        int right=lis.size()-1;
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            
            if(lis[mid]>=target) right=mid;
            else left=mid+1;
        }
        
        return left;
    }
    
    void print(vector<vector<int>>& envelopes)
    {
        for(auto& i: envelopes)
        {
            printf("%d, %d \n",i[0],i[1]);
        }
        printf("\n");
    }
};

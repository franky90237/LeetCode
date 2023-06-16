//2023-06-16
//time  : O(n*n)
//space : O(n)
class Solution 
{   
public:
    long long minCost(vector<int>& nums, int x)
    {   
        int n=nums.size();
        
        vector<int> minimum(n, INT_MAX);
        long long res=LLONG_MAX;
        for(int cnt=0; cnt<n; ++cnt)
        {
            long long curCost=0;
            for(int i=0; i<n; ++i)
            {
                minimum[i]=min(minimum[i], nums[(i+cnt)%n]);
                curCost += minimum[i];
            }
            
            curCost += (long long)x*cnt;
            res=min(res, curCost);
        }
        
        return res;
    }    
};


/*

[15,150,56,69,214,203]
42

0 : 15+150+56+69+214+203 = 707
1 : 15+56+56+69+203+15+42 = 456
2 : 15+56+56+69+15+15+42*2 = 310
3 : 15+56+56+15+15+15+42*3 = 298
4 : 15+56+15+15+15+15+42*4 = 299
5 : 15*6+42*5 = 300
*/

//2023-06-16
//time  : O(n*n)
//space : O(n)
class Solution 
{   
public:
    long long minCost(vector<int>& nums, int x)
    {   
        int n=nums.size();
        
        vector<int> minimum(n, INT_MAX);
        long long res=LLONG_MAX;
        for(int cnt=0; cnt<n; ++cnt)
        {
            long long curCost=0;
            for(int i=0; i<n; ++i)
            {
                minimum[i]=min(minimum[i], nums[(i+cnt)%n]);
                curCost += minimum[i];
            }
            
            curCost += (long long)x*cnt;
            if(curCost > res)
            {
                break;
            }
            res=min(res, curCost);
        }
        
        return res;
    }    
};

//2023-06-16
//time  : O(n*n + n*log(n))
//space : O(n*n)
class Solution 
{   
public:
    long long minCost(vector<int>& nums, int x)
    {   
        int n=nums.size();
        
        vector<vector<int>> minimum(n, vector<int>(n, INT_MAX));                
        for(int i=0; i<n; ++i)
        {
            minimum[i][0]=nums[i];            
            for(int cnt=1; cnt<n; ++cnt)
            {
                minimum[i][cnt]=min(minimum[i][cnt-1], nums[(i+cnt)%n]);                
                //cout<<minimum[i][cnt]<<" ";
            }
            //cout<<endl;
        }
        
        long long res=LLONG_MAX;
        int low=0;
        int high=n-1;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            
            long long ans1=getCost(nums, minimum, x, mid);
            long long ans2=getCost(nums, minimum, x, mid+1);
            //cout<<low<<","<<mid<<","<<high<<" | "<<ans1<<" "<<ans2<<endl;
            if(ans1 <= ans2)
            {
                high=mid-1;
                res=ans1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return res;
    }
    
    long long getCost(vector<int>& nums, vector<vector<int>>& minimum, int x, int cnt)
    {
        int n=nums.size();
        if(cnt >= n) return LLONG_MAX;
        //cout<<cnt<<"********"<<endl;
        
        long long res=0;
        for(int i=0; i<n; ++i)
        {        
            res += minimum[i][cnt];
            //cout<<res<<" ";
        }
        
        //cout<<endl;
        res += (long long)x*cnt;        
        return res;
    }
};

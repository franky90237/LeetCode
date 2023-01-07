//2022-01-08
//time  : O(nlog(sum(n)))
//space : O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int l=weights[0];
        int r=weights[0];
        for(int i=1; i<weights.size(); ++i)
        {
            l=max(l, weights[i]);
            r += weights[i];
        }
        
        int ans=0;
        while(l <= r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(check(weights, days, mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& weights, int days, int target)
    {
        int sum=0;
        int cnt=1;
        for(auto weight: weights)
        {
            sum += weight;
            if(sum > target)
            {
                sum=weight;
                ++cnt;
            }
        }
        
        return cnt <= days;
    }
};

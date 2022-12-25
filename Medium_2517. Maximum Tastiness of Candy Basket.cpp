//2022-12-25
//time  : O(nlog(1e9))
//space : O(1)
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k)
    {
        sort(price.begin(), price.end());
        
        int low=0;
        int high=1e9-1;
        int ans=0;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            if(check(price, k, mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
    
    bool check(vector<int>& price, int k, int threshold)
    {
        int cnt=1;
        int pre=price[0];
        for(int i=1; i<price.size(); ++i)
        {
            if(price[i] - pre >= threshold)
            {
                pre=price[i];
                ++cnt;
                if(cnt >= k) return true;
            }
        }
        
        return false;
    }
};

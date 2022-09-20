// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//2022-09-20
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int firstBadVersion(int n)
    {
        int l=0;
        int r=n;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(isBadVersion(mid)) r=mid;
            else l=mid+1;
        }
        
        return l;
    }
};

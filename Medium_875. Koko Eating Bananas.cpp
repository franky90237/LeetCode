//2022-09-21
//time  : O(nlog(n) + nlog(k))
//space : O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        /*
        [3,6,7,11]
        1 : 3+6 = 9 > 8
        2 : 2+3+4 = 9 > 8
        3 : 1+2+3+4 = 10 > 8
        4 : 1+2+2+3 = 8 <= 8

        5 : 1+2+2+3 = 8 <= 8
        6 : 1+1+2+2 = 6 < 8
        ...
        11 : 1+1+1+1 = 4 < 8
        */
        
        sort(piles.begin(), piles.end());
        
        int l=1;
        int r=piles.back();
        while(l<r)
        {
            int mid=l+(r-l)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            
            if(check(piles, mid, h))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return l;
    }
    
    bool check(vector<int>& piles, int k, int h)
    {
        int hours=0;
        for(int i=piles.size()-1; i>=0; --i)
        {
            hours += ceil(piles[i]/(double)k);
            //cout<<"("<<piles[i]<<" "<<k<<" "<<hours<<") ";
            if(hours > h) return false;
        }
        //cout<<endl;
        
        return true;
    }
};

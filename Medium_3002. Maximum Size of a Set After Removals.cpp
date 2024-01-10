//2023-01-10
//time  : O(n)
//space : O(n)
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> t1(nums1.begin(), nums1.end());
        unordered_set<int> t2(nums2.begin(), nums2.end());
        unordered_set<int> t1_and_t2;
        for(auto& it : nums1)
        {
            if(t2.count(it)) t1_and_t2.insert(it);
        }
                
        int n=nums1.size();
        int s1=t1.size();
        int s2=t2.size();
        int common=t1_and_t2.size();
        int total=s1+s2-common;
        //cout<<s1<<" "<<s2<<" "<<common<<endl;
        
        int cnt1=n/2;
        int duplicate1=n-s1;
        if(duplicate1 < cnt1)
        {
            cnt1 -= duplicate1;
            if(cnt1 > common)
            {
                cnt1 -= common;
                common=0;
                total -= cnt1;
            }
            else
            {
                common -= cnt1;
            }
        }        
        
        int cnt2=n/2;
        int duplicate2=n-s2;
        if(duplicate2 < cnt2)
        {
            cnt2 -= duplicate2;
            if(cnt2 > common)
            {
                cnt2 -= common;
                common=0;
                total -= cnt2;
            }
            else
            {
                common -= cnt2;
            }
        }
        
        return total;
    }
};

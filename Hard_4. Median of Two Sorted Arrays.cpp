class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        int target=ceil((m+n)/2.0);
        cout<<target<<endl;
        
        int l1=0, r1=m-1;
        int l2=0, r2=n-1;
        int cur=-1;
        
        int n1;
        int index;
        while(cur!=target && l1<=r1)
        {
            int m1=(l1+r1)/2;
            n1=nums1[m1];
            
            index=find(nums2,l2,r2,n1);
            
            if(nums2[index]>n1) 
            {
                cur=(m1-l1)+1+(index-1-l2)+1;
            }
            else 
            {
                cur=(m1-l1)+1+(index-l2)+1;
            }
            cout<<"cur : "<<cur<<" - n1 : "<<n1<<endl;
            if(cur==target) break;
            else if(cur>target) r1=m1-1;
            else l1=m1+1;            
        }
        
        if(cur==target) return n1;
        cout<<"cur : "<<cur<<" - tar : "<<target<<" - idx : "<<index<<endl;
        if(cur>target) 
        {
            int diff=cur-target;
            return index-diff<0 ? nums2[index] : nums2[index-diff];
        }
        else
        {
            int diff=target-cur;
            return index+diff>=n ? nums2[index] : nums2[index+diff];    
        }
        
    }
    
    int find(vector<int>& nums, int l, int r, int target)
    {
        while(l<r)
        {
            int m=(l+r)/2;
            
            if(nums[m]==target) r=m;
            else if(nums[m]>target) r=m-1;
            else l=m+1;
        }
        
        return l;
    }
};

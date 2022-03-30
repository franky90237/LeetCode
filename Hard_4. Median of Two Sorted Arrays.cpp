class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        if(n<m) return findMedianSortedArrays(nums2,nums1);
        int target=ceil((m+n)/2.0);
        
        int ans1;
        if(nums1.empty()) ans1=nums2[target-1];
        else              ans1=search_target(nums1,nums2,target);
        //,cout<<ans1<<endl;
        if((m+n)%2==1) return ans1;
        
        int ans2;
        if(nums1.empty()) ans2=nums2[target];
        else              ans2=search_target(nums1,nums2,target+1);
        //cout<<ans2<<endl;
        return (ans1+ans2)/2.0;
    }
    
    int search_target(vector<int>& nums1, vector<int>& nums2, int target)
    {
        int m=nums1.size();
        int n=nums2.size();
        //cout<<endl<<target<<endl;
        
        int l1=0, r1=m-1;
        int l2=0, r2=n-1;
        int cur=0;
        
        int n1=1000001;
        int index=0;
        while(cur!=target && l1<=r1)
        {
            int m1=(l1+r1)/2;
            n1=nums1[m1];
            
            index=find(nums2,l2,r2,n1);
            
            if(nums2[index]>=n1) cur=m1+1+index-1+1;
            else                cur=m1+1+index+1;
            
            //cout<<"cur : "<<cur<<" - n1 : "<<n1<<" - idx : "<<index<<endl;
            //cout<<m1<<" "<<l1<<" "<<index<<" "<<l2<<endl;
            
            if(cur==target) break;
            else if(cur>target) 
            {
                r1=m1-1;
                r2=index;
            }
            else
            {
                l1=m1+1;
                l2=index;
            }
        }
        
        //cout<<"cur : "<<cur<<" - tar : "<<target<<" - idx : "<<index<<endl;
        
        int ans1;
        if(cur==target) ans1= n1;
        else if(cur>target) 
        {
            if(n1>nums2[index]) --cur;
            int diff=cur-target;
            ans1=(index-diff<0) ? nums2[index] : nums2[index-diff];
        }
        else
        {
            //if(index==0 && n1<=nums2[index]) ++cur;
            if(n1<=nums2[index]) ++cur;
            int diff=target-cur;
            ans1=(index+diff>=n) ? nums2[index] : nums2[index+diff];
        }
        
        return ans1;
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

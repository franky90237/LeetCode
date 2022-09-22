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


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        int k=(m+n+1)/2;
        
        int ans1=get_kth(nums1,0,m-1,nums2,0,n-1,k);
        if((m+n)%2==1) return ans1;
        //cout<<endl;
        
        int ans2=get_kth(nums1,0,m-1,nums2,0,n-1,k+1);
        //cout<<ans1<<" "<<ans2<<endl;
        return (ans1+ans2)/2.0;
    }
    
    int get_kth(vector<int>& nums1, int l1, int r1,vector<int>& nums2, int l2, int r2, int k)
    {
        int m1=(l1+r1)/2;
        int m2=(l2+r2)/2;
        
        //printf("%d,%d,%d - %d,%d,%d - k=%d \n",l1,m1,r1,l2,m2,r2,k);
        
        if(l1>r1) return nums2[(k-1)+l2];
        if(l2>r2) return nums1[(k-1)+l1];
        
        if(k==1) return min(nums1[l1],nums2[l2]);
        
        //we can't use (m1-l1)+(m2-l2)+1<=k
        //because it'll lead to remove the smaller number
        if((m1-l1)+(m2-l2)+1<k)
        {
            if(nums1[m1]<=nums2[m2])
                return get_kth(nums1,m1+1,r1,nums2,l2,r2,k-(m1-l1+1));
            else
                return get_kth(nums1,l1,r1,nums2,m2+1,r2,k-(m2-l2+1));
        }
        else
        {
            if(nums1[m1]<=nums2[m2])
                return get_kth(nums1,l1,r1,nums2,l2,m2-1,k);
            else
                return get_kth(nums1,l1,m1-1,nums2,l2,r2,k);
        }
    }
};

//2022-09-21
//time  : O(log(m)*log(n) + log(n)*log(m))
//space : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        1,2,2,2,10,15
        [1,2,10]
        [2,2,15]

        5
        [10,11,12]
        [1,2,3]
        [1,2,10,11,12]
        */        
        int m=nums1.size();
        int n=nums2.size();
        
        if(nums1.empty() && nums2.empty()) return 0;
        if(nums2.empty()) return (nums1[m/2] + nums1[(m-1)/2])/2.0;
        if(nums1.empty()) return (nums2[n/2] + nums2[(n-1)/2])/2.0;
        
        int cnt=m+n;
                
        if(cnt%2==0)
        {
            int mid1 = search(nums1, nums2, cnt/2);
            int mid2 = search(nums1, nums2, (cnt/2)+1);
            if(mid1==-1 || mid2==-1) cout<<mid1<<" "<<mid2<<endl;
            //cout<<mid1<<" "<<mid2<<endl;
            return (mid1+mid2) / 2.0;
        }
        else
        {
            int mid = search(nums1, nums2, (cnt/2)+1);
            if(mid==-1) cout<<mid<<endl;
            
            return mid;
        }                        
    }
    
    int search(vector<int>& nums1, vector<int>& nums2, int cnt)
    {
        int l=0;
        int r=nums1.size()-1;        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            vector<int> range = check(nums2, nums1[mid]);
            //cout<<nums1[mid]<<" : "<<range[0]<<" "<<range[1]<<endl;
            
            if(range[0]==range[1])
            {   
                int len=range[0]+mid+1;
                if(len == cnt) return nums1[mid];
                else if(len > cnt) r=mid-1;
                else l=mid+1;
            }
            else
            {
                int len_l=range[0]+mid+1;
                int len_r=range[1]+mid+1;
                
                if(len_l <= cnt && cnt <= len_r) return nums1[mid];
                else if(len_l > cnt) r=mid-1;
                else l=mid+1;
            }
        }
        
        //
        l=0;
        r=nums2.size()-1;        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            vector<int> range = check(nums1, nums2[mid]);
            //cout<<nums2[mid]<<" : "<<range[0]<<" "<<range[1]<<endl;
            
            if(range[0]==range[1])
            {   
                int len=range[0]+mid+1;
                if(len == cnt) return nums2[mid];
                else if(len > cnt) r=mid-1;
                else l=mid+1;
            }
            else
            {
                int len_l=range[0]+mid+1;
                int len_r=range[1]+mid+1;
                
                if(len_l <= cnt && cnt <= len_r) return nums2[mid];
                else if(len_l > cnt) r=mid-1;
                else l=mid+1;
            }
        } 
        
        return -1;
    }
    
    vector<int> check(vector<int>& nums, int target)
    {
        int l=0;
        int r=nums.size()-1;
        
        vector<int> ans(2);
        
        while(l<r)
        {
            int mid=l+(r-l)/2;
            
            if(target > nums[mid]) l=mid+1;
            else r=mid;
        }
        ans[0]=l;
        
        //if(target==2) cout<<l<<endl;
        if(target != nums[l])
        {
            if((l==0 || l==nums.size()-1) && target>nums[l])
            {
                ++ans[0];              
            }
            
            ans[1]=ans[0];
            return ans;            
        }         
        
        l=l;
        r=nums.size()-1;
        while(l<r)
        {
            int mid=l+ceil((r-l)/2.0);
            
            if(target < nums[mid]) r=mid-1;
            else l=mid;
        }        
        ans[1]=l+1;
        
        return ans;
    }
};

//2022-09-22
//time  : O(log(min(m,n)))
//space : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        6 [1,2,3,4,5,6]
        4 [1,2,3,8]

        10 [1,1,2,2,3,3,4,5,6,8] 10/2=5

        5 [1,2,3,4,5]
        4 [1,2,3,8]

        9 [1,1,2,2,3,3,4,5,8] 9/2=4

        2 [1,3]
        1 [2]

        [1,3,3] (2+1+1)/2=2

        l=0   1
        r=1   1
        c2=0  1
        c1=2  1

        l2=S  2
        r2=2  B
        l1=3  1
        r1=B  3
        */
        
        int m=nums1.size();
        int n=nums2.size();        
        if(m<n) return findMedianSortedArrays(nums2, nums1);
        
        int total=(m+n+1)/2;
        int l=0;
        int r=n;
        while(l<=r)
        {
            int cnt2 = l+(r-l)/2;
            int cnt1 = total-cnt2;
            //cout<<cnt2<<" "<<cnt1<<endl;
            
            int l2 = (nums2.empty() || cnt2-1 < 0 ) ? INT_MIN : nums2[cnt2-1];
            int r2 = (nums2.empty() || cnt2 >= n) ? INT_MAX : nums2[cnt2];
            int l1 = (nums1.empty() || cnt1-1 < 0) ? INT_MIN : nums1[cnt1-1];
            int r1 = (nums1.empty() || cnt1 >= m) ? INT_MAX : nums1[cnt1];
            
            if(l2<=r1 && l1<=r2)
            {
                if((m+n)%2==0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            }
            
            if(l2>r1)
            {
                r=cnt2-1;
            }
            else
            {
                l=cnt2+1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n && j-i<=k; ++j)
            {
                if((long)abs((long)nums[i]-(long)nums[j])<=(long)t) return true;
            }
        }
        
        return false;
    }
};

//binary search tree
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k==0 || nums.size()<=1) return false;
        
        int n=nums.size();
        multiset<int> bst;
        
        for(int i=0; i<n; ++i)
        {
            long min=(long)nums[i]-t<INT_MIN ? INT_MIN : nums[i]-t;
            long max=(long)nums[i]+t>INT_MAX ? INT_MAX : nums[i]+t;
                
            multiset<int>::iterator l=bst.lower_bound(min);
            multiset<int>::iterator h=bst.lower_bound(max);
            
            //for(auto i:bst) cout<<i<<" ";
            //cout<<i<<"--"<<(long)*l<<" "<<(long)*h<<endl;
                
            if( (l!=bst.end() && (long)*l>=(long)nums[i]-t && (long)*l<=(long)nums[i]+t) || 
               (h!=bst.end() && (long)*h>=(long)nums[i]-t && (long)*h<=(long)nums[i]+t) )
            {
                return true;
            }
            
            if(bst.size()>=k) bst.erase(nums[i-k]);
            
            bst.insert(nums[i]);
        }
        
        return false;
    }
};

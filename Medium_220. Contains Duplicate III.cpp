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
                
            multiset<int>::iterator l=bst.lower_bound(min);
            
            //for(auto i:bst) cout<<i<<" ";
            //cout<<i<<"--"<<(long)*l<<" "<<endl;
                
            if(l!=bst.end() && (long)*l>=(long)nums[i]-t && (long)*l<=(long)nums[i]+t)
            {
                return true;
            }
            
            if(bst.size()>=k) bst.erase(nums[i-k]);
            
            bst.insert(nums[i]);
        }
        
        return false;
    }
};

//bucket
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if(k==0 || nums.size() <= 1) return false;
        
        int n=nums.size();
        map<int,int> bucket;
        
        //cout<<-1/4<<" "<<-1%4<<endl;
        //cout<<-4/4<<" "<<-4%4<<endl;
        
        for(int i=0; i<n; ++i)
        {
            int index=nums[i] / ((long)t+1);
            if(nums[i] < 0) --index;
                        
            if(bucket.find(index)!=bucket.end() ||  
              (bucket.find(index+1)!=bucket.end() && (long)bucket.find(index+1)->second-nums[i] <= t) ||
              (bucket.find(index-1)!=bucket.end() && (long)nums[i]-bucket.find(index-1)->second <= t) )
            {
                return true;
            }
            
            if(bucket.size()>=k)
            {
                int erased_index=nums[i-k] / ((long)t+1);
                if(nums[i-k] < 0) --erased_index;
                
                bucket.erase(erased_index);
            }
            
            bucket.insert(pair<int,int>(index,nums[i]));
            
            //for(auto j:bucket) cout<<j.second<<" ";
            //cout<<"----"<<i<<endl;
        }
        
        return false;
    }
};

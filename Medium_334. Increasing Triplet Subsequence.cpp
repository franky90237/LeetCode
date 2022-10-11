//2022-04-28
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=2) return false;
        
        int small=INT_MAX;
        int big=INT_MAX;
        for(auto& num:nums)
        {
            if(num<=small) small=num;
            else if(num<=big) big=num;
            else return true;
        }
        
        return false;
    }
};

//2022-10-12
//time  : O(n*log(3))
//space : O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=2) return false;
        
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; ++i)
        {                        
            if(nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }            
            else
            {
                int idx=search(ans, nums[i]);            
                ans[idx]=nums[i];
            }
            
            //for(auto& x: ans) cout<<x<<" ";
            //cout<<endl;
            
            if(ans.size() == 3) return true;
        }
        
        return false;        
    }
    
    int search(vector<int>& ans, int num)
    {        
        int l=0;
        int r=ans.size()-1;
        
        while(l < r)
        {
            int mid=l+(r-l)/2;            
            if(ans[mid] == num) return mid;
            
            if(ans[mid] > num)
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
};

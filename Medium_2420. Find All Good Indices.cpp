//2022-09-25
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k)
    {
        int n=nums.size();
        
        vector<int> ans;                        
        for(int i=k; i<n-k; ++i)
        {
            if(k==1 || check_good(ans, nums, i, k))
            {                
                ans.push_back(i);               
            }
        }
        
        return ans;
    }
    
    bool check_good(vector<int>& ans, vector<int>& nums, int idx, int k)
    {
        int i=idx-k+1;
        if(!ans.empty()) 
        {
            int pre=ans.back();
            i=max(i, pre);
        }
        
        for(; i<idx; ++i)
        {
            if(nums[i-1] < nums[i]) return false;
        }
                
        i=idx+2;
        if(!ans.empty()) 
        {
            int pre=ans.back()+k+1;
            i=max(i, pre);
        }
        
        for(; i<=idx+k; ++i)
        {
            if(nums[i-1] > nums[i]) return false;
        }
        
        return true;
    }
};

//2022-09-25
//time  : O(n)
//space : O(n)
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k)
    {
        /*
           [2,1,1,1,3,4,1]
        d : 0,0,0,0,4,5,5
        i : 0,5,5,5,5,5,6

        */        
        int n=nums.size();
        
        int de[n];
        de[0]=0;
        for(int i=1; i<n; ++i)
        {
            if(nums[i-1] >= nums[i])
            {
                de[i]=de[i-1];
            }
            else
            {
                de[i]=i;
            }
        }
        
        int in[n];
        in[n-1]=n-1;
        for(int i=n-2; i>=0; --i)
        {
            if(nums[i+1] >= nums[i])
            {
                in[i]=in[i+1];
            }
            else
            {
                in[i]=i;
            }
        }
        
        vector<int> ans;                        
        for(int i=k; i<n-k; ++i)
        {
            if(check_good(nums, de, in, k, i))
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
    bool check_good(vector<int>& nums, int de[], int in[], int k, int i)
    {
        int start=de[i-1];
        if(start > i-k) return false;
        
        int end=in[i+1];
        if(end < i+k) return false;
        
        return true;
    }
};

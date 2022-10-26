//2022-10-26
//TLE
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        //int totalNums=accumulate(nums.begin(), nums.end(), 0);
        
        int n=nums.size();
        
        unordered_set<int> remainder[n];
        remainder[0].insert(nums[0]%k);
        
        for(int i=1; i<nums.size(); ++i)
        {            
            int r=nums[i]%k;
            //cout<<i<<" "<<r<<endl;
            if(remainder[i-1].find((k-r)%k) != remainder[i].end()) return true;
            
            remainder[i].insert(r);
            for(auto& it: remainder[i-1])
            {                
                remainder[i].insert((it+r)%k);
            }
        }
        
        return false;
    }
};

//2022-10-26
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {               
        int n=nums.size();
        if(n <= 1) return false;      
        
        unordered_map<int, int> remainder;
        remainder[nums[0]%k]=0;
        remainder[0]=-1; 
        
        int r=nums[0];        
        for(int i=1; i<nums.size(); ++i)
        {
            r=(r+nums[i])%k;
            if(remainder.find(r) != remainder.end() && i-remainder[r] >= 2) return true;
            
            if(remainder.find(r) != remainder.end())
            {
                remainder[r]=min(remainder[r], i);
            }
            else
            {
                remainder[r]=i;
            }
        }
        
        return false;
    }
};


/*

n[i]+n[i+1]+...n[k]
sum[i]=n[0]+n[1]+..n[i-1]

(n[i]+n[i+1]+...n[k])%k=0
n[i]+n[i+1]+...n[k]=sum[k+1]-sum[i]

(n[i]+n[i+1]+...n[k])%k = (sum[k+1]-sum[i])%k = 0

sum[k+1]%k = sum[i]%k

29%6=5
23%6=5
*/

//2022-04-25
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int res=3000;
        for(int i=0; i<n-2; ++i)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            //cout<<"****"<<i<<" "<<nums[i]<<endl;
            //cout<<res<<endl;
            
            int new_target=target-nums[i];
            int left=i+1;
            int right=n-1;
            int pre=nums[left]+nums[right];
            int sum=nums[left]+nums[right];
            while(left<right)
            {
                sum=nums[left]+nums[right];
                //cout<<left<<" "<<right<<endl;
                if(sum==new_target)
                {
                    return target;
                }
                else if(sum>new_target) 
                {
                    if(abs(res-target)>sum-new_target)
                    {
                        if(pre<new_target)
                        {
                            if(new_target-pre<sum-new_target) res=pre+nums[i];
                            else res=sum+nums[i];
                        }
                        else
                        {
                            res=sum+nums[i];
                        }
                    }
                    
                    pre=sum;
                    while(left<right && nums[right]==nums[right-1]) --right;
                    --right;
                }
                else 
                {
                    if(abs(res-target)>new_target-sum)
                    {
                        if(pre>new_target)
                        {
                            if(pre-new_target<new_target-sum) res=pre+nums[i];
                            else res=sum+nums[i];
                        }
                        else
                        {
                            res=sum+nums[i];
                        }
                    }
                    
                    pre=sum;
                    while(left<right && nums[left]==nums[left+1]) ++left;
                    ++left;
                }
            }
        }
        
        return res;        
    }
};

//2022-04-25
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0; i<n-2; ++i)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int left=i+1;
            int right=n-1;
            int sum;
            while(left<right)
            {
                sum=nums[i]+nums[left]+nums[right];
                
                if(sum==target)
                {
                    return target;
                }
                else if(sum>target) 
                {
                    while(left<right && nums[right]==nums[right-1]) --right;
                    --right;
                }
                else 
                {
                    while(left<right && nums[left]==nums[left+1]) ++left;
                    ++left;
                }
                
                if(abs(target-res)>abs(target-sum)) res=sum;
            }
        }
        
        return res;        
    }
};

//2022-09-09
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        
        int ans=nums[0]+nums[1]+nums[2];
        
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            if(i!=0 && nums[i-1]==nums[i]) continue;
                      
            int l=i+1;
            int r=n-1;            
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                
                if(sum==target) 
                {
                    return sum;
                }
                else if(sum>target)
                {
                    if(abs(sum-target)<abs(ans-target)) ans=sum;
                    --r;
                    while(l<r && nums[r]==nums[r+1]) --r;                    
                }
                else
                {
                    if(abs(sum-target)<abs(ans-target)) ans=sum;
                    ++l;
                    while(l<r && nums[l]==nums[l-1]) ++l;                   
                }                            
            }
        }
        
        return ans;
    }
};

//2022-10-09
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int ans=nums[0]+nums[1]+nums[2];
        int i=0;
        while(i <= n-3)
        {
            int l=i+1;
            int r=n-1;
            while(l < r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                
                if(sum==target)
                {
                    return sum;
                }                
                else if(abs(target-sum) < abs(target-ans))
                {
                    ans=sum;
                }
                
                if(sum > target)
                {
                    --r;
                    while(l < r && nums[r] == nums[r+1]) --r;                     
                }
                else
                {
                    ++l;
                    while(l < r && nums[l] == nums[l-1]) ++l;                     
                }                                             
            }        
            
            ++i;
            while(i <= n-3 && nums[i] == nums[i-1]) ++i;
        }
        
        return ans;
    }
};

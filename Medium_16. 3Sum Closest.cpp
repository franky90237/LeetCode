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

//2022-09-12
//TLE
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k)
    {
        /*
        dp[i]=max(1, 1+dp[k]), if(nums[i]-nums[k]<=3), 0<=k<=i-1
        
             [4,2,1,4,3,4,5,8,15]
        dp :  1 1 1 1 2 3 4 5 1 
        
             [1,19,2,3,4], k=18
        dp :  1  2 2 3 4
        
        */
        
        int n=nums.size();
        int dp[n];
        for(int i=0; i<n; ++i) dp[i]=1;
        
        multimap<int,int> bst;
        multimap<int,int> ;
        bst.insert({dp[0],nums[0]});
        
        int ans=dp[0];
        for(int i=1; i<n; ++i)
        {
            //cout<<nums[i]<<" : ";
                    
            bool find=false;
            for(auto it=bst.rbegin(); it!=bst.rend(); ++it)
            {
                int len=it->first;
                int val=it->second;
                                
                if(nums[i]>val && nums[i]-val<=k)
                {
                    dp[i]=len+1;
                    bst.insert({dp[i],nums[i]});
                    find=true;
                    break;
                }               
            }   
            
            if(!find)
            {
                bst.insert({dp[i],nums[i]});
            }
            
            ans=max(ans,dp[i]);        
        }
        
        //for(auto& i:bst) cout<<i.second<<" "<<i.first<<endl;
        
        /*for(int i=0; i<n; ++i) cout<<dp[i]<<" ";
        cout<<endl;*/
        
        return ans;
    }
};

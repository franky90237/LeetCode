//2023-03-23
//time  : O(nlog(n))
//space : O(n+k)
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        vector<map<int, int>> group(k);        
        
        for(auto num: nums)
        {
            ++group[num % k][num];            
        }
        
        //int ans=1;
        int pick=0;
        int not_pick=0;
        
        for(int i=0; i<k; ++i)
        {
            if(group[i].empty()) continue;                        
            
            auto head=group[i].begin();
            int preNum=(head->first)-k-1;
            
            
            for(auto& it: group[i])
            {
                int num=it.first;
                int cnt_of_num=it.second;                
                int cnt_of_subset=pow(2, cnt_of_num)-1;
                    
                if(num-preNum == k)
                {
                    int pre_not_pick=not_pick;
                    
                    not_pick += pick;
                    pick=(pre_not_pick+1)*cnt_of_subset;
                }
                else
                {
                    int pre_not_pick=not_pick;
                    
                    not_pick += pick;
                    pick=(pick+pre_not_pick+1)*cnt_of_subset;
                }
                
                preNum=num;
                //cout<<num<<" | "<<pick<<" "<<not_pick<<endl;
            }                        
        }
        
        return pick+not_pick;
    }
};

//2023-03-25
//time  : O(2^n)
//space : O(n)
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        vector<int> subset(1001, 0);
        return solve(nums, k, 0, subset)-1;
    }
    
    int solve(vector<int>& nums, int k, int cur, vector<int>& subset)
    {
        int n=nums.size();
        if(cur >= n)
        {
            return 1;
        }
        
        int pick=0;
        int not_pick=0;
            
        int big=nums[cur]+k;
        int small=nums[cur]-k;
        
        if((big >= subset.size() || subset[big] == 0) && (small < 0 || subset[small] == 0))
        {
            ++subset[nums[cur]];
            pick=solve(nums, k, cur+1, subset);
            --subset[nums[cur]];                        
        }
        
        not_pick=solve(nums, k, cur+1, subset);
        
        //cout<<cur<<" | "<<pick<<" "<<not_pick<<endl;
        return pick+not_pick;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        //bfs will be Time Limit Exceeded.
        //return bfs_findTargetSumWays(nums,target);
        
        //return dfs_findTargetSumWays(nums,target,0,0);
    }
    
    int bfs_findTargetSumWays(vector<int>& nums, int target)
    {
        int expressions=0;
        int step=1;
        queue<int> q;
        
        q.push(nums[0]);
        while(step<nums.size())
        {
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                int sum=q.front();
                q.pop();
                
                q.push(sum+nums[step]);
                q.push(sum-nums[step]);
            }
            
            ++step;
        }
        //print_queue(q);
        while(!q.empty())
        {
            int sum=q.front();
            q.pop();
            
            if(sum==target) ++expressions;
            if(sum-2*nums[0]==target) ++expressions;
        }
        
        return expressions;        
    }
    
    int dfs_findTargetSumWays(vector<int>& nums, int target, int sum, int step)
    {
        if(step==nums.size())
        {
            if(sum==target) return 1;
            return 0;
        }
                
        return dfs_findTargetSumWays(nums,target,sum+nums[step],step+1)+\
            dfs_findTargetSumWays(nums,target,sum-nums[step],step+1);
        
    }
    
    void print_queue(queue<int> q)
    {
        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
};

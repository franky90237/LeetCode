/*
2021/12/02
dfs (without memorization)
bfs (Time Limit Exceeded)
*/
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

/*
2021/12/03
dfs with memorization
*/
class Solution {
private:
    int **visited;    
    int nums_sum;
    
public:        
    int findTargetSumWays(vector<int>& nums, int target) 
    {        
        nums_sum=0;
        for(int i=0;i<nums.size();++i) nums_sum+=nums[i];
            
        int row_size=nums.size()+1;
        int col_size=2*nums_sum+1;
        
        visited=new int*[row_size];
        for(int i=0;i<row_size;++i)
        {
            visited[i]=new int[col_size];
            memset(visited[i],0,sizeof(int)*col_size);
        }
                
        return dfs_memorization(nums,target,0,0);
    }   
    
    int dfs_memorization(vector<int>& nums, int target, int sum, int step)
    {
        if(step==nums.size())
        {
            if(sum==target) return 1;
            return 0;
        }
        
        if(visited[step][sum+nums_sum])
        {
            //cout<<step<<" "<<sum+nums_sum<<endl;
            return visited[step][sum+nums_sum];
        }
               
        visited[step][sum+nums_sum]=\
            dfs_memorization(nums,target,sum+nums[step],step+1)+dfs_memorization(nums,target,sum-nums[step],step+1);
        return visited[step][sum+nums_sum];
    }    
};

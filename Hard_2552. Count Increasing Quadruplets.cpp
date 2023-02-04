//2023-02-03
//time  : O(n*n)
//space : O(n*n)
class Solution {
public:
    long long countQuadruplets(vector<int>& nums)
    {
        int n=nums.size();
                
        vector<vector<int>> less(n, vector<int>(n+1, 0));
        vector<vector<int>> greater(n, vector<int>(n+1, 0));              
        
        for(int j=1; j<n; ++j)
        {
            for(int val=0; val<=n; ++val)
            {
                less[j][val]=less[j-1][val];
            }
            
            for(int val=nums[j-1]+1; val<=n; ++val)
            {
                ++less[j][val];
            }
        }
        
        for(int k=n-2; k>=0; --k)
        {
            for(int val=0; val<=n; ++val)
            {
                greater[k][val]=greater[k+1][val];
            }
            
            for(int val=nums[k+1]-1; val>=0; --val)
            {
                ++greater[k][val];
            }                        
        }
        
        /*
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=n; ++j) cout<<less[i][j]<<" ";
            cout<<endl;
        }
        
        cout<<endl;
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=n; ++j) cout<<greater[i][j]<<" ";
            cout<<endl;
        }
        */
        
        long long ans=0;
        for(int j=0; j<n; ++j)
        {
            for(int k=j+1; k<n; ++k)
            {
                if(nums[j] <= nums[k]) continue;
                
                ans += less[j][nums[k]] * greater[k][nums[j]];
            }
        }
        
        return ans;
    }
};

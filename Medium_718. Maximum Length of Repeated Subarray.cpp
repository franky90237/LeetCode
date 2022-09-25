//2022-09-20
//TLE
//time  : O(m * n * min(m, n))
//space : O(n)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        
        unordered_map<int, vector<int>> table;
        for(int i=0; i<m; ++i)
        {
            table[nums2[i]].push_back(i);
        }
        
        int ans=0;
        for(int i=0; i<m; ++i)
        {
            for(auto& k : table[nums1[i]])
            {            
                int f=i;
                int s=k;
                while(f<m && s<n  && nums1[f]==nums2[s])
                {                    
                    ++f;
                    ++s;
                }
                
                ans=max(ans, f-i);
            }
        }
        
        return ans;
    }     
};

//2022-09-20
//time  : O(m*n)
//space : O(m*n)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        dp[i][j] = maximum length starting from nums1[i] and nums2[j] when nums[i]==nums[j]

        [1,2,3,2,1]
        [3,2,1,4,7]

           1 2 3 2 1
        3  0 0 3 0 0
        2  0 1 0 2 0
        1  1 0 0 0 1
        4  0 0 0 0 0 
        7  0 0 0 0 0
        */
        
        int m=nums1.size();
        int n=nums2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));        
        
        int ans=0;
        for(int i=m-1; i>=0; --i)
        {
            for(int k=n-1; k>=0; --k)
            {            
                if(nums1[i]==nums2[k])
                {
                    dp[i][k] = 1 + dp[i+1][k+1];
                    ans=max(ans, dp[i][k]);
                }                
            }
        }
        
        return ans;
    }     
};

//2022-09-21
//time  : O(m*n)
//space : O(1)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        /*    
        [0,1,2,3]
        [0,1]

        (0,0) (0,1)
        (1,0) (1,1)
        (2,0) (2,1)
        (3,0) (3,1)

        (0,0) (1,1) -> 2

        (0,1) ->1

        (1,0) (2,1) -> 2
        (2,0) (3,1) -> 2
        (3,0) ->1
        */
        
        int m=nums1.size();
        int n=nums2.size();
        
        int ans=0;
                        
        for(int diff=0; diff<n; ++diff)
        {
            int len=0;
            int p1=0;
            int p2=diff;
            while(p1<m && p2<n)
            {
                if(nums1[p1]==nums2[p2])
                {
                    ++len;
                    ans=max(ans, len);
                }
                else
                {
                    len=0;
                }
                
                ++p1;
                ++p2;
            }
        }
        
        for(int diff=1; diff<m; ++diff)
        {
            int len=0;
            int p1=diff;
            int p2=0;
            while(p1<m && p2<n)
            {
                if(nums1[p1]==nums2[p2])
                {
                    ++len;
                    ans=max(ans, len);
                }
                else
                {
                    len=0;
                }
                
                ++p1;
                ++p2;
            }
        }
        
        return ans;
    }
};    
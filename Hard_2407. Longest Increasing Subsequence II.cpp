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

//2022-09-12
//segment tree
//time  : O(nlog(n))
//space : O(max(n))
class segment_tree
{
private:
    int SIZE;
    vector<int> st;
    
public:
    segment_tree(int n)
    {
        SIZE=n;
        st.resize(2*n+2,0);
    }
    
    void modify(int idx, int len)
    {
        idx+=SIZE;
        
        st[idx]=len;
        while(idx>1)
        {
           // cout<<idx<<endl;
            idx/=2;
            st[idx]=max(st[2*idx],st[2*idx+1]);
        }
    }
    
    int query(int left, int right)
    {
        if(left>right) return 0;
        
        left+=SIZE;
        right+=SIZE;
        
        int ans=0;
        
        while(left<=right)
        {
            //cout<<left<<" "<<right<<endl;
            if(left%2==1) 
            {
                ans=max(ans,st[left]);
                ++left;
            }
            if(right%2==0)
            {
                ans=max(ans,st[right]);
                --right;
            }
            
            left=left/2;
            right=right/2;
        }
        
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k)
    {
        int MAX_NUM=1e5;         
        segment_tree st(MAX_NUM);
        
        int ans=0;
        int n=nums.size();        
        for(int i=0; i<n; ++i)
        {
            //cout<<nums[i]<<endl;
            int len=st.query(max(1,nums[i]-k),nums[i]-1);
            st.modify(nums[i],len+1);
            
            ans=max(ans,len+1);
        }
        
        return ans;
    }
};

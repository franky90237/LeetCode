//2022-10-24
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {        
        int n=nums.size();
        int ans=0;        
        for(int i=0; i<n; ++i)
        {
            int GCD=nums[i];            
            for(int j=i; j<n && nums[j]%k==0; ++j)
            {
                GCD=gcd(GCD, nums[j]);
                if(GCD == k) ++ans;                
            }            
        }
        
        return ans;
    }    
};

//2022-10-25
//time  : O(n*m), m is the preGCD count
//space : O(n*m)
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {        
        int n=nums.size();                
        int ans=0;
        
        unordered_map<int, int> preGCD[n];
        if(nums[0]%k == 0) 
        {
            ++preGCD[0][nums[0]];
            if(nums[0] == k) ++ans;
        }
                
        for(int i=1; i<n; ++i)
        {
            if(nums[i]%k != 0) continue;
                        
            ++preGCD[i][nums[i]];
            if(nums[i] == k) ++ans;
            
            for(auto& it: preGCD[i-1])
            {
                int curGCD=gcd(nums[i], it.first);
                if(curGCD%k == 0)
                {
                    preGCD[i][curGCD] += it.second;
                    if(curGCD == k) ans += it.second;
                }
            }
            //cout<<ans<<endl;
        }
        
        /*for(int i=0; i<n; ++i)
        {
            for(auto& it: preGCD[i])
            {
                cout<<"("<<it.first<<","<<it.second<<") ";
            }
            cout<<endl;
        }*/
        
        return ans;
    }
};

//2023-12-04
//time  : O(n*log(max(num)))
//space : O(log(max(num)))
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int n=nums.size();        
        unordered_map<int, int> table;

        int ans=0;        
        for(int right=0; right<n; ++right)
        {            
            //cout<<right<<" : ";

            int GCD=nums[right];
            if(GCD == k) ++ans;
            
            unordered_map<int, int> next;
            ++next[GCD];
            //cout<<GCD<<" ";
            
            for(auto [preGCD, cnt]: table)
            {            
                int nextGCD=gcd(GCD, preGCD);
                //cout<<"("<<nextGCD<<" "<<cnt<<") ";
                if(nextGCD == k) ans += cnt;
                next[nextGCD]+=cnt;
            }
            
            //cout<<endl;
            swap(table, next);
        }

        return ans;          
    }
};

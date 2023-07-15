//2023-07-14
//time  : O(n)
//spcae : O(n)
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> table(n+1, 0);
        int sum=0;
        for(int i=0; i<n; ++i)
        {
            sum += table[i];
            int rest=nums[i]+sum;
            //cout<<i<<" | "<<sum<<" "<<rest<<endl;
            if(rest < 0) return false;
            
            table[i] -= rest;
            if(i+k < n+1)table[i+k] += rest;
            sum = sum - rest;
        }              
        
        //for(int i=0; i<=n; ++i) cout<<table[i]<<" "; cout<<endl;            
        
        return table.back()+sum == 0;
    }
};

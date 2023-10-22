//2023-10-23
//time  : O(min frequency * number of groups)
//space : O(n)
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int, int> groups;
        for(int num :nums) ++groups[num];
        
        int minSize=INT_MAX;
        for(auto it: groups) minSize=min(minSize, it.second);
        
        
        for(; minSize>1; --minSize)
        {
            bool isAllGood=true;
            for(auto it: groups)
            {
                if(!canSplit(minSize, it.second))
                {
                    isAllGood=false;
                    break;
                }                            
            }
            
            if(isAllGood) break;
        }
        
        //cout<<minSize<<endl;
        
        int ans=0;
        for(auto it: groups)
        {
            ans += (it.second/(minSize+1)) + ((it.second%(minSize+1)) > 0);
        }
        
        return ans;
    }
    
    bool canSplit(int base, int size)
    {
        if(size-base == 0 || size-base == 1) return true;
        
        int cnt=size/base;
        int rest=size%base;
        //cout<<base<<" "<<size<<" | "<<cnt<<" "<<rest<<endl;
        if(rest <= cnt) return true;
        return false;
    }
};

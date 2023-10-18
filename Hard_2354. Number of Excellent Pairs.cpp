//2023-10-19
//time  : O(32*n)
//space : O(n)
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) 
    {

        /*
        (0,0) : 0&0,0|0 = (0,0)
        (0,1) : 0&1,0|1 = (0,1)
        (1,0) : 1&0,1|0 = (0,1)
        (1,1) : 1&1,1|1 = (1,1)

        1 : 0001
        2 : 0010
        3 : 0011
        1 : 0001
        */
        
        //unordered_map<int, int> table;
        vector<set<int>> bits(32);
        int maxSetBit=0;
        for(int num: nums)
        {
            //++table[num];
            int bitCnt=__builtin_popcount(num);
            bits[bitCnt].insert(num);        
        }
        
        vector<long long> prefixSum(33, 0);
        for(int i=1; i<=32; ++i)
        {
            prefixSum[i]=prefixSum[i-1]+(bits[i-1].size());
        }
        
        //for(int i=0; i<32; ++i) cout<<bits[i].size()<<" "; cout<<endl;
        //for(int i=0; i<=32; ++i) cout<<prefixSum[i]<<" "; cout<<endl;
        
        unordered_set<int> vis;
        long long ans=0;
        for(int num: nums)
        {
            if(vis.find(num) != vis.end()) continue;
            vis.insert(num);
            
            int bitCnt=__builtin_popcount(num);
            int diff=k-bitCnt;
            if(diff <= 0)
            {
                ans += prefixSum[32];
            }
            else if(diff <= 32)
            {
                ans += prefixSum[32]-prefixSum[diff];
            }
            
            //cout<<num<<" "<<ans<<endl;            
        }
        
        return ans;        
    }      
};

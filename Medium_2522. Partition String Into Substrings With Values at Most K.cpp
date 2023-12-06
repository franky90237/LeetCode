//2023-12-06
//time  : O(n)
//space : O(1)
class Solution {
public:
    int minimumPartition(string s, int k) 
    {        
        if(k < 9)
        {
            for(char c : s)
            {                
                if(c > (k+'0')) return -1;                
            }
        }
        
        int n=s.size();        
        long long curVal=0;
        int lastCutIdx=0;
        int ans=1;
        for(int right=0; right<n; ++right)
        {
            curVal = curVal*10+(s[right]-'0');
            cout<<right<<" "<<curVal<<endl;
            if(curVal > k)
            {
                curVal = s[right]-'0';
                lastCutIdx=right;
                ++ans;
                continue;
            }
        }

        return ans;
    }
};

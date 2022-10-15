//2022-10-15
//time  : O(2^(n-k))
//space : O(n)
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) 
    {
        int n=s.size();
        vector<int> valid(n, true);        
        
        return solve(s, k, valid, 0);
    }
    
    int solve(string& s, int k, vector<int>& valid, int cur)
    {
        int n=s.size();
        if(k == 0) return runLength(s, valid);
        if(n-cur < k) return INT_MAX;        
        
        int keep=solve(s, k, valid, cur+1);
        
        valid[cur]=false;
        int remove=solve(s, k-1, valid, cur+1);
        valid[cur]=true;
        
        //cout<<cur<<", "<<k<<" : "<<keep<<" | "<<remove<<endl;        
        return min(keep, remove);
    }
    
    int runLength(string& s, vector<int>& valid)
    {        
        int totalLen=0;
        int left=0;
        while(left < s.size())
        {
            if(!valid[left])
            {
                ++left;
                continue;
            }
            
            int len=0;
            int right=left;
            while(right < s.size() && (s[right] == s[left] || !valid[right]))
            {
                if(valid[right]) ++len;
                ++right;                
            }                             
            
            ++totalLen;
            if(len != 1)
            {
                totalLen += to_string(len).size();
            }
            
            left=right;
        }
        
        return totalLen;
    }
};

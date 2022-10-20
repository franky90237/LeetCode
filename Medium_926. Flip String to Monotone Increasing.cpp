//2022-10-20
//TLE
//time  : O(n*n)
//space : O(1)
class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int ans=INT_MAX;
        int n=s.size();
        for(int zeros=n; zeros>=0; --zeros)
        {
            int flips=calculate(s, zeros);
            if(flips == 0) return 0;
            //cout<<zeros<<" "<<flips<<endl;
            ans=min(ans, flips);
        }
        
        return ans;
    }
    
    int calculate(string& s, int zeros)
    {
        int flips=0;
        int i=0;
        while(i < zeros)
        {
            if(s[i] != '0') ++flips;
            ++i;
        }
        
        while(i< s.size())
        {
            if(s[i] != '1') ++flips;
            ++i;
        }
        
        return flips;
    }
};

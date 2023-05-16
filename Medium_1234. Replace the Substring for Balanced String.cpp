//2023-05-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    int balancedString(string s)
    {
        unordered_map<char, int> table;    
        int n=s.size();
        int maxCnt=n/4;
        int left=0;
        int right=n-1;
        
        while(left < n && table[s[left]]+1 <= maxCnt)
        {
            ++table[s[left]];
            ++left;
        }
        
        if(left == n) return 0;
        
        while(right > left && table[s[right]]+1 <= maxCnt)
        {
            ++table[s[right]];
            --right;
        }
        
        int ans=right-left+1;
        //cout<<"***"<<ans<<endl;
        while(left > 0)
        {
            --left;
            --table[s[left]];
                                    
            while(right > left && table[s[right]]+1 <= maxCnt)
            {        
                ++table[s[right]];
                --right;
            }
            
            ans=min(ans, right-left+1);
        }
        
        return ans;
    }
};

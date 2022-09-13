//2022-09-13
//time  : O(nlog(n))
//space : O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        /*
             [1,2,3,4], p=2
                  ^ * 
        p : 2 1 5 3 0
        s : 0 1 0 1 2
        a : 0 1 1 1 2
        
        */
        int n=tokens.size();
        if(n==0) return 0;
        
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0]) return 0;
        
        int l=0;
        int r=n-1;
        int score=0;
        int ans=0;
        
        while(l<=r)
        {
            while(l<=r && tokens[l]<=power)
            {
                power-=tokens[l];
                ++score;
                ++l;
            }
            
            ans=max(ans,score);
            
            if(score==0) break;
            
            if(l<=r && score>=1)
            {
                power+=tokens[r];
                --score;
                --r;
            }
        }
        
        return ans;
    }    
};

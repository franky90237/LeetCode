//2022-08-30
//time  : O(26*26*n)
//space : O(26)
class Solution {
public:
    int largestVariance(string s)
    {
        /*
          a b c d e
        a 1 1 1 1 1
        b 0 1 1 1 1
        F F F  
        A 0 0
        
          a a b a b b b
        a 0 0 0 1 1 1 1
        b 0 0 1 1 2 3 4
        F T T T T T T T
        A 0 0 1 1 1 2 3
        
          a b b a a b b b 
        a 1 1 0 1 2 2 2 0
        b 0 1 0 0 0 1 2 0
        f F F T T T T T T
        A 0 0 0 1 2 2 2 2
        */
        
        int frequency[26];
        for(auto& c:s) ++frequency[c-'a'];
        
        int ans=0;
        for(char c1='a'; c1<='z'; ++c1)
        {
            for(char c2='a'; c2<='z'; ++c2)
            {
                if(c1==c2 || frequency[c1-'a']==0 || frequency[c2-'a']==0) continue;
                
                int cnt1=0;
                int cnt2=0;
                bool left2=false;
                
                for(auto& c:s)
                {                    
                    if(c==c1) ++cnt1;                    
                    else if(c==c2) ++cnt2;                    
                                        
                    if((cnt2>0 && cnt1>cnt2)) 
                    {
                        ans=max(ans,cnt1-cnt2);
                        left2=false;
                    }
                    else if(left2 && cnt2==0)
                    {
                        ans=max(ans,cnt1-cnt2-1);
                    }
                    
                    if(cnt2>cnt1)
                    {
                        cnt1=0;
                        cnt2=0;
                        left2=true;
                    }
                    
                    //if(c1=='b' && c2=='a') cout<<c<<" : "<<cnt1<<","<<cnt2<<" "<<ans<<endl;
                }                                
            }
        }
        
        return ans;
    }
};

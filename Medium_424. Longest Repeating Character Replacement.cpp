//2022-07-03
//TLE
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int res=0;
        for(int i=0; i<s.size(); ++i)
        {            
            int len=solve(i,i,s[i],s,k);
            res=max(res,len);
            //cout<<i<<" : "<<res<<" "<<len<<endl<<endl;
        }
        
        return res;
    }
    
    int solve(int l, int r, char c,string& s, int k)
    {
        int n=s.size();
        while(r+1<n && s[r+1]==c) ++r;
        while(l-1>=0 && s[l-1]==c) --l;
        
        //cout<<l<<" "<<r<<" "<<k<<endl;
        if(k==0) return r-l+1;        
        
        int right;
        if(r==n-1) right=r-l+1;
        else right=solve(l,r+1,c,s,k-1);
        
        int left;
        if(l==0) left=r-l+1;
        else left=solve(l-1,r,c,s,k-1);        
        
        return max(left,right);
    }
};

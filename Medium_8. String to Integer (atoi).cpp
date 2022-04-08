class Solution {
public:
    int myAtoi(string s) 
    {
        int n=s.size();        
        
        int idx=0;
        while(idx<n && s[idx]==' ') ++idx;
        
        int sign=1;
        if(idx<n && (s[idx]=='+' || s[idx]=='-'))
        {
            if(s[idx]=='-') sign=-1;
            ++idx;
        }
        
        long res=0;
        for(int i=idx; i<n; ++i)
        {
            int c=s[i];
            
            if(c<'0' || c>'9') break;
            
            res=res*10+c-'0';
            if(sign==1 && res>=INT_MAX) return INT_MAX;
            else if(sign==-1 && -res<=INT_MIN) return INT_MIN;
        }
        
        return sign*res;
    }
};

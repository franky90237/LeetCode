class Solution {
public:
    int reverse(int x) 
    {
        if(x==0 || x==INT_MIN || x==INT_MAX) return 0;
        
        int sign = (x<0) ? -1 : 1;
        x=abs(x);
                
        while(x%10==0) x=x/10;
        //cout<<x<<endl;
        
        int res=0;
        while(x!=0)
        {
            int num=x%10;            
            //cout<<num<<endl;
            if(sign==1 && (double)res>(INT_MAX-num)/10.0) return 0;
            else if(sign==-1 && (double)res>(INT_MAX-num)/10.0 + 1/10.0) return 0;
            
            res=res*10+num;
            x=x/10;
        }        
        
        return sign*res;
    }
};

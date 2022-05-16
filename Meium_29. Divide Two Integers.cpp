//2022-05-16
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;        
        if(divisor==1 || divisor==-1) return dividend*divisor;        
        
        unsigned int dd=abs_my(dividend);
        unsigned int dv=abs_my(divisor);
        //cout<<dd<<" "<<dv<<endl;
        
        int res=0;
        while(dd>=dv)
        {
            unsigned int tmp=dv;
            int cnt=0;
            while(dd>(tmp<<1))
            {                
                tmp=tmp<<1;
                //cout<<tmp<<endl;
                if(tmp==0)
                {
                    tmp=dd;
                    break;
                }
                ++cnt;
            }
            
            dd-=tmp;
            //cout<<dd<<endl<<endl;
            res+=(1<<cnt);
        }
        
        return ((dividend<0) == (divisor<0)) ? res : -res;
    }
    
    unsigned int abs_my(int num)
    {        
        if(num==INT_MIN) return (unsigned)INT_MAX+1;
        return (num<0) ? -num : num;
    }
};

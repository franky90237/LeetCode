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

class Solution {
public:
    int reverse(int x) 
    {
        int res=0;
        //cout<<22/-10<<" "<<22%-10<<endl;
        
        while(x!=0)
        {
            int num=x%10;
            if( (x>0 && (res>INT_MAX/10 || (res>INT_MAX/10 && num>7))) ||
                (x<0 && (-res>INT_MAX/10 || (-res>INT_MAX/10 && num>8))) )
                return 0;
            
            res=res*10+num;
            x=x/10;
        }
        
        return res;
    }
};

//2023-03-25
//time  : O(32)
//space : O(1)
class Solution {
public:
    int reverse(int x) 
    {
        if(x == INT_MAX || x == INT_MIN)
        {
            return 0;
        }        
        
        if(x >= 0) return reservePositive(x);
        return reserveNegative(x);
    }
    
    int reservePositive(int num)
    {
        int ans=0;
        
        while(num != 0)
        {
            int right=num%10;
            
            if(ans > (INT_MAX-right)/10)
            {
                return 0;
            }
            
            ans = 10*ans + right;
            num /= 10;
        }
        
        return ans;
    }
    
    int reserveNegative(int num)
    {        
        int ans=0;
        
        while(num != 0)
        {
            int right=-((-num)%10);
            //cout<<num<<" "<<right<<endl;
            
            if(ans < (INT_MIN-right)/10)
            {
                return 0;
            }
            
            ans = 10*ans + right;
            if(ans > 0)
            {
                ans = -ans;
            }
            
            num /= 10;
        }
        
        return ans;
    } 
};

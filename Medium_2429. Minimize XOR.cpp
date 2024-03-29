//2022-10-04
//time  : O(32)
//space : O(1)
class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int cnt2=get_set_bits(num2);
        int cnt1=get_set_bits(num1);
                
        if(cnt1 == cnt2)
        {
            return num1;
        }
        else if(cnt1 > cnt2)
        {
            int ans=num1;
                       
            int diff=cnt1-cnt2;
            int i=1;
            while(diff > 0 && num1 > 0)
            {
                int lsb=num1%2;
                if(lsb == 1)
                {
                    --diff;
                    ans = ans & ~i;
                }
                
                i = i << 1;
                num1 = num1 >> 1;
            }        
            
            return ans;
        }
        else
        {
            int ans=num1;
                       
            int diff=cnt2-cnt1;
            int i=1;
            while(diff > 0 && num1 > 0)
            {
                int lsb=num1%2;
                if(lsb == 0) 
                {
                    --diff;
                    ans = ans | i;
                }
                
                i = i << 1;
                num1 = num1 >> 1;
            }
            
            while(diff > 0)
            {
                ans = ans | i;
                i = i << 1;
                --diff;
            }
            
            return ans;
        }
    }
    
    int get_set_bits(int num)
    {
        int cnt=0;
        while(num > 0)
        {
            num = num & (num-1);
            ++cnt;
        }
        
        return cnt;
    }
};

//2022-10-05
//time  : O(32)
//space : O(1)
class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        int cnt=get_set_bits(num2);
        
        int ans=0;
        
        unsigned int b=1<<31;
        for(int i=31; i>=0; --i)
        {
            if(cnt==0) break;
            
            if((b & num1) > 0)
            {                
                ans = ans | b;
                --cnt;
            }
            
            b = b >> 1;
        }
        
        //cout<<cnt<<" "<<ans<<endl;
        if(cnt == 0) return ans;
        
        b=1;
        for(int i=0; i<=31; ++i)
        {
            if(cnt==0) break;
            
            if((b & num1) == 0)
            {
                ans = ans | b;
                --cnt;
            }
            
            b = b << 1;
        }
        
        return ans;
    }
    
    int get_set_bits(int num)
    {
        int cnt=0;
        while(num > 0)
        {
            num = num & (num-1);
            ++cnt;            
        }
        
        return cnt;
    }
};

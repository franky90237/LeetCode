//2022-10-19
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool sumOfNumberAndReverse(int num) 
    {
        for(int i=0; i<=num; ++i)
        {
            int revI=reverse_int(i);
            if(i + revI == num) return true;
        }
        
        return false;
    }
    
    int reverse_int(int num)
    {
        int sum=0;
        while(num != 0)
        {
            sum = sum*10 + num%10;
            num /= 10;
        }
        
        return sum;
    }
};

//2022-10-19
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool sumOfNumberAndReverse(int num) 
    {
        int revI;
        int increment=1;
        for(int i=0; i<=num; ++i)
        {
            if(i%10 == 0)
            {
                revI=reverse_int(i);
                if(revI == 1) increment *= 10;                
            }
            else
            {
                revI = revI + increment;
            }
            
            //cout<<i<<" "<<revI<<endl;
            if(i + revI == num) return true;
        }
        
        return false;
    }
    
    int reverse_int(int num)
    {
        int sum=0;
        while(num != 0)
        {
            sum = sum*10 + num%10;
            num /= 10;
        }
        
        return sum;
    }
};

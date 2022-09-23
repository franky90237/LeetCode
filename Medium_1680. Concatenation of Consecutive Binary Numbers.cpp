//2022-09-23
//time  : O(n*l), l is the binary length of the number
//space : O(1)
class Solution {
public:
    int concatenatedBinary(int n) 
    {
    /*
    sum*2^len + num;

    1 01
    2 10
    3 11
    4 100
    5 101


    5%3 + 7%3 = 2 + 1
    12%3=0

    15%10 23%10 = 5 + 3
    38%10=8

    5*2 % 3 = 1
    1*2 % 3 = 2

    5*2*2 %3 = 2

    */        
        int modulo=1e9+7;
        long sum=0;
        for(int i=1; i<=n; ++i)
        {
            int len = get_binary_length(i);
            //cout<<i<<" "<<len<<endl;
            sum = (sum<<len) + i;
            sum = sum % modulo;
        }
        
        return sum;
    }
    
    int get_binary_length(int num)
    {
        int len=0;
        while(num!=0)
        {
            num = num>>1;
            ++len;
        }
        
        return len;
    }
};

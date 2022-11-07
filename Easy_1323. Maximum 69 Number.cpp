//2022-11-08
//time  : O(n)
//space : O(1)
class Solution {
public:
    int maximum69Number (int num)
    {
        int digit = (float)log(num)/(float)log(10);
        int power=pow(10,digit);        
        while(power > 0)
        {
            int left=(num/power)%10;
            if(left == 6) break;            
            power /= 10;
        }

        if(power > 0)
        {
            num=num+power*3;
        }
        return num;
    }   
};

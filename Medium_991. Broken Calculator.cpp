//2023-08-19
//time  : O(log(n))
//space : O(1)
class Solution {
public:
    int brokenCalc(int startValue, int target)
    {
        if(startValue >= target) return startValue-target;
        
        int cnt=0;
        while(startValue < target)
        {
            if(target % 2 == 0)
            {
                target /= 2;
            }
            else
            {
                ++target;
            }
            
            ++cnt;
        }
        
        return cnt+(startValue-target);
    }
};

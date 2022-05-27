//2022-05-27
//time  : O(32)
//space : O(1)
class Solution {
public:
    int numberOfSteps(int num) 
    {
        if(num<=2) return num;
        
        int res=0;
        while(num!=1)
        {
            if(num&1==1) res+=1;
            res+=1;
            num=num>>1;
        }
        
        return res+1;
    }
};

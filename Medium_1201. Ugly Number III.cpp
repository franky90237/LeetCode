//2022-04-19
//time  : O(k), k is the nthUglyNumber
//space : O(1)
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        vector<int> divisor({a,b,c});
        sort(divisor.begin(),divisor.end());
        
        int size=1;
        for(int i=1; i<3; ++i)
        {
            if(divisor[i]!=divisor[i-1]) 
            {
                divisor[size]=divisor[i];
                ++size;
            }
        }
        divisor.resize(size);
                        
        for(int i=size-1; i>0; --i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(divisor[i]%divisor[j]==0) 
                {
                    divisor.erase(divisor.begin()+i);
                    break;
                }
            }
        }
        
        //for(auto& i:divisor) cout<<i<<" ";
        
        int num=divisor[0];
        while(n!=0)
        {
            for(auto i:divisor)
            {
                if(num%i==0)
                {
                    --n;
                    break;
                }
            }
            
            ++num;
        }
        
        return num-1;
    }
};

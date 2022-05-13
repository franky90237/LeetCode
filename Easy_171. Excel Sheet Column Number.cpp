//2022-05-13
//time  : O(n)
//space : O(1)
class Solution {
public:
    int titleToNumber(string columnTitle) 
    {                
        int n=columnTitle.size();
        
        unsigned int res=0;
        unsigned int base=1;
        for(int i=n-1; i>=0; --i)
        {
            unsigned int number=(columnTitle[i]-'A')+1;
            //cout<<number<<endl;
            res+=number*base;                        
            base*=26;
        }
        
        return res;
    }
};

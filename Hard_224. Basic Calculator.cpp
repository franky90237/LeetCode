//2022-07-27
//pre sign
//time  : O(n)
//space : O(n)
class Solution {
public:
    int calculate(string s)
    {
        /*
        -1+(4+5-2)-3+(6+8)
                         ^
        sign   :  1
        result : 17
        stack  :
        
        4*5/6
         ^
        sign   :  1
        result :  4
        stack  :  *
        */
        
        int n=s.size();
        vector<int> stack;        
        int result=0;
        int sign=1;
        
        for(int i=0; i<n; ++i)
        {
            if(s[i]==' ') continue;
            
            if(isdigit(s[i]))
            {
                int sum=s[i]-'0';
                while(i+1<n && isdigit(s[i+1]))
                {
                    sum = sum*10 + (s[i+1]-'0');
                    ++i;
                }
                
                result += sign*sum;
            }
            else
            {
                if(s[i]=='+')
                {
                    sign=1;
                }
                else if(s[i]=='-')
                {
                    sign=-1;                    
                }
                else if(s[i]=='(')
                {
                    stack.push_back(result);
                    stack.push_back(sign);
                    result=0;
                    sign=1;
                }
                else
                {
                    result=result*stack.back();
                    stack.pop_back();
                    
                    result=stack.back()+result;
                    stack.pop_back();
                    
                    sign=1;
                }
            }                        
        }
        
        return result;
    }     
};

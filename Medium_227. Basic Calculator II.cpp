//2022-06-02
//time  : O(n)
//space : O(n)
class Solution {
public:
    int calculate(string s)
    {
        vector<int> integers;
        vector<int> operators;
        
        for(int i=0; i<s.size(); ++i)
        {
            char c=s[i];
            if(c==' ') continue;
            
            if(!isdigit(c))
            {
                operators.push_back(c);
            }
            else
            {
                int sum=0;
                int j=i;
                while(isdigit(s[j]))
                {
                    sum=sum*10+(s[j]-'0');
                    ++j;
                }
                
                if(!operators.empty() && (operators.back()=='*' || operators.back()=='/'))
                {
                    //cout<<sum<<" "<<integers.back()<<" ";
                    if(operators.back()=='*') sum=integers.back()*sum;
                    else sum=integers.back()/sum;
                    //cout<<sum<<endl;
                    
                    integers[integers.size()-1]=sum;
                    operators.pop_back();
                }
                else integers.push_back(sum);
                
                i=j-1;
            }
        }
        
        //for(auto& i:integers) cout<<i<<endl;
        
        int res=integers[0];
        int j=1;
        for(int i=0; i<operators.size(); ++i)
        {
            //cout<<res<<endl;
            if(operators[i]=='+') res=res+integers[j];
            else res=res-integers[j];
            
            ++j;
        }
        
        return res;
    }
};

//2022-06-02
//time  : O(n)
//space : O(1)
class Solution {
public:
    int calculate(string s)
    {
        s+="++";
        int res=0;
        int tmp=0;
        int integer=0;
        int prevOp='+';
        
        for(int i=0; i<s.size(); ++i)
        {
            char c=s[i];
            if(c==' ') continue;
            //printf("%c : %d %d %d\n",c,res,tmp,integer);
            
            if(isdigit(c))
            {
                integer=integer*10+(c-'0');
            }
            else
            {
                if(prevOp=='*') tmp=tmp*integer;
                else if(prevOp=='/') tmp=tmp/integer;
                else if(prevOp=='+')
                {
                    res=res+tmp;
                    tmp=integer;
                }
                else if(prevOp=='-')
                {
                    res=res+tmp;
                    tmp=-integer;
                }
                
                integer=0;
                prevOp=c;
            }
        }
        
        return res;
    }
};

//2022-07-27
//one stack
//time  : O(n)
//space : O(n)
class Solution {
public:
    int calculate(string s)
    {
        vector<int> stack;
        
        int i=0;
        while(i<s.size())
        {            
            if(s[i]==' ') 
            {
                ++i;
                continue;                
            }
                        
            if('0'<=s[i] && s[i]<='9')
            {
                int num=get_num(i,s);
                stack.push_back(num);                
            }
            else 
            {
                int symbol=s[i];
                
                ++i;
                while(s[i]==' ') ++i;
                
                int num=get_num(i,s);
                    
                if(symbol=='+')
                {
                    stack.push_back(num);                    
                }
                else if(symbol=='-')
                {
                    stack.push_back(-1*num);                
                }
                else 
                {
                    int pre_num=stack.back();
                    stack.pop_back();
                    
                    if(symbol=='*') stack.push_back(pre_num*num);
                    else if(symbol=='/') stack.push_back(pre_num/num);
                }                              
            }
        }
        
        return accumulate(stack.begin(),stack.end(),0);
    }
    
    int get_num(int& i, string& s)
    {
        int num=0;
        
        while('0'<=s[i] && s[i]<='9')
        {
            //cout<<num<<" "<<s[i]-'0'<<endl;
            num= num*10 + (s[i]-'0');
            ++i;
        }
        
        return num;
    }
};

//2022-07-27
//one stack, look from past
//time  : O(n)
//space : O(n)
class Solution {
public:
    int calculate(string s)
    {
        s+='+';
        vector<int> stack;
        char pre_sign='+';
        
        int num=0;
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i]==' ') continue;
            
            //cout<<i<<" "<<s[i]<<endl;
            if(isdigit(s[i])) num= num*10 + (s[i]-'0');
            else
            {
                if(pre_sign=='+') stack.push_back(num);
                else if(pre_sign=='-') stack.push_back(-num);
                else
                {
                    int pre_num=stack.back();
                    stack.pop_back();
                    
                    if(pre_sign=='*') stack.push_back(pre_num*num);
                    else if(pre_sign=='/') stack.push_back(pre_num/num);
                }
                    
                pre_sign=s[i];
                num=0;
            }
        }                               
        
        return accumulate(stack.begin(),stack.end(),0);
    }    
};

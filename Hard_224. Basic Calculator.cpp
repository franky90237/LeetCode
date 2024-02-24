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

//2024-02-24
class Solution {
public:
    int calculate(string s) 
    {        
        int n = s.size();
        vector<string> st;
        for(int i=0; i<n; ++i)
        {
            if(s[i] == ' ') continue;
            
            if(s[i] == ')')
            {
                string val=st.back();
                st.pop_back();
                st.pop_back();
                st.emplace_back(val);
                
                doOneOperation(st);
            }
            else if(isdigit(s[i]))
            {
                string num;
                while(i < n && isdigit(s[i]))
                {                
                    num.push_back(s[i]);
                    ++i;
                }
                --i;
                
                st.emplace_back(num);
                doOneOperation(st);
            }            
            else
            {
                st.push_back({s[i]});
            }                        
        }
                
        return stoi(st.back());
    }
    
    void doOneOperation(vector<string>& st)
    {
        //for(string& s : st) cout<<s<<" "; cout<<endl;
        
        if(st.size() <= 1) return;
        if(st[st.size()-2] == "(") return;
        if(st[st.size()-2] == "-" && (st.size() == 2 || st[st.size()-3].back() == '('))
        {        
            int val=stoi(st.back());
            st.pop_back();
            st.pop_back();
            st.emplace_back(to_string(-val));
            return;
        }
                
        int second = stoi(st.back()); 
        st.pop_back();
        
        string op = st.back();
        st.pop_back();
        
        int first = 0;
        if(!st.empty() && isdigit(st.back().back()))
        {                      
            first = stoi(st.back());
            st.pop_back();
        }
        //cout<<first<<" "<<second<<endl;
        
        if(op == "+")
        {
            st.emplace_back(to_string(first + second));
        }
        else if(op == "-")
        {
            st.emplace_back(to_string(first - second));
        }
    }
};

//2024-02-24
//time  : O(n)
//space : O(n)
class Solution {
public:
    int calculate(string s) 
    {
        return calculate(s, 0)[0];
    }
    
    vector<int> calculate(string& s, int i)
    {
        int n=s.size();
        
        char op = '+';
        int num = 0;
        stack<int> st;
        
        for(; i<n; ++i)
        {
            if(s[i] == ' ') continue;            
            else if(isdigit(s[i]))
            {
                num = 10*num + (s[i]-'0');
            }
            else if(s[i] == '(')
            {
                vector<int> res = calculate(s, i+1);
                update(st, op, res[0]);
                i = res[1];
            }
            else if(s[i] == ')')
            {
                break;
            }
            else
            {
                update(st, op, num);
                op = s[i];
                num = 0;
            }
        }
        
        update(st, op, num);
        return {getSum(st), i};        
    }
    
    int getSum(stack<int>& st)
    {
        int res = 0;
        while(!st.empty()) 
        {
            res += st.top();
            st.pop();
        }
        
        return res;        
    }
    
    void update(stack<int>& st, char op, int num)
    {
        switch(op)
        {
            case '+':
                st.push(num);
                break;
            
            case '-':
                st.push(-num);
                break;                      
            
            default:
                break;
        }
    }
};

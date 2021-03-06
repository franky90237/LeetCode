class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size()%2==1) return false;
        
        stack<char> left_parentheses;    
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                left_parentheses.push(s[i]);
            }
            else
            {
                if(left_parentheses.empty()) return false;
                
                switch(s[i])
                {
                    case ')':
                        if(left_parentheses.top()!='(') return false;
                        break;
                    case ']':
                        if(left_parentheses.top()!='[') return false;
                        break;
                    case '}':
                        if(left_parentheses.top()!='{') return false;
                        break;
                }
                left_parentheses.pop();
            }
        }
        
        if(!left_parentheses.empty()) return false;
        return true;                
    }
    
    //push close parentheses rather than open parentheses
    bool isValid(string s) 
    {
        if(s.size()%2==1) return false;
        
        stack<char> parentheses;    
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(') parentheses.push(')');
            else if(s[i]=='[') parentheses.push(']');
            else if(s[i]=='{') parentheses.push('}');
            else
            {
                if(parentheses.empty() || s[i]!=parentheses.top()) return false;
                parentheses.pop();
            }
           
        }
                
        return parentheses.size()==0;                
    }  
};

//2022-07-18
//stack, good for many push operations
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool isValid(string s)
    {
        vector<char> stack;
        for(auto& c:s)
        {
            if(c=='(' || c=='[' || c=='{')
            {
                stack.push_back(c);
            }
            else
            {
                if(stack.empty()) return false;
                
                char left=stack.back();                
                switch(left)
                {
                    case '(':
                        if(c!=')') return false;
                        break;
                    case '[':
                        if(c!=']') return false;
                        break;
                    case '{':
                        if(c!='}') return false;
                        break;                    
                }
                
                stack.pop_back();
            }
        }
        
        return stack.empty();
    }
};

//2022-07-18
//stack, good for many pop operations
//time  : O(n)
//space : O(n)
class Solution {
public:
    bool isValid(string s)
    {
        vector<char> stack;
        for(auto& c:s)
        {
            if(c=='(') stack.push_back(')');
            else if(c=='[') stack.push_back(']');
            else if(c=='{') stack.push_back('}');
            else
            {
                if(stack.empty() || stack.back()!=c) return false;
                
                stack.pop_back();
            }
        }
        
        return stack.empty();
    }
};

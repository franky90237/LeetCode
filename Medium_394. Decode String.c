//two stack
class Solution {
public:
    string decodeString(string s) 
    {
        stack<int> number;
        stack<string> letter;      
        
        for(int i=0;i<s.size();++i)
        {       
            if('0'<=s[i] && s[i]<='9')
            {
                //process number
                int num=0;                
                while('0'<=s[i] && s[i]<='9')
                {
                    num=num*10+s[i]-'0';
                    ++i;
                }
                number.push(num);
                
                //push "["
                letter.push("[");                                  
            }
            else if('a'<=s[i] && s[i]<='z')
            {                
                //process letter
                string l;
                while('a'<=s[i] && s[i]<='z')
                {
                    l.push_back(s[i]);
                    ++i;
                }
                letter.push(l);
                --i;                                 
            }
            else
            {
                //cout<<number.top()<<" "<<letter.top()<<endl;
                
                string l;
                while(!letter.empty() && letter.top()!="[")
                {
                    l=letter.top()+l;
                    letter.pop();
                }                
                letter.pop();
                //letter.push(l);
                
                //combine number and letter
                string multiple_l;
                for(int i=0;i<number.top();++i)
                {
                    multiple_l+=l;
                }
                number.pop();
                letter.push(multiple_l);                                                              
            }            
        }
        
        //cout<<letter.size()<<" "<<number.size()<<endl;    
        
        string result;
        while(!letter.empty())
        {
            result=letter.top()+result;
            letter.pop();
        }
        
        return result;
    }
};

//recursive similar to dfs
class Solution {
public:
    string decodeString(string s) 
    {
        int begin=0;
        return handler(s,begin);
    }
    
    string handler(string& s, int& begin)
    {
        //cout<<begin<<endl;
        string result;
        int number=0;
        
        while(begin<s.size())
        {
            if(s[begin]==']') break;
            else if('a'<=s[begin] && s[begin]<='z')
            {
                result+=s[begin];
                ++begin;
            }
            else if('0'<=s[begin] && s[begin]<='9') 
            {
                number=number*10+s[begin]-'0';
                ++begin;
            }
            else // if(s[begin]=='[')
            {
                ++begin;
                string sub_result=handler(s,begin);
                
                for(int i=0;i<number;++i)
                {
                    result+=sub_result;
                }
                
                number=0;
                ++begin;                
            }
        }
        
        return result;        
    }
};

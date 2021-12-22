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

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> digits;        
        
        for(int i=0;i<tokens.size();++i)
        {            
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
            {
                digits.push(stoi(tokens[i]));
            }
            else
            {
                int operand2=digits.top(); digits.pop();
                int operand1=digits.top(); digits.pop();
                
                switch(tokens[i][0])
                {
                    case '+':                        
                        digits.push(operand1+operand2);
                        break;
                    case '-':
                        digits.push(operand1-operand2);
                        break;
                    case '*':
                        digits.push(operand1*operand2);
                        break;
                    case '/':
                        digits.push(int(operand1/operand2));
                        break;               
                }
            }    
        }
        
        return digits.top();
    }
};

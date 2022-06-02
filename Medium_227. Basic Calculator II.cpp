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

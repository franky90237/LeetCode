//2022-04-13
//time  : O(n)
//space : O(1)
class Solution {
public:
    bool areNumbersAscending(string s) 
    {
        int n=s.size();
        
        int num=-1;                
        for(int i=0; i<n; ++i)
        {
            char c=s[i];
            if(c==' ' || isalpha(c)) continue;
            
            int new_num=0;
            while(isdigit(s[i]))
            {
                new_num=new_num*10+s[i]-'0';                
                ++i;
            }
            
            if(num>=new_num) return false;
            num=new_num;
            
            --i;
        }
        
        return true;
    }
};

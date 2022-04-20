//2022-04-20
//time  : O(n)
//space : O(1)
class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> roman;
        config(roman);
        
        int n=s.size();
        int sum=0;
        for(int i=0; i<n; ++i)
        {
            if(i+1<n && roman[s[i+1]]>roman[s[i]])
            {
                sum+=roman[s[i+1]]-roman[s[i]];
                ++i;
            }
            else
            {
                sum+=roman[s[i]];
            }            
        }
        
        return sum;
    }
    
    void config(unordered_map<char,int>& roman)
    {
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
    }
};

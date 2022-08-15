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

//2022-08-15
//time  : O(n)
//space : O(1)
class Solution {
public:
    int romanToInt(string s)
    {
        /*
        29 = XXIX
        10
        20
        19
        29
        
        429 = CDXXIV
        -100
        400
        410
        420
        419
        429
        */
        
        unordered_map<char,int> table;
        table['I']=1;
        table['V']=5;
        table['X']=10;
        table['L']=50;
        table['C']=100;
        table['D']=500;
        table['M']=1000;
                
        int ans=0;
        
        for(int i=0; i<s.size(); ++i)
        {
            if(i+1<s.size() && table[s[i]]<table[s[i+1]]) ans-=table[s[i]];
            else ans+=table[s[i]];
        }
        
        return ans;
    }
};

//2022-04-15
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> answer;
        
        for(int i=1; i<=n; ++i)
        {
            if(i%3==0 && i%5==0) answer.push_back("FizzBuzz");
            else if(i%3==0) answer.push_back("Fizz");
            else if(i%5==0) answer.push_back("Buzz");
            else answer.push_back(to_string(i));
        }
        
        return answer;
    }
};

//2022-04-15
//less if condition
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> answer;
        
        for(int i=1; i<=n; ++i)
        {
            string s="";
            
            if(i%3==0) s="Fizz";
            if(i%5==0) s+="Buzz";
            if(s=="") s+=to_string(i);
            
            answer.push_back(s);
        }
        
        return answer;
    }
};

//2022-04-16
//using mapping
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        map<int,string> m;
        m[3]="Fizz";
        m[5]="Buzz";
        
        vector<string> answer;
        for(int i=1; i<=n; ++i)
        {
            string s="";
            
            for(auto& it:m)
            {
                if(i%it.first==0) s+=it.second;
            }
            
            if(s=="") s=to_string(i);
            
            answer.push_back(s);
        }
        
        return answer;
    }
};

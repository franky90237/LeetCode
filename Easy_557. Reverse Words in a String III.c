class Solution {
public:
    string reverseWords(string s) 
    {        
        int word_start=0;
        for(int word_end=0;word_end<s.size();++word_end)
        {
            if(s[word_end]!=' ')
            {
                word_start=word_end;
                while(word_end<s.size() && s[word_end]!=' ')
                {
                    ++word_end;
                }
                reverse(s.begin()+word_start,s.begin()+word_end);                                
            }
        }
        
        return s;
    }
};

//2022-08-02
//time  : O(n)
//space : O(1)
class Solution {
public:
    string reverseWords(string s)
    {
        int start=0;
        int len=0;
        
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i]!=' ') ++len;
            else
            {
                //cout<<start<<" "<<len<<endl;
                reverse(s.begin()+start,s.begin()+start+len);
                start=i+1;
                len=0;
            }
        }
        
        reverse(s.begin()+start,s.begin()+start+len);
        return s;
    }    
};

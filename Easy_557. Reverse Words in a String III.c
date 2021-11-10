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

//2022-10-11
//time  : O(n)
//space : O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) 
    {
        int len=palindrome.size();
        if(len == 1) return "";
        
        int half=(len)/2;
        bool change=false;
        for(int i=0; i<half; ++i)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                change=true;
                break;
            }
        }
        
        if(!change)
        {
            if(palindrome[len-1] == 'a') ++palindrome[len-1];
            else --palindrome[len-1];                       
        }
        
        return palindrome;
    }
};
